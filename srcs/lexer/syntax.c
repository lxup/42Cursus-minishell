/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 14:40:29 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/15 18:47:48 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_chars(char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str && str[i])
	{
		if (str[i] == '\'')
			while (str[i] && str[i] != '\'')
				i++;
		if (str[i] == '\"')
			while (str[i] && str[i] != '\"')
				i++;
		if (str[i] == c)
			count++;
		i++;
	}
	return (count);
}

int	is_valid_open_bracket(char *str, int i)
{
	if (!str)
		return (0);
	while (--i > 0 && str[i] && ft_iswhitespace(str[i]))
		;
	if (i >= 0 && (str[i] != '&' && str[i] != '|' && str[i] != '('))
		return (0);
	return (1);
}

int	is_bracket_open(char *str, int i)
{
	int	count;

	count = 1;
	while (str && --i >= 0)
	{
		if (str[i] == ')')
			count++;
		if (str[i] == '(')
			count--;
		if (count == 0)
			return (1);
	}
	return (0);
}

int	is_valid_pipe(char *str, int i)
{
	int	count;

	if (!str)
		return (0);
	if ((i == 0 && str[0] == '|') || str[ft_strlen(str) - 1] == '|')
		return (0);
	count = i - 1;
	while (--i > 0 && str[i] && str[i] != '|')
		;
	if (count == i)
		return (0);
	return (1);
}

int	is_valid_syntax(char *str)
{
	int	i;

	i = -1;
	if ((count_chars(str, '(') != count_chars(str, ')'))
		|| str[0] == '|' || str[ft_strlen(str) - 1] == '|')
		return (0);
		// || count_chars(str, ';') > 0 || count_chars(str, '\\') > 0)
	while (str && str[++i])
	{
		if (str[i] == '\'')
			while (str[i] && str[i] != '\'')
				i++;
		if (str[i] == '\"')
			while (str[i] && str[i] != '\"')
				i++;
		if (str[i] == '(')
			if (!is_valid_open_bracket(str, i))
				return (0);
		if (str[i] == ')')
			if (!is_bracket_open(str, i))
				return (0);
		// if (str[i] == '|')
		// 	if (!is_valid_pipe(str, i))
		// 		return (0);
	}
	return (1);
}
