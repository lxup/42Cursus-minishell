/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_update.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 06:15:39 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/22 22:02:00 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	create_shell_lvl(t_mini *mini)
{
	t_env	*env;
	char	*level;

	env = ft_lstfind_env(&mini->env, "SHLVL");
	if (env)
	{
		level = ft_itoa(ft_atoi(env->value) + 1);
		if (!level)
			return (ft_exit(mini), 0);
		ft_lstupsert_env(&mini->env, "SHLVL", level, 1);
		free(level);
		level = NULL;
	}
	else
		ft_lstupsert_env(&mini->env, "SHLVL", "1", 1);
	return (1);
}

static int	create_pwd(t_mini *mini)
{
	char	*pwd;

	pwd = getcwd(NULL, 0);
	if (!pwd)
	{
		pwd = ft_strdup("?");
		if (!pwd)
			return (ft_exit(mini), 0);
	}
	ft_lstupsert_env(&mini->env, "PWD", pwd, 1);
	free(pwd);
	pwd = NULL;
	return (1);
}

static int	create_cmd(t_mini *mini)
{
	t_env	*cmd_path;
	
	if (mini->cmd_path)
	{
		ft_free_array((void **)mini->cmd_path);
		mini->cmd_path = NULL;
	}
	cmd_path = ft_lstfind_env(&mini->env, "PATH");
	if (!cmd_path)
		return (1);
	mini->cmd_path = ft_split(cmd_path->value, ":");
	if (!mini->cmd_path)
		return (ft_exit(mini), 0);
	return (1);
}

int	env_update(t_mini *mini)
{
	if (!create_pwd(mini))
		return (0);
	if (!create_shell_lvl(mini))
		return (0);
	if (!create_cmd(mini))
		return (0);
	ft_lstinsert_env(&mini->env, "_", "/usr/bin/env", 1);
	ft_lstinsert_env(&mini->env, "TERM", "xterm-256color", 1);
	return (1);
}
