/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_to_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 00:09:01 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/19 22:22:35 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	*create_env_var(t_env *env)
{
	int		var_len;
	int		value_len;
	char	*env_var;

	if (!env)
		return (NULL);
	var_len = ft_strlen(env->name);
	value_len = ft_strlen(env->value);
	env_var = ft_calloc(var_len + value_len + 2, sizeof(char));
	if (!env_var)
		return (NULL);
	ft_strlcpy(env_var, env->name, var_len + 1);
	ft_strlcpy(env_var + var_len, "=", 2);
	ft_strlcpy(env_var + var_len + 1, env->value, value_len + 1);
	return (env_var);
}

char	**env_to_str(t_env *env)
{
	char	**str;
	int		i;
	int		env_size;

	i = 0;
	env_size = ft_lstsize_env(env);
	str = malloc(sizeof(char *) * (env_size + 1));
	if (!str)
		return (NULL);
	while (i < env_size)
	{
		str[i] = create_env_var(env);
		if (!str[i])
			return (ft_free_array((void **)str), NULL);
		env = env->next;
		i++;
	}
	str[i] = NULL;
	return (str);
}
