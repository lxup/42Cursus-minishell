/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 15:58:46 by emehdaou          #+#    #+#             */
/*   Updated: 2024/02/23 12:02:18 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	*ft_exec(t_pipeline *pipeline, t_mini *mini)
{
	char	*cmd;

	if (!pipeline->args)
	{
		ft_free_mini(mini);
		return (exit(0), NULL);
	}
	if (is_builtin(mini, pipeline))
	{
		ft_free_mini(mini);
		return (exit(g_status), NULL);
	}
	cmd = get_path_pipex(mini, pipeline->args[0]);
	if (cmd)
		execve(cmd, pipeline->args, mini->env_array);
	free(cmd);
	if (handle_cmd_with_path(pipeline, mini))
		return (ft_free_mini(mini), exit(g_status), NULL);
	ft_dprintf("%s%s: command not found\n", SHELL, pipeline->args[0]);
	ft_free_mini(mini);
	return (exit(127), NULL);
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
