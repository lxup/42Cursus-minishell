/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 18:43:41 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/20 11:30:00 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	heredoc(t_mini *mini, char *delim, t_pipeline *pipeline)
{
	int		fd;
	char	*str;

	pipeline->heredoc = heredoc_filename(pipeline);
	if (!pipeline->heredoc)
		return (0);
	fd = open(pipeline->heredoc, O_RDWR | O_CREAT | O_EXCL, 0644);
	if (fd == -1)
		return (0);
	while (1)
	{
		// signal(SIGQUIT, SIG_IGN);
		signal(SIGINT, &signals_heredoc);
		str = readline("heredoc> ");
		if (!str)
			return (close(fd), 1);
		if (!ft_strcmp(delim, str))
			break ;
		str = expander_heredoc(mini, str);
		ft_putstr_fdnl(fd, str);
		free(str);
	}
	return (free(str), close(fd), 1);
}

int	exec_heredoc(t_mini *mini, char *delim, t_pipeline *pipeline)
{
	int	pid;
	
	pid = fork();
	if (pid == 0)
		heredoc(mini, delim, pipeline);
	waitpid(pid, &mini->exec_status, 0);
	mini->exec_status = WEXITSTATUS(mini->exec_status);
	return (mini->exec_status);
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
				if (exec_heredoc(mini, token->next->value, pipeline) == 1)
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

// static int	heredoc_child(t_mini *mini)
// {
// 	signal(SIGINT, signals_heredoc);
// 	heredoc(mini, , mini->pipeline);
// 	exit(0);
// }

// static int	heredoc_parent(t_mini *mini)
// {
// 	int	exit_status;
	
// 	signal(SIGINT, SIG_IGN);
// 	wait(&exit_status);
// 	if (WIFEXITED(exit_status))
// 	{
// 		mini->exec_status = WEXITSTATUS(exit_status);
// 		if (mini->exec_status == 1)
// 			return (0);
// 	}
// 	signals(mini);
// 	return (1);
// }

// int	handle_heredoc(t_mini *mini)
// {
// 	int	pid;
	
// 	pid = fork();
// 	if (pid == 0)
// 		heredoc_child(mini);
// 	else
// 		return (heredoc_parent(mini));
// }

int	handle_heredoc(t_mini *mini)
{
	int		ret;
	int		heredoc_count;

	heredoc_count = ft_lstcount_tokentype_pipeline(mini->pipeline, \
		TOKEN_DLESSER);
	if (!heredoc_count)
		return (-1);
	signal(SIGQUIT, &signals_heredoc_parents);
	signal(SIGINT, &signals_heredoc_parents);
	ret = process_heredocs(mini, heredoc_count);
	signal(SIGQUIT, SIG_DFL);
	signal(SIGINT, SIG_DFL);
	signals(mini);
	return (ret);
}
