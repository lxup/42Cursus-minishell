/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_is_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 22:38:23 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/14 11:49:45 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_word_quote(char *prompt, int *i, char c)
{
	int	cursor;
	int	quote_count;

	cursor = *i;
	if (!prompt || !prompt[cursor])
		return (0);
	cursor++;
	quote_count = 1;
	while (prompt[cursor] == '\"' || prompt[cursor] == '\'')
	{
		if (prompt[cursor] == c)
			quote_count++;
		cursor++;
	}
	while (prompt[cursor] && prompt[cursor] != '\"' && prompt[cursor] != '\'')
		cursor++;
	while (prompt[cursor] == '\"' || prompt[cursor] == '\'')
	{
		if (prompt[cursor] == c)
			quote_count--;
		cursor++;
		if (quote_count == 0)
			return (*i = cursor, 1);
	}
	return (*i = cursor, 1);
}

int	is_word(char *prompt, int *i)
{
	int	cursor;

	cursor = *i;
	if (!prompt || !prompt[cursor])
		return (0);
	if (prompt[cursor] == '\"')
		return (is_word_quote(prompt, i, '\"'));
	else if (prompt[cursor] == '\'')
		return (is_word_quote(prompt, i, '\''));
	else
	{
		while (prompt[cursor] && ft_isprint(prompt[cursor]) \
			&& !ft_iswhitespace(prompt[cursor]) \
			&& prompt[cursor] != '>' && prompt[cursor] != '<')
			cursor++;
		if (cursor == *i)
			return (0);
		return (*i = cursor, 1);
	}
}
