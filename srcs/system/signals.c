/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 12:18:31 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/18 01:20:46 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

pid_t	g_pid;

void	sig_handler(int sig)
{
	if (sig == SIGINT)
	{
		g_pid = 1;
		write(1, "\n", 2);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
	else if (sig == SIGQUIT)
	{
		rl_on_new_line();
		rl_redisplay();
		ft_putstr_nl(MSG_EXIT);
	}	
}

void	sig_ctrl_c(void)
{
	struct sigaction	ctrl_c;

	ctrl_c.sa_handler = sig_handler;
	ctrl_c.sa_flags = SA_RESTART;
	sigemptyset(&ctrl_c.sa_mask);
	sigaction(SIGINT, &ctrl_c, NULL);
}

void	sig_ctrl_backslash(void)
{
	struct sigaction	ctrl_backslash;

	ctrl_backslash.sa_handler = SIG_IGN;
	ctrl_backslash.sa_flags = SA_RESTART;
	sigemptyset(&ctrl_backslash.sa_mask);
	sigaction(SIGQUIT, &ctrl_backslash, NULL);
}

void	terms(t_mini *mini)
{
	struct termios	term;

	tcgetattr(1, &mini->term);
	tcgetattr(1, &term);
	term.c_lflag &= ~ECHOCTL;
	tcsetattr(1, TCSAFLUSH, &term);
}

void	sig_init(t_mini *mini)
{
	(void)mini;
	g_pid = 0;
	terms(mini);
	sig_ctrl_c();
	sig_ctrl_backslash();
}

