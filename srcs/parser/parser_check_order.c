/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_check_order.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 06:46:56 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/16 11:26:07 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	parser_checker_order_if_2(t_mini *mini, t_token *token)
{
	if (ft_lstprev_tokentype_token(token, TOKEN_DLESSER) \
		&& mini->exec_only_heredoc == -1 \
		&& (token->type == TOKEN_LESSER || token->type == TOKEN_GREATER \
		|| token->type == TOKEN_DLESSER || token->type == TOKEN_DGREATER)
		&& (!token->next || (token->next && token->next->type != TOKEN_FILE)))
	{
		mini->exec_only_heredoc = ft_lstcountprev_tokentype_token(token, \
			TOKEN_DLESSER);
		p_err_syntax(mini, '\n');
	}
	return (1);
}

static int	parser_checker_order_if(t_mini *mini, t_token *token)
{
	if (token == token->next || token == token->prev)
		return (p_err_syntax(mini, token->value[0]), 0);
	if (token->type == TOKEN_PIPE && (!token->prev || !token->next))
		return (p_err_syntax(mini, token->value[0]), 0);
	if (token->type == TOKEN_ARGS && (!token->prev || (token->prev \
		&& token->prev->type != TOKEN_CMD && token->prev->type != TOKEN_ARGS \
		&& token->prev->type != TOKEN_FILE)))
		return (p_err_syntax(mini, token->value[0]), 0);
	if (token->type == TOKEN_FILE && (!token->prev || (token->prev \
		&& (token->prev->type != TOKEN_LESSER \
		&& token->prev->type != TOKEN_GREATER \
		&& token->prev->type != TOKEN_DLESSER \
		&& token->prev->type != TOKEN_DGREATER))))
		return (p_err_syntax(mini, token->value[0]), 0);
	if (!ft_lstprev_tokentype_token(token, TOKEN_DLESSER) \
		&& (token->type == TOKEN_LESSER || token->type == TOKEN_GREATER \
		|| token->type == TOKEN_DLESSER || token->type == TOKEN_DGREATER) \
		&& (!token->next || (token->next && token->next->type != TOKEN_FILE)))
		{
			if (!token->next)
				return (p_err_syntax(mini, '\n'), 0);
			else if (token->next->type != TOKEN_FILE)
				return (p_err_syntax(mini, token->value[0]), 0);
		}
	return (parser_checker_order_if_2(mini, token));
}

int	parser_check_order(t_mini *mini)
{
	t_token		*tmp_token;

	tmp_token = mini->tokens;
	while (tmp_token)
	{
		if (!parser_checker_order_if(mini, tmp_token))
			return (0);
		tmp_token = tmp_token->next;
	}
	return (1);
}
