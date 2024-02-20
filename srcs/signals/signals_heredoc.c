/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals_heredoc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 11:28:00 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/20 23:18:29 by lquehec          ###   ########.fr       */
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
		g_status = 130;
		// printf("g_status = %d\n", g_status);
		// write(STDIN_FILENO, "\0", 1);
		close(STDIN_FILENO);
		return ;
	}
}
