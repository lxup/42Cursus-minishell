/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_multi_pipeline.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 22:48:44 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/16 11:06:32 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_multi_pipeline(t_mini *mini)
{
	t_pipeline	*cur_pipeline;
	int			pipe[2];
	int			fd_in;

	(void)mini;
	(void)cur_pipeline;
	(void)pipe;
	(void)fd_in;
	printf("MULTI PIPELINE\n");
	printf("std_in: %d\n", mini->std_in);
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