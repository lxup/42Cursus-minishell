/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:45:06 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/21 19:01:56 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	export_add(t_mini *mini, t_pipeline *pipeline)
{
	int		i;
	char	**env;

	i = 0;
	while (pipeline->args[++i])
	{
		if (!ft_strchr(pipeline->args[i], '=') || pipeline->args[i][0] == '=')
			// || count_char(pipeline->args[i], '=') > 1)
		{
			mini->exec_status = 1;
			ft_dprintf("%sexport: `%s': not a valid identifier\n", SHELL, \
				pipeline->args[i]);		
			continue ;
		}
		if (pipeline->args[i][0] == '-')
		{
			mini->exec_status = 2;
			continue ;
		}
		env = ft_split(pipeline->args[i], "=");
		if (!env)
			ft_exit(mini);
		else if (!export_is_valid_env(pipeline, env))
		{
			mini->exec_status = 1;
			ft_dprintf("%sexport: `%s': not a valid identifier\n", SHELL, \
				pipeline->args[i]);
		}
		else
		{
			if (ft_2d_strlen(env) == 1)
				ft_lstupsert_env(&mini->env, env[0], NULL);
			else if (ft_2d_strlen(env) == 2)
				ft_lstupsert_env(&mini->env, env[0], env[1]);
		}
		ft_free_array((void **)env);
	}
}
