/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstreplace_env.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 11:32:13 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/22 21:51:32 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_lstreplace_env(t_env **env, char *name, char *value)
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
			tmp->value = value;
			return_value++;
		}
		tmp = tmp->next;
	}
	return (return_value);
}
