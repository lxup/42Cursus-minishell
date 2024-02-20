/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals_heredoc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 11:28:00 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/20 20:29:36 by lquehec          ###   ########.fr       */
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
	// ft_nsm(130);
	g_status = 130;
	close(STDIN_FILENO);
	return ;
	// exit(1);
}
