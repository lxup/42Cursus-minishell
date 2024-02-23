/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_tilde.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 12:35:10 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/23 14:07:49 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	expand_tilde(t_mini *mini, t_token *token)
{
	t_env	*home;
	char	*tmp;

	home = ft_lstfind_env(&mini->env, "HOME");
	if (!home)
		return (0);
	if ((!token->prev || (token->prev && token->prev->index != token->index)) \
		&& (!token->next \
		|| (token->next && token->next->index != token->index)))
	{
		tmp = ft_strdup(home->value);
		if (!tmp)
			return (ft_exit(mini), -1);
		free(token->value);
		token->value = tmp;
	}
	return (1);
}

int	expander_tilde(t_mini *mini)
{
	int			ret;
	t_token		*token;
	t_token		*tmp;

	token = mini->tokens;
	while (token)
	{
		tmp = NULL;
		if (token->type == TOKEN_TILDE)
		{
			ret = expand_tilde(mini, token);
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
