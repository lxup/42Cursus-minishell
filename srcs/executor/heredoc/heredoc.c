/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 18:43:41 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/16 23:14:20 by lquehec          ###   ########.fr       */
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
		ft_putstr_fd(STDOUT_FILENO, "heredoc> ");
		str = get_next_line(STDIN_FILENO);
		if (!str)
			return (ft_putstr("\n"), close(fd), 1);
		str[ft_strlen(str) - 1] = '\0';
		if (!ft_strcmp(delim, str))
			break ;
		str = expander_heredoc(mini, str);
		ft_putstr_fdnl(fd, str);
		free(str);
	}
	return (free(str), close(fd), 1);
}

static int	process_heredocs(t_mini *mini, int heredoc_count)
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
				if (!heredoc(mini, token->next->value, pipeline))
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
	int		heredoc_count;

	heredoc_count = ft_lstcount_tokentype_pipeline(mini->pipeline, \
		TOKEN_DLESSER);
	if (!heredoc_count)
		return (0);
	return (process_heredocs(mini, heredoc_count));
}
