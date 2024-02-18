/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 15:59:21 by emehdaou          #+#    #+#             */
/*   Updated: 2024/02/18 11:43:26 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	*open_files(t_pipeline *pipeline)
{
	int	fd_in;
	int	fd_out;

	fd_in = 0;
	fd_out = 0;
	if (pipeline->infile)
	{
		fd_in = open(pipeline->infile, O_RDONLY);
		if (fd_in < 0)
			return (perror(pipeline->infile), exit(1), NULL);
		dup2(fd_in, STDIN_FILENO);
		close(fd_in);
	}
	if (pipeline->outfile)
	{
		if (pipeline->redir_append)
			fd_out = open(pipeline->outfile, O_RDWR | O_CREAT | O_APPEND, 0644);
		else
			fd_out = open(pipeline->outfile, O_RDWR | O_CREAT | O_TRUNC, 0644);
		if (fd_out < 0)
			return (perror(pipeline->outfile), exit(1), NULL);
		dup2(fd_out, STDOUT_FILENO);
		close(fd_out);
	}
	return (NULL);
}

char	*get_path_pipex(t_mini *mini, char *cmd)
{
	int		i;
	char	*tmp;

	i = 0;
	if (!cmd)
		return (NULL);
	if (!*cmd)
		return (ft_strdup(cmd));
	if (ft_strchr(cmd, '/'))
		return (ft_strdup(cmd));
	while (mini->cmd_path[i])
	{
		tmp = ft_strjoin_bs(mini->cmd_path[i], cmd);
		if (access(tmp, F_OK | X_OK) == 0)
			return (tmp);
		free(tmp);
		i++;
	}
	return (ft_strdup(cmd));
}

void	ft_waitpid(t_mini *mini, t_pipeline *pipeline)
{
	t_pipeline	*curr_pipeline;

	curr_pipeline = pipeline;
	while (curr_pipeline)
	{
		waitpid(curr_pipeline->pid, &curr_pipeline->exec_status, 0);
		mini->exec_status = WEXITSTATUS(curr_pipeline->exec_status);
		curr_pipeline = curr_pipeline->next;
	}
}
