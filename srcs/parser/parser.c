/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 10:44:39 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/14 20:55:00 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	parser_checker_token_type(t_mini *mini)
{
	t_pipeline	*tmp_pipeline;
	t_token		*tmp_token;

	tmp_pipeline = mini->pipeline;
	while (tmp_pipeline)
	{
		tmp_token = tmp_pipeline->tokens;
		while (tmp_token)
		{
			if (tmp_token->type == TOKEN_NOT_SET \
				|| tmp_token->type == TOKEN_UNKNOWN)
				return (mini->exec_status = EXEC_SYNTAX_ERROR, 0);
			tmp_token = tmp_token->next;
		}
		tmp_pipeline = tmp_pipeline->next;
	}
	return (1);
}

int	parser_checker_order_if(t_token *token)
{
	if (token == token->next || token == token->prev)
		return (0);
	if (token->type == TOKEN_ARGS && (!token->prev || (token->prev \
		&& token->prev->type != TOKEN_CMD && token->prev->type != TOKEN_ARGS)))
		return (0);
	if (token->type == TOKEN_FILE && (!token->prev || (token->prev \
		&& (token->prev->type != TOKEN_LESSER \
		&& token->prev->type != TOKEN_GREATER \
		&& token->prev->type != TOKEN_DLESSER \
		&& token->prev->type != TOKEN_DGREATER))))
		return (0);
	if ((token->next == NULL || (token->next && token->next->type != TOKEN_FILE)) \
		&& (token->type == TOKEN_LESSER || token->type == TOKEN_GREATER \
		|| token->type == TOKEN_DLESSER || token->type == TOKEN_DGREATER))
		return (0);
	return (1);
}

int	parser_checker_order(t_mini *mini)
{
	t_pipeline	*tmp_pipeline;
	t_token		*tmp_token;

	tmp_pipeline = mini->pipeline;
	while (tmp_pipeline)
	{
		tmp_token = tmp_pipeline->tokens;
		while (tmp_token)
		{
			if (!parser_checker_order_if(tmp_token))
				return (mini->exec_status = EXEC_SYNTAX_ERROR, 0);
			tmp_token = tmp_token->next;
		}
		tmp_pipeline = tmp_pipeline->next;
	}
	return (1);
}

int	parser(t_mini *mini)
{
	if (!parser_checker_token_type(mini))
		return (0);
	if (!parser_checker_order(mini))
		return (0);
	if (!expander_env_var(mini))
		return (0);
	// if (!parser_quote_fix(mini))
	// 	return (0);
	return (1);
}
