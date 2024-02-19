/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 21:57:38 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/19 21:57:58 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_valid_identifier(const char *str)
{
	int	i;

	i = 0;
	if (!ft_isalpha(str[i]) && str[i] != '_')
		return (0);
	i++;
	while (str[i] != '\0')
	{
		if (!ft_isalnum(str[i]) && str[i] != '_')
			return (0);
		i++;
	}
	return (1);
}

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
		else if (!is_valid_identifier(pipeline->args[i]))
		{
			ft_dprintf("%sunset: %s: not a valid identifier\n", \
				SHELL, pipeline->args[i]);
			mini->exec_status = 1;
		}
		i++;
	}
	return (1);
}

void	unset_builtin(t_mini *mini, t_pipeline *pipeline)
{
	ft_printf("unset_builtin\n");
	(void)pipeline;
	if (pipeline->args[1] == NULL)
	{
		ft_dprintf("%sunset: not enough arguments\n", SHELL);
		mini->exec_status = 1;
		return ;
	}
	else
		unset_env(mini, pipeline);
}
