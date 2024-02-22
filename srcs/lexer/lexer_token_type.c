/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_token_type.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 11:02:35 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/21 18:43:50 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	create_tokens(t_mini *mini)
{
	int				arg_index;
	int				i;

	i = 0;
	arg_index = 0;
	while (mini->prompt && mini->prompt[i])
	{
		while (ft_iswhitespace(mini->prompt[i]))
			i++;
		if (!mini->prompt[i])
			break ;
		if (!lexer_define_token_type(mini, &i, arg_index))
			return (p_err_syntax(mini, mini->prompt[i]), 0);
		arg_index++;
	}
	return (1);
}

int	adjust_token_type(t_token *tokens)
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
			else if (!ft_lstprev_cmd_token(tmp) \
				&& (tmp == tokens || tmp->prev->type == TOKEN_FILE))
				tmp->type = TOKEN_CMD;
			else if (tmp->prev && (tmp->prev->type == TOKEN_CMD \
				|| tmp->prev->type == TOKEN_ARGS \
				|| tmp->prev->type == TOKEN_FILE))
				tmp->type = TOKEN_ARGS;
			else if (tmp->prev && tmp->prev->type == TOKEN_PIPE)
				tmp->type = TOKEN_CMD;
		}
		tmp = tmp->next;
	}
	return (1);
}
