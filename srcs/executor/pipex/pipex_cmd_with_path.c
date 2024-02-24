/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_cmd_with_path.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 11:47:59 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/23 21:35:58 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	handle_cmd_with_path(t_pipeline *pipeline, t_mini *mini)
{
	struct stat	sb;

	if (mini->cmd_path && (ft_strchr(pipeline->args[0], '/') == NULL))
		return (0);
	if (stat(pipeline->args[0], &sb) == 0)
	{
		if (S_ISDIR(sb.st_mode))
		{
			ft_dprintf("%s%s: is a directory\n", SHELL, pipeline->args[0]);
			g_status = 126;
			return (1);
		}
		if (access(pipeline->args[0], X_OK) == 0)
			execve(pipeline->args[0], pipeline->args, mini->env_array);
		else
		{
			ft_dprintf("%s%s: Permission denied\n", SHELL, pipeline->args[0]);
			g_status = 126;
			return (1);
		}
	}
	ft_dprintf("%s%s: No such file or directory\n", SHELL, pipeline->args[0]);
	g_status = EXEC_CMD_NOT_FOUND;
	return (1);
}
