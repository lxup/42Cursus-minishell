/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 21:57:38 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/22 21:44:53 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	unset_env(t_mini *mini, t_pipeline *pipeline)
{
	t_env	*env_var;
	int		i;

	i = 1;
	while (pipeline->args[i])
	{
		env_var = NULL;
		env_var = ft_lstfind_env(&mini->env, pipeline->args[i]);
		if (env_var)
			ft_lstremove_env(&mini->env, env_var);
		i++;
	}
	return (1);
}

void	unset_builtin(t_mini *mini, t_pipeline *pipeline)
{
	if (pipeline->args[1] == NULL)
		return ;
	else
		unset_env(mini, pipeline);
}
