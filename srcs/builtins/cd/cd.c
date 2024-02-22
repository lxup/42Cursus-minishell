/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 21:52:55 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/21 16:29:33 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	go_home(t_mini *mini, t_pipeline *pipeline)
{
	t_env	*env;

	if (ft_2d_strlen(pipeline->args) == 1 || (pipeline->args[1] \
		&& !ft_strcmp(pipeline->args[1], "~")))
	{
		env = ft_lstfind_env(&mini->env, "HOME");
		if (env)
		{
			if (chdir(env->value) == -1)
			{
				ft_dprintf("%s: cd: %s: %s\n", SHELL, \
					env->value, strerror(errno));
				mini->exec_status = 1;
			}
		}
		else
		{
			ft_dprintf("%s: cd: HOME not set\n", SHELL);
			mini->exec_status = 1;
		}
		return (1);
	}
	return (0);
}

void	cd_builtin(t_mini *mini, t_pipeline *pipeline)
{
	if (ft_2d_strlen(pipeline->args) > 2)
	{
		ft_dprintf("%scd: too many arguments\n", SHELL);
		mini->exec_status = 1;
		return ;
	}
	else if (go_home(mini, pipeline))
		return ;
	if (chdir(pipeline->args[1]) != 0)
	{
		ft_dprintf("%scd: %s: %s\n", SHELL, pipeline->args[1], strerror(errno));
		mini->exec_status = 1;
	}
}
