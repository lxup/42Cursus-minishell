/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_check_token_type.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 06:48:39 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/16 06:51:38 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	parser_check_token_type(t_mini *mini)
{
	t_token		*tmp_token;

	tmp_token = mini->tokens;
	while (tmp_token)
	{
		if (tmp_token->type == TOKEN_NOT_SET \
			|| tmp_token->type == TOKEN_UNKNOWN)
			return (mini->exec_status = EXEC_SYNTAX_ERROR, 0);
		tmp_token = tmp_token->next;
	}
	return (1);
}
