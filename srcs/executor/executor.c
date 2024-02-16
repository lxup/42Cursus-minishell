/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 10:56:17 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/16 05:56:43 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// void	ft_exec(t_mini *mini, t_pipeline *pipeline)
// {
// 	char	*cmd_path;
	
// 	cmd_path = get_cmd_path(mini, ft_lstfind_cmd_pipeline(pipeline));
// 	// if (cmd_path)
// 	// 	execve(cmd_path, args, data->envp);
// 	// ft_dprintf("%s: command not found\n", cmd_path);
// 	// free(cmd_path);
// }
// infile ls ls ls ls outfile
// void	redirections(t_data *data, int i)
// {
// 	if (i != 0)
// 	{
// 		dup2(data->prev, STDIN_FILENO);
// 		close(data->prev);
// 	}
// 	if (i != data->nbcmd - 1)
// 		dup2(data->pipefd[1], STDOUT_FILENO);
// 	close(data->pipefd[1]);
// 	close(data->pipefd[0]);
// }


int	create_pipeline(t_mini *mini)
{
	t_token		*cur_token;
	t_pipeline	*cur_pipeline;

	cur_token = mini->tokens;
	ft_lstadd_back_pipeline(&mini->pipeline, ft_lstnew_pipeline());
	cur_pipeline = mini->pipeline;
	while (cur_token)
	{
		if (cur_token->type == TOKEN_PIPE)
		{
			ft_lstadd_back_pipeline(&mini->pipeline, ft_lstnew_pipeline());
			cur_pipeline = cur_pipeline->next;
			cur_token = cur_token->next;
		}
		ft_lstadd_back_token(&cur_pipeline->tokens, ft_lstnew_token(ft_strdup(cur_token->value), cur_token->type));
		cur_token = cur_token->next;
	}

	return (1);
}


// void	*ft_child_proc(t_mini *mini, t_pipeline *pipeline)
// {
// 	t_pipexcmd	*cmd;

// 	cmd = cmd_head->content;
// 	close(fd[0]);
// 	if (cmd_head->next && dup2(fd[1], STDOUT_FILENO) == -1)
// 		return (ft_exit(NULL, DUP_ERR, info, NULL));
// 	if (!cmd_head->next && dup2(info->fd_out, STDOUT_FILENO) == -1)
// 		return (ft_exit(NULL, DUP_ERR, info, NULL));
// 	close(fd[1]);
// 	close(info->fd_in);
// 	close(info->fd_out);
// 	if (execve(cmd->path, cmd->cmd, envp) == -1)
// 		return (ft_exit(*cmd->cmd, EXEC_ERR, info, NULL));
// 	return (NULL);
// }
	
int	executor(t_mini *mini)
{
	t_pipeline	*cur_pipeline;
	
	(void)mini, (void)cur_pipeline;
	printf("Executor\n");
	if (mini->pipeline)
		ft_lstclear_pipeline(&mini->pipeline);
	if (!create_pipeline(mini))
		return (0); // TODO handle error
	if (mini->tokens)
		ft_lstclear_token(&mini->tokens);
	print_pipeline(mini);
	// TODO: Check file ?
	// TODO: Check if command is built-in
	cur_pipeline = mini->pipeline;
	handle_heredoc(mini);
	// if (ft_lstsize_pipeline(mini->pipeline) == 1)
	// 	exec_single_pipeline(mini);
	// else
	// exec_multi_pipeline(mini);
	// while (cur_pipeline)
	// {
	// 	// printf("pipeline cmd: %s\n", ft_lstfind_type_pipeline(cur_pipeline, TOKEN_CMD));
	// 	if (mini->exec_status != EXEC_SUCCESS)
	// 		break ;
	// 	if (pipe(cur_pipeline->pipe) == -1)
	// 	{
	// 		mini->exec_status = EXEC_PIPE_ERROR;
	// 		continue ;
	// 	}
	// 	cur_pipeline->pid = fork();
	// 	if (cur_pipeline->pid == 0)
	// 	{
	// 		free(cur_pipeline->pid);
	// 		redirections(cur_pipeline);
	// 		if ((i == 0 || i == data->nbcmd - 1))
	// 			open_files(i, data);
	// 		ft_exec(data->cmd[i], data);
	// 		exit(127);
	// 	}
	// 	else
	// 	{
	// 		// if (i)
	// 		// 	close(cur_pipeline->prev->pipe);
	// 		// cur_pipeline->prev-> = data->pipefd[0];
	// 		// close(data->pipefd[1]);
	// 	}
	// 	cur_pipeline = cur_pipeline->next;
	// }
	
	return (0);
}
