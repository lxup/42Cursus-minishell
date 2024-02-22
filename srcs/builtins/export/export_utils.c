/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:40:59 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/22 12:17:05 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_valid_identifier(const char *str)
{
	int	i;

	i = 0;
	if (!ft_isalpha(str[i]) && str[i] != '_')
		return (0);
	i++;
	while (str[i] != '\0')
	{
		if (!ft_isalnum(str[i]) && str[i] != '_')
			return (0);
		i++;
	}
	return (1);
}

void	export_print(t_mini *mini)
{
	t_env	*env;

	env = mini->env;
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
		if (env == mini->env)
			break ;
	}
}

int	export_is_valid_env(t_pipeline *pipeline, char **env)
{
	int	i;

	(void)pipeline;
	if (ft_2d_strlen(env) == 0 || ft_2d_strlen(env) > 2)
		return (0);
	if (!is_valid_identifier(env[0]))
		return (0);
	i = 0;
	while (env[1] && env[1][i])
	{
		if (env[1][i] == '=')
			return (0);
		i++;
	}
	return (1);
}
