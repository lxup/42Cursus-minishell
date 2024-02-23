/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 06:12:43 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/23 18:57:41 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	*get_env(t_mini *mini, char **env)
{
	int		i;
	char	**tmp;
	t_env	*new;

	i = -1;
	while (env && env[++i])
	{
		tmp = ft_split(env[i], "=");
		if (!tmp)
			return (ft_exit(mini), NULL);
		new = ft_lstnew_env(tmp[0], tmp[1], 1);
		if (!new)
			return (ft_free_array((void **)tmp), ft_exit(mini), NULL);
		ft_lstadd_back_env(&mini->env, new);
		ft_free_array((void **)tmp);
	}
	return (NULL);
}

void	*env_init(t_mini *mini, char **env)
{
	if (env && *env)
		get_env(mini, env);
	ft_lstinsert_env(&mini->env, "PATH", \
		"/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin", 1);
	ft_lstinsert_env(&mini->env, "TERM", "xterm-256color", 1);
	env_update(mini);
	return (NULL);
}
