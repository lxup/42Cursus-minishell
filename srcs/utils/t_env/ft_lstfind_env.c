/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfind_env.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:33:05 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/11 10:32:03 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_lstfind_env(t_env **env, char *name)
{
	t_env	*start;
	t_env	*tmp;

	if (!env || !*env)
		return (NULL);
	start = *env;
	tmp = start;
	while (tmp)
	{
		if (ft_strcmp(tmp->name, name) == 0)
			return (tmp->value);
		tmp = tmp->next;
		if (tmp == start)
			break ;
	}
	return (NULL);
}
