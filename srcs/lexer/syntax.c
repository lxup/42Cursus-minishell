/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 14:40:29 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/12 23:28:26 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_chars(char *str, char c)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (str && str[++i])
	{
		if (str[i] == '\'')
			while (str[++i] && str[i] != '\'');
		if (str[i] == '\"')
			while (str[++i] && str[i] != '\"');
		if (str[i] == c)
			count++;
	}
	return (count);
}

int	ft_isspace(int c)
{
	return (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r');
}

int	is_valid_open_bracket(char *str, int i)
{
	if (!str)
		return (0);
	while (str[--i] && i > 0 && ft_isspace(str[i]));
	if (i >= 0 && (str[i] != '&' && str[i] != '|'))
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

// int	is_bracket_close(char *str, int i)
// {
// 	int	count;

// 	count = 1;
// 	while (str && str[++i])
// 	{
// 		if (str[i] == '(')
// 			count++;
// 		if (str[i] == ')')
// 			count--;
// 		if (count == 0)
// 			return (1);
// 	}
// 	return (0);
// }

int	is_valid_syntax(char *str)
{
	int	i;

	i = -1;
	if (count_chars(str, '(') != count_chars(str, ')'))
		return (0);
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
			// if (!is_bracket_close(str, i))
			// 	return (0);
		if (str[i] == ')')
			if (!is_bracket_open(str, i))
				return (0);
		if (str[i] == ';' || str[i] == '\\')
			return (0);
	}
	return (1);
}