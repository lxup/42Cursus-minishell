/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_env_var.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 20:49:58 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/21 16:58:10 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_token_type	prev_token_type(t_token *token)
{
	t_token	*tmp;

	tmp = token;
	while (tmp && tmp->index == token->index)
		tmp = tmp->prev;
	if (tmp)
		return (tmp->type);
	return (TOKEN_NOT_SET);
}

static int	ambiguous_redirect(t_token *token)
{
	if ((!token->next || (token->next && token->next->index != token->index)) \
		&& token->prev && (token->prev->type == TOKEN_DLESSER \
		|| token->prev->type == TOKEN_LESSER \
		|| token->prev->type == TOKEN_GREATER \
		|| token->prev->type == TOKEN_DGREATER))
	{
		ft_dprintf("%s%s: ambiguous redirect\n", SHELL, token->value);
		return (-1);
	}
	return (0);
}

static int	expand_env_var(t_mini *mini, t_token *token)
{
	t_env	*env_var;
	char	*env_var_value;
	char	*tmp;

	env_var = NULL;
	env_var_value = NULL;
	if (prev_token_type(token) == TOKEN_DLESSER)
		return (1);
	if (ft_strcmp(token->value + 1, "?") == 0)
		env_var_value = ft_itoa(mini->last_exec_status);
	else
	{
		env_var = ft_lstfind_env(&mini->env, token->value + 1);
		if (env_var)
			env_var_value = ft_strdup(env_var->value);
		else
			return (ambiguous_redirect(token));
	}
	if (!env_var_value)
		return (ft_exit(mini));
	tmp = token->value;
	token->value = env_var_value;
	free(tmp);
	return (1);
}

int	expander_env_var(t_mini *mini)
{
	int			ret;
	t_token		*token;
	t_token		*tmp;

	token = mini->tokens;
	while (token)
	{
		tmp = NULL;
		if (token->type == TOKEN_ENV_VAR)
		{	
			ret = expand_env_var(mini, token);
			if (ret == 0)
			{
				tmp = token->next;
				ft_lstremove_token(&mini->tokens, token);
				token = tmp;
				continue ;
			}
			if (ret == -1)
				return (0);
		}
		token = token->next;
	}
	return (1);
}
