/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 19:35:42 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/17 00:51:21 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

pid_t	g_pid;

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
	// char	*line;

	if (isatty(fileno(stdin)))
		mini->prompt = readline(mini->shell_prompt.prompt);
	// else
	// {
	// 	printf("test\n");
	// 	line = get_next_line(fileno(stdin));
	// 	if (!line)
	// 		return (NULL);
	// 	mini->prompt = ft_strtrim(line, "\n");
	// 	free(line);
	// }
	if (mini->prompt == NULL) // ctrl + D
	{
		printf("salam\n");
		mini->exit_code = EXIT_CTRL_D;
		return (NULL);
	}
	return ((void *)1);
}

int	reset_mini(t_mini *mini)
{
	if (mini->pipeline)
		ft_lstclear_pipeline(&mini->pipeline);
	if (mini->tokens)
		ft_lstclear_token(&mini->tokens);
	mini->last_exec_status = mini->exec_status;
	mini->exec_status = EXEC_SUCCESS;
	mini->exec_only_heredoc = -1;
	return (1);
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
		if (lexer(mini) && parser(mini))
			executor(mini);
		add_to_history(mini);
		env_update(mini);
		reset_mini(mini);
	}
}