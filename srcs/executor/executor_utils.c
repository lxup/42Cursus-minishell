/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:14:51 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/20 16:16:55 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	clear_heredoc_after_exec(t_mini *mini)
{
	t_pipeline	*pipeline;
	
	(void)mini;
	pipeline = mini->pipeline;
	while (pipeline)
	{
		if (pipeline->heredoc)
		{
			if (access(pipeline->heredoc, F_OK) == 0)
				unlink(pipeline->heredoc);
		}
		pipeline = pipeline->next;
	}
	return (1);
}
