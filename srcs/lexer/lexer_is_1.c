/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_is_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 17:23:38 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/13 22:38:22 by lquehec          ###   ########.fr       */
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
