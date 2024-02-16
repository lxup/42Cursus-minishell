/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 06:12:43 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/16 06:37:53 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	env_init(t_mini *mini, char **env)
{
	int		i;
	char	**tmp;

	i = -1;
	while (env && env[++i])
	{
		tmp = ft_split(env[i], "=");
		if (!tmp)
			ft_exit(mini, EXIT_FAILURE, ERR_MALLOC);
		ft_lstadd_back_env(&mini->env, ft_lstnew_env(tmp[0], tmp[1]));
		ft_free_array((void **)tmp);
	}
	mini->cmd_path = ft_split(ft_lstfind_env(&mini->env, "PATH"), ":");
	if (!mini->cmd_path)
		ft_exit(mini, EXIT_FAILURE, ERR_MALLOC);
	env_update(mini);
}
