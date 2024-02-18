/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 06:12:43 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/18 12:50:48 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	*env_init(t_mini *mini, char **env)
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
		new = ft_lstnew_env(tmp[0], tmp[1]);
		if (!new)
			return (ft_free_array((void **)tmp), ft_exit(mini), NULL);
		ft_lstadd_back_env(&mini->env, new);
		ft_free_array((void **)tmp);
	}
	mini->cmd_path = ft_split(ft_lstfind_env(&mini->env, "PATH"), ":");
	if (!mini->cmd_path)
		ft_exit(mini);
	env_update(mini);
	return (NULL);
}
