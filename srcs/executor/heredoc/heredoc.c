/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 18:43:41 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/15 22:14:35 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// char	*heredoc_filename(t_pipeline *pipeline)
// {
// 	char	*filename;
// 	char	*index_str;
// 	char	*tmp;

// 	if (pipeline->file)
// 	{
// 		unlink(pipeline->file);
// 		return (pipeline->file);
// 	}
// 	index_str = ft_itoa(pipeline);
// 	tmp = ft_strjoin(HEREDOC_TEMPLATE_PATH_PREFIX, index_str);
// 	free(index_str);
// 	if (!tmp)
// 		return (NULL);
// 	filename = ft_strjoin(tmp, HEREDOC_TEMPLATE_PATH_SUFFIX);
// 	free(tmp);
// 	if (!filename)
// 		return (NULL);
// 	unlink(filename);
// 	return (filename);
// }

int	heredoc(t_mini *mini, char *delim, t_pipeline *pipeline)
{
	int		fd;
	char	*str;

	pipeline->file = heredoc_filename(pipeline);
	if (!pipeline->file)
		return (0); // TODO: handle error creating file
	fd = open(pipeline->file, O_RDWR | O_CREAT | O_EXCL, 0644);
	if (fd == -1)
		return (0); // TODO: handle error opening file
	while (1)
	{
		ft_putstr_fd(STDOUT_FILENO, "heredoc> ");
		str = get_next_line(STDIN_FILENO);
		if (!str )
		{
			ft_putstr("\n");
			break ;
		}
		str = expander_heredoc(mini, str);
		str[ft_strlen(str) - 1] = '\0';
		if (!ft_strcmp(delim, str))
			break ;
		ft_putstr_fdnl(fd, str);
		free(str);
	}
	return (free(str), close(fd), 1);
}

int	handle_heredoc(t_mini *mini)
{
	(void)mini;
	t_token		*token;
	t_pipeline	*pipeline;
	int		heredoc_count;

	heredoc_count = ft_lstcount_tokentype_pipeline(mini->pipeline, \
		TOKEN_DLESSER);
	if (!heredoc_count)
		return (0);
	pipeline = NULL;
	token = ft_lstnext_tokentype_pipeline(mini->pipeline, TOKEN_DLESSER, NULL, \
		&pipeline);
	if (!token)
		return (0);
	while (token)
	{
		if (!heredoc(mini, token->next->value, pipeline))
			return (0);
		token = ft_lstnext_tokentype_pipeline(mini->pipeline, \
			TOKEN_DLESSER, token, &pipeline);
	}
	return (1);
}
