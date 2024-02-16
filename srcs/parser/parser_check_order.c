/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_check_order.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 06:46:56 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/16 06:50:32 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	parser_checker_order_if(t_token *token)
{
	if (token == token->next || token == token->prev)
		return (0);
	if (token->type == TOKEN_PIPE && (!token->prev || !token->next \
		|| !ft_lstprev_cmd_token(token) || !ft_lstnext_cmd_token(token)))
		return (0);
	if (token->type == TOKEN_ARGS && (!token->prev || (token->prev \
		&& token->prev->type != TOKEN_CMD && token->prev->type != TOKEN_ARGS \
		&& token->prev->type != TOKEN_FILE)))
		return (0);
	if (token->type == TOKEN_FILE && (!token->prev || (token->prev \
		&& (token->prev->type != TOKEN_LESSER \
		&& token->prev->type != TOKEN_GREATER \
		&& token->prev->type != TOKEN_DLESSER \
		&& token->prev->type != TOKEN_DGREATER))))
		return (0);
	if ((token->next == NULL \
		|| (token->next && token->next->type != TOKEN_FILE)) \
		&& (token->type == TOKEN_LESSER || token->type == TOKEN_GREATER \
		|| token->type == TOKEN_DLESSER || token->type == TOKEN_DGREATER))
		return (0);
	return (1);
}

int	parser_check_order(t_mini *mini)
{
	t_token		*tmp_token;

	tmp_token = mini->tokens;
	while (tmp_token)
	{
		if (!parser_checker_order_if(tmp_token))
			return (mini->exec_status = EXEC_SYNTAX_ERROR, 0);
		tmp_token = tmp_token->next;
	}
	return (1);
}
