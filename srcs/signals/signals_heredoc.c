/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals_heredoc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 11:28:00 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/22 23:26:53 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// pid_t	g_status;

void	signals_heredoc_parents(int sig)
{
	if (sig == SIGINT)
		printf("\n");
}

void	signals_heredoc(int sig)
{
	(void)sig;
	if (sig == SIGINT)
	{
		g_status = EXEC_CTRL_C;
		close(STDIN_FILENO);
		return ;
	}
}
