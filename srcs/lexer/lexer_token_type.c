/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_token_type.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 11:02:35 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/17 15:07:47 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	define_word_token(t_mini *mini, int *i, int arg_index)
{
	t_token_type	type;
	int				start;
	char			quote;

	quote = 0;
	while (mini->prompt[*i] && (quote || (!quote && mini->prompt[*i] != '>' \
		&& (!ft_iswhitespace(mini->prompt[*i]) && mini->prompt[*i] != '<' \
		&& mini->prompt[*i] != '|'))))
	{
		start = *i;
		type = TOKEN_NOT_SET;
		if (is_quote(mini->prompt + *i, &quote, &type))
			*i += 1;
		else if (is_dquote(mini->prompt + *i, &quote, &type))
			*i += 1;
		else if (is_env_var(mini->prompt, i))
			type = TOKEN_ENV_VAR;
		else if (is_word_in_quote(mini->prompt, i, quote))
			type = TOKEN_WORD;
		if (type == TOKEN_NOT_SET)
			return (0);
		ft_lstadd_back_token(&mini->tokens, \
			ft_lstnew_token(ft_strndup(mini->prompt + start, \
				*i - start, 0), type, arg_index));
	}
	return (1);	
}

int	define_token_type(t_mini *mini, int *i, int arg_index)
{
	t_token_type	type;
	int				start;

	start = *i;
	
	type = TOKEN_NOT_SET;
	if (is_greater(mini->prompt + *i))
		type = TOKEN_GREATER, *i += 1;
	else if (is_dgreater(mini->prompt + *i))
		type = TOKEN_DGREATER, *i += 2;
	else if (is_lesser(mini->prompt + *i))
		type = TOKEN_LESSER, *i += 1;
	else if (is_dlesser(mini->prompt + *i))
		type = TOKEN_DLESSER, *i += 2;
	else if (is_pipe(mini->prompt + *i))
		type = TOKEN_PIPE, *i += 1;
	else if (is_word(mini->prompt, *i))
		return (define_word_token(mini, i, arg_index));
	if (type == TOKEN_NOT_SET)
		return (0);
	ft_lstadd_back_token(&mini->tokens, \
		ft_lstnew_token(ft_strndup(mini->prompt + start, \
			*i - start, 0), type, arg_index));
	return (1);
}

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
		if (!define_token_type(mini, &i, arg_index))
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
