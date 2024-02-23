/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals_heredoc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 11:28:00 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/23 14:05:36 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	signals_heredoc_parents(int sig)
{
	if (sig == SIGINT)
		ft_printf("\n");
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
