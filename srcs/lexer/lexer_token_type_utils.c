/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_token_type_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 18:42:34 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/23 12:32:11 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	lexer_check_case(t_mini *mini, int *i, t_token_type *type)
{
	if (is_greater(mini->prompt + *i, type))
		return (*i += 1, 1);
	else if (is_dgreater(mini->prompt + *i, type))
		return (*i += 2, 1);
	else if (is_lesser(mini->prompt + *i, type))
		return (*i += 1, 1);
	else if (is_dlesser(mini->prompt + *i, type))
		return (*i += 2, 1);
	else if (is_pipe(mini->prompt + *i))
		return (*type = TOKEN_PIPE, *i += 1, 1);
	return (0);
}

static void	lexer_check_case_word(t_mini *mini, int *i, char *quote,
		t_token_type *type)
{
	if (is_quote(mini->prompt + *i, quote, type))
		*i += 1;
	else if (is_dquote(mini->prompt + *i, quote, type))
		*i += 1;
	else if (is_env_var(mini->prompt, i))
		*type = TOKEN_ENV_VAR;
	else if (is_tilde(mini->prompt, i))
		*type = TOKEN_TILDE;
	else if (is_word_in_quote(mini->prompt, i, *quote))
		*type = TOKEN_WORD;
}

static int	define_word_token(t_mini *mini, int *i, int arg_index)
{
	t_token_type	type;
	int				start;
	char			quote;
	char			*tmp;

	quote = 0;
	while (mini->prompt[*i] && (quote || (!quote && mini->prompt[*i] != '>'
				&& (!ft_iswhitespace(mini->prompt[*i])
					&& mini->prompt[*i] != '<' && mini->prompt[*i] != '|'))))
	{
		tmp = NULL;
		start = *i;
		type = TOKEN_NOT_SET;
		lexer_check_case_word(mini, i, &quote, &type);
		if (type == TOKEN_NOT_SET)
			return (0);
		tmp = ft_strndup(mini->prompt + start, *i - start, 0);
		if (!tmp)
			return (ft_exit(mini), 0);
		ft_lstadd_back_token(&mini->tokens, ft_lstnew_token(tmp, type, \
			arg_index));
	}
	return (1);
}

int	lexer_define_token_type(t_mini *mini, int *i, int arg_index)
{
	t_token_type	type;
	int				start;
	char			*tmp;

	start = *i;
	type = TOKEN_NOT_SET;
	tmp = NULL;
	if (lexer_check_case(mini, i, &type))
		tmp = NULL;
	else if (is_word(mini->prompt, *i))
		return (define_word_token(mini, i, arg_index));
	if (type == TOKEN_NOT_SET)
		return (0);
	tmp = ft_strndup(mini->prompt + start, *i - start, 0);
	if (!tmp)
		return (ft_exit(mini), 0);
	ft_lstadd_back_token(&mini->tokens, ft_lstnew_token(tmp, type, arg_index));
	return (1);
}
