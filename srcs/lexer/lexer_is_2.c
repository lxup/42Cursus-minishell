/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_is_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 22:38:23 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/14 18:12:09 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_word(char *prompt, int *i)
{
	char	quote;
	int		inside_quote;
	int		cursor;

	cursor = *i - 1;
	quote = 0;
	inside_quote = 0;
	while (++cursor >= 0 && prompt[cursor] && ft_isprint(prompt[cursor]) \
		&& !ft_iswhitespace(prompt[cursor]) \
		&& (inside_quote || (prompt[cursor] != '>' && prompt[cursor] != '<')))
	{
		if ((prompt[cursor] == '\'' || prompt[cursor] == '\"'))
		{
			if (inside_quote && quote == prompt[cursor])
				inside_quote = 0;
			else if (!inside_quote )
			{
				quote = prompt[cursor];
				inside_quote = 1;
			}
		}
	}
	if (cursor == *i)
		return (0);
	return (*i = cursor, 1);
}
