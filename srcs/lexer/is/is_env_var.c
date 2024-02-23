/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_env_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 17:44:43 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/23 12:30:15 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_valid_env_var(char *prompt)
{
	int		cursor;

	cursor = 0;
	if (prompt[cursor] != '$')
		return (0);
	cursor++;
	if (prompt[cursor] == '?')
		return (1);
	while (cursor >= 0 && (ft_isalnum(prompt[cursor]) || prompt[cursor] == '_'))
		cursor++;
	if (cursor == 1)
		return (0);
	return (1);
}

int	is_env_var(char *prompt, int *i)
{
	int		cursor;

	if (!i)
		return (is_valid_env_var(prompt));
	cursor = *i;
	if (prompt[cursor] != '$')
		return (0);
	cursor++;
	if (prompt[cursor] == '?')
		return (*i = cursor + 1, 1);
	while (cursor >= 0 && (ft_isalnum(prompt[cursor]) || prompt[cursor] == '_'))
		cursor++;
	if (cursor == *i + 1)
		return (0);
	return (*i = cursor, 1);
}
