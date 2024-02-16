/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstinsert_env .c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 06:05:38 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/16 06:25:20 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_lstinsert_env(t_env **env, char *name, char *value)
{
	t_env	*start;
	t_env	*tmp;

	if (!env || !*env)
		return (0);
	start = *env;
	tmp = start;
	while (tmp)
	{
		if (ft_strcmp(tmp->name, name) == 0)
			return (0);
		tmp = tmp->next;
		if (tmp == start)
			break ;
	}
	ft_lstadd_back_env(env, ft_lstnew_env(name, value));
	return (1);
}
