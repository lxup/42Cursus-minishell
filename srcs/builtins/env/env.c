/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 21:55:08 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/19 21:55:20 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	env_builtin(t_mini *mini, t_pipeline *pipeline)
{
	t_env	*env;

	if (pipeline->args[1] != NULL)
	{
		ft_dprintf("%senv: too many arguments\n", SHELL);
		mini->exec_status = 1;
		return ;
	}
	env = mini->env;
	while (env)
	{
		if (env->name && env->value)
			ft_printf("%s=%s\n", env->name, env->value);
		else if (env->name && !env->value)
			ft_printf("%s=\n", env->name);
		env = env->next;
		if (env == mini->env)
			break ;
	}
}
