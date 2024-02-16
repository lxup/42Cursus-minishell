/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_word_in_quote.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 17:58:24 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/16 21:26:24 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_word_in_quote(char *prompt, int *i, char quote)
{
	int		cursor;

	cursor = *i;
	while (cursor >= 0 && prompt[cursor] && !is_env_var(prompt + cursor, NULL) \
		&& ((quote && prompt[cursor] != quote) \
		|| (prompt[cursor] != '>' && prompt[cursor] != '<' \
		&& prompt[cursor] != '|' && !ft_iswhitespace(prompt[cursor]) \
		&& prompt[cursor] != '\'' && prompt[cursor] != '\"')))
	{
		cursor++;
	}
	if (cursor == *i)
		return (0);
	return (*i = cursor, 1);
}
