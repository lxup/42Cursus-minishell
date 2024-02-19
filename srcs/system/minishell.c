/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 19:35:42 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/19 12:47:33 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// void	init_term(struct termios *term_mini)
// {
// 	struct termios	term;

// 	tcgetattr(1, &term_mini);
// 	tcgetattr(1, &term);
// 	term.c_lflag &= ~(ICANON | ECHO);
// 	tcsetattr(1, TCSANOW, &term);
// }

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
	if (mini->prev_prompt)
		free(mini->prev_prompt);
	mini->prev_prompt = mini->prompt;
	mini->prompt = NULL;
	return (1);
}

void	minishell(t_mini *mini)
{
	(void)mini;

	while (1)
	{
		signals(mini);
		get_shell_prompt(mini);
		if (!start_reading(mini))
			break ;
		add_to_history(mini);
		if (lexer(mini) && parser(mini))
			executor(mini);
		env_update(mini);
		reset_mini(mini);
	}
}