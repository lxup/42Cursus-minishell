/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_token_type.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 11:02:35 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/14 17:15:01 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	define_token_type(char *prompt, t_token_type *type, int *i)
{
	if (is_greater(prompt + *i))
		return (*type = TOKEN_GREATER, *i += 1, 1);
	else if (is_dgreater(prompt + *i))
		return (*type = TOKEN_DGREATER, *i += 2, 1);
	else if (is_lesser(prompt + *i))
		return (*type = TOKEN_LESSER, *i += 1, 1);
	else if (is_dlesser(prompt + *i))
		return (*type = TOKEN_DLESSER, *i += 2, 1);
	else if (is_word(prompt, i))
		return (*type = TOKEN_WORD, 1);
	return (0);
}

void	adjust_token_type(t_token *tokens)
{
	t_token	*tmp;

	tmp = tokens;
	while (tmp)
	{
		if (tmp->type == TOKEN_WORD)
		{
			if (tmp->prev && (tmp->prev->type == TOKEN_GREATER \
				|| tmp->prev->type == TOKEN_DGREATER \
				|| tmp->prev->type == TOKEN_LESSER \
				|| tmp->prev->type == TOKEN_DLESSER))
				tmp->type = TOKEN_FILE;
			else if (tmp == tokens || tmp->prev->type == TOKEN_FILE)
				tmp->type = TOKEN_CMD;
			else if (tmp->prev && (tmp->prev->type == TOKEN_CMD \
				|| tmp->prev->type == TOKEN_ARGS))
				tmp->type = TOKEN_ARGS;
		}
		tmp = tmp->next;
	}
}
