/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 08:25:49 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/19 21:36:29 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_builtin(t_mini *mini, t_pipeline *pipeline)
{
	if (!pipeline->args)
		return (0);
	if (ft_strcmp(pipeline->args[0], "echo") == 0)
		return (echo_builtin(mini, pipeline), 1);
	else if (ft_strcmp(pipeline->args[0], "cd") == 0)
		return (cd_builtin(mini, pipeline), 1);
	else if (ft_strcmp(pipeline->args[0], "pwd") == 0)
		return (pwd_builtin(mini, pipeline), 1);
	else if (ft_strcmp(pipeline->args[0], "export") == 0)
		return (export_builtin(mini, pipeline), 1);
	else if (ft_strcmp(pipeline->args[0], "unset") == 0)
		return (unset_builtin(mini, pipeline), 1);
	else if (ft_strcmp(pipeline->args[0], "env") == 0)
		return (env_builtin(mini, pipeline), 1);
	else if (ft_strcmp(pipeline->args[0], "exit") == 0)
		return (exit_builtin(mini, pipeline), 1);
	if (ft_lstsize_env(mini->env) == 0)
		mini->exec_status = 127;
	return (0);
}
