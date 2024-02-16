/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_multi_pipeline.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 22:48:44 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/16 14:31:13 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_multi_pipeline(t_mini *mini)
{
	t_pipeline	*cur_pipeline;
	int			fd[2];
	int			fd_in;

	(void)mini;
	(void)cur_pipeline;
	(void)pipe;
	(void)fd_in;
	(void)fd;
	fd_in = mini->std_in;
	cur_pipeline = mini->pipeline;
	while (cur_pipeline)
	{
		
		// print_2d_array(cur_pipeline->args);
		// printf("pid: %d\n", cur_pipeline->pid);
		// if (cur_pipeline->next)
		// 	pipe(fd);
		cur_pipeline = cur_pipeline->next;
	}
// 	cur_pipeline = mini->pipeline;
// 	while (cur_pipeline)
// 	{
// 		if (pipe(cur_pipeline->pipe) == -1)
// 		{
// 			mini->exec_status = EXEC_PIPE_ERROR; // TODO  manage error
// 			continue ;
// 		}
// 		cur_pipeline->pid = fork();
// 		if (cur_pipeline->pid == -1)
// 		{
// 			mini->exec_status = EXEC_FORK_ERROR; // TODO  manage error
// 			continue ;
// 		}
// 		if (cur_pipeline->pid == 0)
// 			return (exec_child(mini, cur_pipeline));
// 		waitpid(cur_pipeline->pid, &mini->exec_status, 0);
// 		cur_pipeline = cur_pipeline->next;
// 	}
}