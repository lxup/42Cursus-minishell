/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstinsert_env.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 06:05:38 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/22 21:53:11 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_lstinsert_env(t_env **env, char *name, char *value, int equal_sign)
{
	t_env	*start;
	t_env	*tmp;

	if (!env || !name)
		return (0);
	if (!*env)
	{
		*env = ft_lstnew_env(name, value, equal_sign);
		return (1);
	}
	start = *env;
	tmp = start;
	while (tmp)
	{
		if (ft_strcmp(tmp->name, name) == 0)
			return (0);
		tmp = tmp->next;
	}
	ft_lstadd_back_env(env, ft_lstnew_env(name, value, equal_sign));
	return (1);
}
