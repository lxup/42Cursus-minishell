/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_fix_quote.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:17:34 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/16 06:49:33 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	set_new_value(char **str, t_token *token)
{
	int		i;
	int		j;
	char	quote_type;

	i = 0;
	j = 0;
	quote_type = 0;
	while (token->value[i])
	{
		if (token->value[i] == '\'' || token->value[i] == '\"')
		{
			quote_type = token->value[i];
			i++;
			while (token->value[i] && token->value[i] != quote_type)
				(*str)[j++] = token->value[i++];
			quote_type = 0;
		}
		else
		{
			(*str)[j] = token->value[i];
			j++;
		}
		i++;
	}
	return (1);
}

static int	get_new_len(char *str)
{
	int		i;
	int		len;
	char	quote_type;

	i = -1;
	len = 0;
	quote_type = 0;
	while (str[++i])
	{
		if (str[i] == '\'' || str[i] == '\"')
		{
			quote_type = str[i];
			i++;
			while (str[i] && str[i] != quote_type)
			{
				len++;
				i++;
			}
			if (str[i] == '\0')
				return (-1);
		}
		else
			len++;
	}
	return (len);
}

static int	fix_quote(t_mini *mini, t_token *token)
{
	char	*new_value;
	char	*tmp;
	int		new_len;

	new_len = get_new_len(token->value);
	if (new_len == -1)
		return (mini->exec_status = EXEC_SYNTAX_ERROR, 0);
	if (new_len == (int)ft_strlen(token->value) || new_len == 0)
		return (1);
	new_value = ft_calloc(new_len + 1, sizeof(char));
	if (!new_value)
		return (0);
	set_new_value(&new_value, token);
	if (ft_strlen(new_value) != (size_t)new_len)
		return (free(new_value), 0);
	tmp = token->value;
	token->value = new_value;
	free(tmp);
	return (1);
}

int	parser_fix_quote(t_mini *mini)
{
	t_token		*tmp_token;

	tmp_token = mini->tokens;
	while (tmp_token)
	{
		if (ft_contains_char(tmp_token->value, '\'') \
			|| ft_contains_char(tmp_token->value, '\"'))
		{
			if (!fix_quote(mini, tmp_token))
				return (0);
		}
		tmp_token = tmp_token->next;
	}
	return (1);
}
