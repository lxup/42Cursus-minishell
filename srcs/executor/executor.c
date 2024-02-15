/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 10:56:17 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/15 13:06:44 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
	print_pipeline(mini);
	// TODO: Check file ?
	// TODO: Check if command is built-in
	handle_heredoc(mini);
	// while (cur_pipeline)
	// {
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
	// 		mini->exec_status = EXEC_FORK_ERROR;
	// 		continue ;
	// 	}
	// 	else
	// 	{
			
	// 	}
	// 	cur_pipeline = cur_pipeline->next;
	// }
	
	return (0);
}
