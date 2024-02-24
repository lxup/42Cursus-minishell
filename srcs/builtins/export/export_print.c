/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 21:33:21 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/23 21:33:27 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_lstswap_env(t_env *cursor, t_env *tmp)
{
	char	*name;
	char	*value;
	int		equal_sign;

	name = cursor->name;
	value = cursor->value;
	equal_sign = cursor->equal_sign;
	cursor->name = tmp->name;
	cursor->value = tmp->value;
	cursor->equal_sign = tmp->equal_sign;
	tmp->name = name;
	tmp->value = value;
	tmp->equal_sign = equal_sign;
	return (1);
}

static int	sort_env(t_env **env)
{
	t_env	*cursor;
	t_env	*tmp;

	cursor = *env;
	while (cursor)
	{
		tmp = cursor->next;
		while (tmp)
		{
			if (ft_strcmp(cursor->name, tmp->name) > 0)
			{
				ft_lstswap_env(cursor, tmp);
				cursor = *env;
				break ;
			}
			tmp = tmp->next;
		}
		cursor = cursor->next;
	}
	return (1);
}

static int	duplicate_env(t_mini *mini, t_env **new_env)
{
	t_env	*cursor;
	t_env	*new;

	cursor = mini->env;
	while (cursor)
	{
		new = ft_lstnew_env(cursor->name, cursor->value, cursor->equal_sign);
		if (!new)
			return (0);
		ft_lstadd_back_env(new_env, new);
		cursor = cursor->next;
	}
	return (sort_env(new_env));
}

void	export_print(t_mini *mini)
{
	t_env	*env;

	env = NULL;
	if (!duplicate_env(mini, &env))
		return ;
	while (env)
	{
		if (env->name && !env->equal_sign)
			ft_printf("%s %s\n", EXPORT_BUILTIN_PRINT_ENV, \
				env->name);
		else if (env->name && env->value)
			ft_printf("%s %s=\"%s\"\n", EXPORT_BUILTIN_PRINT_ENV, \
				env->name, env->value);
		else if (env->name && !env->value)
			ft_printf("%s %s=\"\"\n", EXPORT_BUILTIN_PRINT_ENV, \
				env->name);
		env = env->next;
	}
	if (env)
		ft_lstclear_env(&env);
}
