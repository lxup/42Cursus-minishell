/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 18:43:41 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/22 20:56:45 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	heredoc(t_mini *mini, char *delim, t_pipeline *pipeline)
{
	int		fd;
	char	*str;

	fd = open(pipeline->heredoc, O_RDWR | O_CREAT | O_EXCL, PERM_RW);
	if (fd == -1)
		return (0);
	signal(SIGINT, &signals_heredoc);
	while (1)
	{
		str = readline("heredoc> ");
		if (!str)
		{
			if (g_status == 130)
				return (close(fd), ft_free_mini(mini), exit(g_status), 0);
			ft_dprintf("%swarning: here-document delimited by end-of-file (wanted `%s')\n", SHELL, delim);
			return (close(fd), 1);
		}
		if (!ft_strcmp(delim, str))
			return (free(str), close(fd), 1);
		str = expander_heredoc(mini, str);
		ft_putstr_fdnl(fd, str);
		free(str);
	}
	return (close(fd), 0);
}

int	exec_heredoc(t_mini *mini, char *delim, t_pipeline *pipeline)
{
	int	status;
	int	pid;

	pipeline->heredoc = heredoc_filename(pipeline);
	if (!pipeline->heredoc)
		return (ft_exit(mini), 0);
	pid = fork();
	if (pid == 0)
	{
		if (!heredoc(mini, delim, pipeline))
		{
			ft_free_mini(mini);
			exit(EXEC_CTRL_C);
		}
		ft_free_mini(mini);
		exit(0);
	}
	else
	{
		signal(SIGINT, &signals_heredoc_parents);
		waitpid(pid, &status, 0);
	}
	g_status = WEXITSTATUS(status);
	return (g_status);
}

int	process_heredocs(t_mini *mini, int heredoc_count)
{
	t_token		*token;
	t_pipeline	*pipeline;
	int			heredoc_made;

	heredoc_made = 0;
	pipeline = mini->pipeline;
	while (pipeline)
	{
		token = pipeline->tokens;
		while (token)
		{
			if (mini->exec_only_heredoc == 0)
				return (1);
			if (token->type == TOKEN_DLESSER)
			{
				if (exec_heredoc(mini, token->next->value, pipeline))
					return (0);
				heredoc_made++;
				mini->exec_only_heredoc--;
			}
			token = token->next;
		}
		pipeline = pipeline->next;
	}
	return (heredoc_made == heredoc_count);
}

int	handle_heredoc(t_mini *mini)
{
	int	ret;
	int	heredoc_count;

	heredoc_count = ft_lstcount_tokentype_pipeline(mini->pipeline,
			TOKEN_DLESSER);
	if (!heredoc_count)
		return (-1);
	ret = process_heredocs(mini, heredoc_count);
	return (ret);
}
