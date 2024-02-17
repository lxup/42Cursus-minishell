/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 15:58:46 by emehdaou          #+#    #+#             */
/*   Updated: 2024/02/17 15:03:45 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void init_redir(t_pipeline *pipeline)
{
    t_token *tmp;

    tmp = pipeline->tokens;
    while (tmp)
    {
        if (tmp->type == TOKEN_LESSER || tmp->type == TOKEN_DLESSER)
        {
            if (tmp->type == TOKEN_DLESSER)
                pipeline->infile = pipeline->heredoc;
            else
                pipeline->infile = tmp->next->value;
        }
        if (tmp->type == TOKEN_GREATER)
        {
            pipeline->outfile = tmp->next->value;
            pipeline->redir_append = 0;
        }
        if (tmp->type == TOKEN_DGREATER)
        {
            pipeline->outfile = tmp->next->value;
            pipeline->redir_append = 1;
        }
        tmp = tmp->next;
    }
}


void	redirections(t_pipeline *pipeline, t_mini *mini)
{
    // i != 0
	if (pipeline->prev)// && pipeline->redir_in == 0)
    {
        dup2(mini->prevpipe, STDIN_FILENO);
        close(mini->prevpipe);
    }
    // i != data->nbcmd - 1
	if (pipeline->next)// && pipeline->redir_out == 0)
		dup2(mini->pipefd[1], STDOUT_FILENO);
	close(mini->pipefd[1]);
	close(mini->pipefd[0]);
}

void	*open_files(t_pipeline *pipeline)
{
	int	fd_in;
    int fd_out;
    
    fd_in = 0;
    fd_out = 0;
    if (pipeline->infile)
    {
        fd_in = open(pipeline->infile, O_RDONLY);
        if (fd_in < 0)
            return (perror(pipeline->infile), exit(1), NULL);
        dup2(fd_in, STDIN_FILENO);
        close(fd_in);
    }
    if (pipeline->outfile)
    {
        if (pipeline->redir_append)
            fd_out = open(pipeline->outfile, O_RDWR | O_CREAT | O_APPEND, 0644);
        else
            fd_out = open(pipeline->outfile, O_RDWR | O_CREAT | O_TRUNC, 0644);
        if (fd_out < 0)
            return (perror(pipeline->outfile), exit(1), NULL);
        dup2(fd_out, STDOUT_FILENO);
        close(fd_out);
    }
    return (NULL);
}
// si i != 0
// alors data->cmd[1 - 1 | data->nbcmd]
// donc la condition est a 0
// alors perror(data->cmd[data->nbcmd])
// sinon
// alors perror(data->cmd[i - 1])

// void	open_files(t_pipeline *pipeline)
// {
// 	int	fd;
    
//     ft_dprintf("open_files\n"); 
// 	if (pipeline->infile)
// 		fd = open(pipeline->infile, O_RDONLY);
// 	if (pipeline->outfile)
//     {
//         ft_dprintf("file_name: %s\n", pipeline->outfile);
// 		fd = open(pipeline->outfile, O_RDWR | O_CREAT | (O_TRUNC + pipeline->redir_append * 512), 0644);
//     }
// 	if (fd < 0)
// 	{
//         if (pipeline->infile)
// 		    perror(pipeline->infile);
//         else
//             perror(pipeline->outfile);
// 		exit(1);
// 	}
// 	dup2(fd, STDIN_FILENO);
// 	close(fd);
// }

void	ft_exec(t_pipeline *pipeline, t_mini *mini)
{
    char *cmd;
    
	cmd = get_path_pipex(mini, pipeline->args[0]);
	if (cmd)
		execve(cmd, pipeline->args, env_to_str(mini->env));
	ft_dprintf("%s: command not found\n", cmd);
	free(cmd);
	// ft_free_array((void **)pipeline->args);
}

void	ft_process(t_pipeline *pipeline, t_mini *mini)
{
    t_pipeline *curr;
    curr = pipeline;
	while (curr)
	{
		pipe(mini->pipefd);
		curr->pid = fork();
		if (curr->pid == 0)
		{
            init_redir(curr);
			redirections(curr, mini);
			if (curr->outfile || curr->infile)
				open_files(curr);
			ft_exec(curr, mini);
			exit(127);
		}
		else
		{
			if (curr->prev)
            {
                ft_printf("prev: %s\n", curr->prev->args[0]);
				close(mini->prevpipe);
            }
			mini->prevpipe = mini->pipefd[0];
			close(mini->pipefd[1]);
		}
        curr = curr->next;
    }
	ft_waitpid(pipeline);
}

int	pipex(t_mini *mini)
{
	ft_process(mini->pipeline, mini);
    close(mini->pipefd[0]);
    return(1);
}