/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 19:35:42 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/20 13:04:39 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	reset_mini(t_mini *mini)
{
	if (mini->env_array)
	{
		ft_free_array((void **)mini->env_array);
		mini->env_array = NULL;
	}
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

int	is_empty(char *str)
{
	while (str && *str)
	{
		if (!ft_iswhitespace(*str))
			return (0);
		str++;
	}
	return (1);
}

void	minishell(t_mini *mini)
{
	while (1)
	{
		signals(mini);
		get_shell_prompt(mini);
		mini->prompt = readline(mini->shell_prompt.prompt);
		if (!mini->prompt)
		{
			ft_printf("salam\n");
			break ;
		}
		if (!*mini->prompt || is_empty(mini->prompt))
			continue ;
		add_to_history(mini);
		if (lexer(mini) && parser(mini))
			executor(mini);
		env_update(mini);
		reset_mini(mini);
	}
}
