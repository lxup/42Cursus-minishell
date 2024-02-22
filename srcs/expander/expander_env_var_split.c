/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_env_var_split.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 12:47:13 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/22 16:00:35 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	insert_new_token(t_mini *mini, t_token *token, char **split, \
	int space_at_end)
{
	t_token	*current;
	t_token	*new_token;
	int		current_index;
	char	*value;
	int		i;

	i = 0;
	current = token;
	current_index = token->index + 1;
	while (split[++i])
	{
		value = NULL;
		value = ft_strdup(split[i]);
		if (!value)
			return (ft_free_array((void **)split), ft_exit(mini), 0);
		new_token = ft_lstnew_token(value, TOKEN_WORD, current_index);
		if (!new_token)
			return (ft_free_array((void **)split), ft_exit(mini), 0);
		ft_lstinsertafter_token(&mini->tokens, \
			current, new_token, space_at_end);
		current = new_token;
		current_index++;
	}
	return (1);
}

int	expander_env_var_split(t_mini *mini, t_token *token, int space_at_end)
{
	char	**split;

	split = ft_split(token->value, " \n\t");
	if (!split)
		return (ft_exit(mini), 0);
	if (ft_2d_strlen(split) > 1)
	{
		free(token->value);
		token->value = ft_strdup(split[0]);
		if (!token->value)
			return (ft_free_array((void **)split), ft_exit(mini), 0);
		insert_new_token(mini, token, split, space_at_end);
	}
	ft_free_array((void **)split);
	return (1);
}
