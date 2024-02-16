/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 10:56:17 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/17 00:21:17 by lquehec          ###   ########.fr       */
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
	printf("Executor\n");
	if (mini->pipeline)
		ft_lstclear_pipeline(&mini->pipeline);
	if (!create_pipeline(mini))
		return (0); // TODO handle error
	if (mini->tokens)
		ft_lstclear_token(&mini->tokens);
	print_pipeline(mini);
	handle_heredoc(mini);
	printf("exec_only_heredoc: %d\n", mini->exec_only_heredoc);
	if (mini->exec_only_heredoc <= -1)
	{
		printf("Pipex\n");
		pipex(mini);
	}
	// while (cur_pipeline)
	// {
	// 	while ((waitpid(cur_pipeline->pid, &status, 0)) > 0)
	// 		if (WIFEXITED(status))
	// 			mini->exec_status = WEXITSTATUS(status);
	// 	cur_pipeline = cur_pipeline->next;
	// }
	// if (mini->exec_only_heredoc == -1)
	// {
	// 	if (ft_lstsize_pipeline(mini->pipeline) == 1)
	// 		exec_single_pipeline(mini);
	// 	else
	// 		exec_multi_pipeline(mini);
	// }
	return (1);
}
