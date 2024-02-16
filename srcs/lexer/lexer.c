/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 10:28:00 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/16 23:22:48 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*token_clear_quote(char *prompt, int end, int start)
{
	char	*token;
	int		start_word;
	int		end_word;
	char	quote;

	start_word = start;
	end_word = end;
	if (prompt[start_word] == '\'' || prompt[start_word] == '\"')
		quote = prompt[start_word];
	while (start_word < end_word \
		&& (prompt[start_word] == quote && prompt[end_word - 1] == quote))
	{
		start_word++;
		end_word--;
	}
	token = ft_strndup(prompt + start_word, end_word - start_word, 0);
	if (!token)
		return (NULL);
	return (token);
}

int	lexer(t_mini *mini)
{
	if (ft_strwhitespace(mini->prompt) || !ft_strcmp(mini->prompt, ":"))
		return (0);
	if (!is_valid_syntax(mini, mini->prompt))
		return (0);
	ft_lstclear_token(&mini->tokens);
	if (!create_tokens(mini))
		return (0);
	if (!expander_env_var(mini))
		return (0);
	return (1);
}
