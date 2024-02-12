/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 19:35:42 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/12 19:43:33 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

// void	init_term(struct termios *term_mini)
// {
// 	struct termios	term;

// 	tcgetattr(1, &term_mini);
// 	tcgetattr(1, &term);
// 	term.c_lflag &= ~(ICANON | ECHO);
// 	tcsetattr(1, TCSANOW, &term);
// }

void	sig_init(t_mini *mini)
{
	(void)mini;
	g_pid = 0;
	// init_term(&mini->term);
	// signal(SIGINT, sig_handler);
	// signal(SIGQUIT, sig_handler);
	sig_ctrl_c();
	sig_ctrl_backslash();
}

int	*start_reading(t_mini *mini)
{
	(void)mini;
	char	*line;

	// mini->exec_on_pipe = 0;
	// mini->should_execute = 0;
	if (isatty(fileno(stdin)))
		mini->prompt = readline(mini->shell_prompt.prompt);
	else
	{
		line = get_next_line(fileno(stdin));
		if (!line)
			return (NULL);
		mini->prompt = ft_strtrim(line, "\n");
		free(line);
	}
	// shell->trimmed_prompt = ft_strtrim(shell->prompt, SPACES);
	if (mini->prompt == NULL)
	{
		mini->exit_code = EXIT_CTRL_D;
		return (NULL);
	}
	return ((void *)1);
}

void	print_exec_msg(t_mini *mini)
{
	if (mini->exec_status != EXEC_SUCCESS)
	{
		if (mini->exec_status == EXEC_SYNTAX_ERROR)
			printf("Syntax error\n");
	}
}

void	minishell(t_mini *mini)
{
	(void)mini;

	while (1)
	{
		sig_init(mini);
		get_shell_prompt(mini);
		if (!start_reading(mini))
			break ;
		// printf("cmd = %s\n", mini->prompt);
		if (lexer(mini) && parser(mini))
			executor(mini);
		add_to_history(mini);
		print_exec_msg(mini);
		if (mini->exec_status == EXEC_SUCCESS)
			mini->last_exec_status = EXEC_SUCCESS;
		else
			mini->last_exec_status = mini->exec_status;
	}
}