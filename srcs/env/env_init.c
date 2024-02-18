/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 06:12:43 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/18 17:01:35 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	*env_init(t_mini *mini, char **env)
{
	int		i;
	char	**tmp;
	t_env	*new;
	t_env	*cmd_path;

	i = -1;
	while (env && env[++i])
	{
		tmp = ft_split(env[i], "=");
		if (!tmp)
			return (ft_exit(mini), NULL);
		new = ft_lstnew_env(tmp[0], tmp[1]);
		if (!new)
			return (ft_free_array((void **)tmp), ft_exit(mini), NULL);
		ft_lstadd_back_env(&mini->env, new);
		ft_free_array((void **)tmp);
	}
	cmd_path = ft_lstfind_env(&mini->env, "PATH");
	if (!cmd_path)
		return (ft_exit(mini), NULL);
	mini->cmd_path = ft_split(cmd_path->value, ":");
	if (!mini->cmd_path)
		return (ft_exit(mini), NULL);
	env_update(mini);
	return (NULL);
}
