/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_update.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 06:15:39 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/17 15:19:27 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	create_shell_lvl(t_mini *mini)
{
	char	*env;
	char	*level;

	env = ft_lstfind_env(&mini->env, "SHLVL");
	if (env)
	{
		level = ft_itoa(ft_atoi(env) + 1);
		if (!level)
			return (0);
		ft_lstupsert_env(&mini->env, "SHLVL", level);
		free(level);
	}
	else
		ft_lstupsert_env(&mini->env, "SHLVL", "1");
	return (1);
}

static int	create_pwd(t_mini *mini)
{
	char	*pwd;

	pwd = getcwd(NULL, 0);
	if (!pwd)
		return (0);
	ft_lstupsert_env(&mini->env, "PWD", pwd);
	free(pwd);
	return (1);
}

int	env_update(t_mini *mini)
{
	if (!create_pwd(mini))
		return (0);
	if (!create_shell_lvl(mini))
		return (0);
	ft_lstinsert_env(&mini->env, "_", "/usr/bin/env");
	ft_lstinsert_env(&mini->env, "TERM", "xterm-256color");
	ft_lstinsert_env(&mini->env, "LOUP", "ok\"");
	return (1);
}
