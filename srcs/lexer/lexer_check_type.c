/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_check_type.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 17:23:38 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/13 21:22:14 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_greater(char *prompt)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (prompt && prompt[i] == '>')
	{
		count++;
		i++;
	}
	if (count == 1)
		return (1);
	return (0);
}

int	is_dgreater(char *prompt)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (prompt && prompt[i] == '>')
	{
		count++;
		i++;
	}
	if (count == 2)
		return (1);
	return (0);
}

int	is_lesser(char *prompt)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (prompt && prompt[i] == '<')
	{
		count++;
		i++;
	}
	if (count == 1)
		return (1);
	return (0);
}

int	is_dlesser(char *prompt)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (prompt && prompt[i] == '<')
	{
		count++;
		i++;
	}
	if (count == 2)
		return (1);
	return (0);
}

int	is_word(char *prompt, int *i)
{
	int	cursor; 
	int	quote_count;
	
	cursor = *i;
	if (!prompt || !prompt[cursor])
		return (0);
	if (prompt[cursor] == '\"')
	{
		cursor++;
		quote_count = 1;
		while (prompt[cursor] == '\"')
		{
			cursor++;
			quote_count++;
		}
		while (prompt[cursor] && prompt[cursor] != '\"')
			cursor++;
		while (prompt[cursor] == '\"')
		{
			quote_count--;
			cursor++;
			if (quote_count == 0)
				return (*i = cursor, 1);
		}
		return (0);
	}
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
