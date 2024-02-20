/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 18:43:41 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/20 20:33:07 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	*ft_nsm(int stp)
{
	static int	*status = {0};

	if (stp)
		*status = stp;
	return (status);
}

static int	heredoc(t_mini *mini, char *delim, t_pipeline *pipeline)
{
	int		fd;
	char	*str;

	fd = open(pipeline->heredoc, O_RDWR | O_CREAT | O_EXCL, 0644);
	if (fd == -1)
		return (0);
	signal(SIGINT, &signals_heredoc);
	// g_status = 150;
	printf("GSTATUS FDP = %d\n", g_status);
	while (1 && g_status != 130)
	{
		// if (*(ft_nsm(0)) == 130)
		// {
		// 	ft_free_mini(mini);
		// 	exit(1);
		// }
		str = readline("heredoc> ");
		if (!str)
			return (close(fd), 1);
		if (!ft_strcmp(delim, str))
			return (free(str), close(fd), 1);
		str = expander_heredoc(mini, str);
		ft_putstr_fdnl(fd, str);
		free(str);
	}
	printf("gp = %d\n", g_status);
	return (close(fd), 0);
}

int	exec_heredoc(t_mini *mini, char *delim, t_pipeline *pipeline)
{
	int	pid;
	
	pipeline->heredoc = heredoc_filename(pipeline);
	if (!pipeline->heredoc)
		return (ft_exit(mini), 0);
	// signal(SIGINT, SIG_IGN);
	pid = fork();
	if (pid == 0)
	{
		if (!heredoc(mini, delim, pipeline))
		{
			ft_free_mini(mini);
			exit (1);
		}
		// printf("ft_nsm(0) = %d\n", *(ft_nsm(0)));
		// if (*(ft_nsm(0)) != 0 || !heredoc(mini, delim, pipeline))
		// {
		// 	ft_free_mini(mini);
		// 	exit (1);
		// }
		ft_free_mini(mini);
		exit(0);
	}
	else
	{
		signal(SIGINT, SIG_IGN);
		waitpid(pid, &mini->exec_status, 0);
	}
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
	int		ret;
	int		heredoc_count;

	heredoc_count = ft_lstcount_tokentype_pipeline(mini->pipeline, \
		TOKEN_DLESSER);
	if (!heredoc_count)
		return (-1);
	// signal(SIGQUIT, &signals_heredoc_parents);
	// signal(SIGINT, &signals_heredoc_parents);
	// printf("g_status = %d\n", g_status);
	ret = process_heredocs(mini, heredoc_count);
	// printf("g_status = %d\n", g_status);
	return (ret);
}
