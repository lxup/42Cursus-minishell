/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_fix_quote.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:17:34 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/18 13:00:11 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	get_new_len(t_token *token, char *quote_type)
{
	t_token	*current;
	int		inside_quote;
	int		len;

	len = 0;
	current = token;
	inside_quote = 0;
	while (current && current->index == token->index)
	{
		if (current->type != TOKEN_QUOTE && current->type != TOKEN_DQUOTE)
			len += ft_strlen(current->value);
		else if (current->type == TOKEN_QUOTE || current->type == TOKEN_DQUOTE)
		{
			*quote_type = current->value[0];
			if (inside_quote)
				inside_quote = 0;
			else
				inside_quote = 1;
		}
		current = current->next;
	}
	if (inside_quote)
		return (-1);
	return (len);
}

static char	*get_new_value(t_mini *mini, t_token *token, int *is_word)
{
	t_token	*current;
	int		new_len;
	char	*new_value;
	char	quote_type;

	new_len = get_new_len(token, &quote_type);
	if (new_len == -1)
		return (p_err_syntax(mini, quote_type), NULL);
	new_value = ft_calloc(new_len + 1, sizeof(char));
	if (!new_value)
		return (ft_exit(mini), NULL);
	current = token;
	while (current && current->index == token->index)
	{
		if (current->type != TOKEN_QUOTE && current->type != TOKEN_DQUOTE)
		{
			ft_strlcat(new_value, current->value, new_len + 1);
			if (current->type == TOKEN_WORD || current->type == TOKEN_ENV_VAR)
				*is_word = 1;
		}
		current = current->next;
	}
	return (new_value);
}

static int	set_new_value(t_mini *mini, t_token *token, \
	char *new_value, int is_word)
{
	t_token	*current;
	t_token	*tmp_token;
	char	*tmp;

	tmp = token->value;
	token->value = new_value;
	if (is_word)
		token->type = TOKEN_WORD;
	free(tmp);
	current = token->next;
	while (current && current->index == token->index)
	{
		tmp_token = current->next;
		ft_lstremove_token(&mini->tokens, current);
		current = tmp_token;
	}
	return (1);
}

static int	fix_quote(t_mini *mini, t_token *token)
{
	char	*new_value;
	int		is_word;

	is_word = 0;
	new_value = get_new_value(mini, token, &is_word);
	if (!new_value)
		return (0);
	set_new_value(mini, token, new_value, is_word);
	return (1);
}

int	parser_fix_quote(t_mini *mini)
{
	t_token		*tmp_token;

	tmp_token = mini->tokens;
	while (tmp_token)
	{
		if (!fix_quote(mini, tmp_token))
			return (0);
		tmp_token = tmp_token->next;
	}
	return (1);
}
