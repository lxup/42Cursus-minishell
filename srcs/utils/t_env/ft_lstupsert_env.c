/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstupsert_env.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 06:05:38 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/16 06:22:07 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_lstupsert_env(t_env **env, char *name, char *value)
{
	int		return_value;
	t_env	*start;
	t_env	*tmp;

	return_value = 0;
	if (!env || !*env)
		return (return_value);
	start = *env;
	tmp = start;
	while (tmp)
	{
		if (ft_strcmp(tmp->name, name) == 0)
		{
			free(tmp->value);
			tmp->value = ft_strdup(value);
			if (tmp->value)
				return_value++;
		}
		tmp = tmp->next;
		if (tmp == start)
			break ;
	}
	if (return_value == 0)
		ft_lstadd_back_env(env, ft_lstnew_env(name, value));
	return (return_value);
}
