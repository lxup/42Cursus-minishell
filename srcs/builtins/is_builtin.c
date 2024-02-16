/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 08:25:49 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/16 09:07:45 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_builtin(t_mini *mini, char *cmd, char **args)
{
	if (ft_strcmp(cmd, "echo") == 0)
		return (echo_builtin(mini, cmd, args), 1);
	else if (ft_strcmp(cmd, "cd") == 0)
		return (cd_builtin(mini, cmd, args), 1);
	else if (ft_strcmp(cmd, "pwd") == 0)
		return (pwd_builtin(mini, cmd, args), 1);
	else if (ft_strcmp(cmd, "export") == 0)
		return (export_builtin(mini, cmd, args), 1);
	else if (ft_strcmp(cmd, "unset") == 0)
		return (unset_builtin(mini, cmd, args), 0);
	else if (ft_strcmp(cmd, "env") == 0)
		return (env_builtin(mini, cmd, args), 0);
	else if (ft_strcmp(cmd, "exit") == 0)
		return (exit_builtin(mini, cmd, args), 0);
	if (ft_lstsize_env(mini->env) == 0)
		mini->exec_status = 127;
	return (0);
}
