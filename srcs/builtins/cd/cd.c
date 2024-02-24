/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 21:52:55 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/24 13:13:09 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	go_home(t_mini *mini, t_pipeline *pipeline)
{
	t_env	*env;

	if (ft_2d_strlen(pipeline->args) == 1)
	{
		env = ft_lstfind_env(&mini->env, "HOME");
		if (env)
		{
			if (chdir(env->value) == -1)
			{
				ft_dprintf("%scd: %s: %s\n", SHELL, \
					env->value, strerror(errno));
				g_status = 1;
			}
		}
		else
		{
			ft_dprintf("%scd: HOME not set\n", SHELL);
			g_status = 1;
		}
		return (1);
	}
	return (0);
}

static int	go_oldpwd(t_mini *mini, t_pipeline *pipeline)
{
	t_env	*env;

	if (ft_2d_strlen(pipeline->args) == 2 \
		&& !ft_strcmp(pipeline->args[1], "-"))
	{
		env = ft_lstfind_env(&mini->env, "OLDPWD");
		if (env)
		{
			if (chdir(env->value) == -1)
			{
				ft_dprintf("%scd: %s: %s\n", SHELL, \
					env->value, strerror(errno));
				g_status = 1;
			}
			printf("%s\n", env->value);
		}
		else
		{
			ft_dprintf("%scd: OLDPWD not set\n", SHELL);
			g_status = 1;
		}
		return (1);
	}
	return (0);
}

void	cd_builtin(t_mini *mini, t_pipeline *pipeline)
{
	g_status = 0;
	if (ft_2d_strlen(pipeline->args) > 2)
	{
		ft_dprintf("%scd: too many arguments\n", SHELL);
		g_status = 1;
		return ;
	}
	else if (go_home(mini, pipeline))
		return ;
	else if (go_oldpwd(mini, pipeline))
		return ;
	if (chdir(pipeline->args[1]) != 0)
	{
		ft_dprintf("%scd: %s: %s\n", SHELL, pipeline->args[1], strerror(errno));
		g_status = 1;
	}
}
