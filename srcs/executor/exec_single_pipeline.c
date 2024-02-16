/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_single_pipeline.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 10:55:05 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/16 11:04:36 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_single_pipeline(t_mini *mini)
{
	int	pid;
	int	status;

	(void)mini;
	(void)pid;
	(void)status;

	// tools->simple_cmds = call_expander(tools, tools->simple_cmds);
	// if (cmd->builtin == mini_cd || cmd->builtin == mini_exit
	// 	|| cmd->builtin == mini_export || cmd->builtin == mini_unset)
	// {
	// 	g_global.error_num = cmd->builtin(tools, cmd);
	// 	return ;
	// }
	// send_heredoc(tools, cmd);
	// pid = fork();
	// if (pid < 0)
	// 	ft_error(5, tools);
	// if (pid == 0)
	// 	handle_cmd(cmd, tools);
	// waitpid(pid, &status, 0);
	// if (WIFEXITED(status))
	// 	g_global.error_num = WEXITSTATUS(status);
}