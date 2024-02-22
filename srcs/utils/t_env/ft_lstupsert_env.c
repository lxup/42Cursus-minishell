/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstupsert_env.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 06:05:38 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/22 16:56:56 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	update_value(t_env *tmp, char *value, int equal_sign, \
	int *return_value)
{
	char	*tmp_value;

	tmp_value = tmp->value;
	if (value)
		tmp->value = ft_strdup(value);
	else
		tmp->value = ft_strdup("");
	free(tmp_value);
	if (!tmp->value)
		return ;
	tmp->equal_sign = equal_sign;
	*return_value += 1;
}

int	ft_lstupsert_env(t_env **env, char *name, char *value, int equal_sign)
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
			update_value(tmp, value, equal_sign, &return_value);
		tmp = tmp->next;
		if (tmp == start)
			break ;
	}
	if (return_value == 0)
		ft_lstadd_back_env(env, ft_lstnew_env(name, value, equal_sign));
	return (return_value);
}
