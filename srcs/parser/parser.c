/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 10:44:39 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/19 22:28:13 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	fix_empty_token(t_mini *mini)
{
	t_token	*token;

	token = mini->tokens;
	while (token)
	{
		if (token->type == TOKEN_QUOTE || token->type == TOKEN_DQUOTE)
			token->type = TOKEN_WORD;
		token = token->next;
	}
	return (1);
}

int	parser(t_mini *mini)
{
	if (!parser_fix_quote(mini))
		return (0);
	if (!fix_empty_token(mini))
		return (0);
	if (!adjust_token_type(mini->tokens))
		return (0);
	if (!parser_check_token_type(mini))
		return (0);
	if (!parser_check_order(mini))
		return (0);
	return (1);
}
