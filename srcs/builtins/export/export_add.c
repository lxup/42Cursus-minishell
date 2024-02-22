/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:45:06 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/22 12:35:44 by lquehec          ###   ########.fr       */
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
		if (pipeline->args[i][0] == '=')
			// || count_char(pipeline->args[i], '=') > 1)
		{
			ft_dprintf("%sexport: `%s': not a valid identifier\n", SHELL, \
				pipeline->args[i]);
			g_status = 1;	
			continue ;
		}
		env = ft_split(pipeline->args[i], "=");
		if (!env)
			ft_exit(mini);
		else if (!export_is_valid_env(pipeline, env))
		{
			ft_dprintf("%sexport: `%s': not a valid identifier\n", SHELL, \
				pipeline->args[i]);
			g_status = 1;
		}
		else
		{

			if (ft_2d_strlen(env) == 1)
			{
				if (!ft_strchr(pipeline->args[i], '='))
					ft_lstupsert_env(&mini->env, env[0], NULL, 0);
				else
					ft_lstupsert_env(&mini->env, env[0], NULL, 1);
			}
			else if (ft_2d_strlen(env) == 2)
				ft_lstupsert_env(&mini->env, env[0], env[1], 1);
		}
		ft_free_array((void **)env);
	}
}