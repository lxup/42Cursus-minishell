/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 15:58:46 by emehdaou          #+#    #+#             */
/*   Updated: 2024/02/22 22:10:03 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_exec(t_pipeline *pipeline, t_mini *mini)
{
	char	*cmd;

	if (!pipeline->args)
	{
		ft_free_mini(mini);
		exit(0);
	}
	if (is_builtin(mini, pipeline))
	{
		ft_free_mini(mini);
		exit(g_status);
	}
	cmd = get_path_pipex(mini, pipeline->args[0]);
	if (cmd)
		execve(cmd, pipeline->args, mini->env_array);
	free(cmd);
	ft_dprintf("%s%s: command not found\n", SHELL, pipeline->args[0]);
	ft_free_mini(mini);
	exit(127);
}

void	ft_process(t_pipeline *pipeline, t_mini *mini)
{
	t_pipeline	*curr;

	curr = pipeline;
	while (curr)
	{
		if (pipe(mini->pipefd) == -1)
			exit(EXIT_FAILURE);
		curr->pid = fork();
		if (curr->pid == 0)
		{
			signals_child();
			init_redir(mini, curr);
			ft_exec(curr, mini);
		}
		else
		{
			if (curr->prev)
				close(mini->prevpipe);
			mini->prevpipe = mini->pipefd[0];
			close(mini->pipefd[1]);
		}
		curr = curr->next;
	}
	signals_parent();
	ft_waitpid(mini, pipeline);
}

int	pipex(t_mini *mini)
{
	ft_process(mini->pipeline, mini);
	close(mini->pipefd[0]);
	return (1);
}
