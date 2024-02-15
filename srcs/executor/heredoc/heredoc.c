/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 18:43:41 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/15 17:21:29 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*heredoc_filename(t_token *token, int index)
{
	char	*filename;
	char	*index_str;
	char	*tmp;

	if (token->file)
	{
		unlink(token->file);
		return (token->file);
	}
	index_str = ft_itoa(index);
	tmp = ft_strjoin(HEREDOC_TEMPLATE_PATH_PREFIX, index_str);
	free(index_str);
	if (!tmp)
		return (NULL);
	filename = ft_strjoin(tmp, HEREDOC_TEMPLATE_PATH_SUFFIX);
	free(tmp);
	if (!filename)
		return (NULL);
	unlink(filename);
	return (filename);
}

int	heredoc(t_token *token, char *delim, int index)
{
	int		fd;
	char	*str;

	token->file = heredoc_filename(token, index);
	if (!token->file)
		return (0); // TODO: handle error creating file
	fd = open(token->file, O_RDWR | O_CREAT | O_EXCL, 0644);
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
	t_token	*token;
	int		heredoc_count;
	int		heredoc_index;

	heredoc_count = ft_lstcount_tokentype_pipeline(mini->pipeline, \
		TOKEN_DLESSER);
	if (!heredoc_count)
		return (0);
	heredoc_index = 0;
	token = ft_lstnext_tokentype_pipeline(mini->pipeline, TOKEN_DLESSER, NULL);
	if (!token)
		return (0);
	while (token)
	{
		if (!heredoc(token, token->next->value, heredoc_index))
			return (0);
		printf("HERE\n");
		token = ft_lstnext_tokentype_pipeline(mini->pipeline, \
			TOKEN_DLESSER, token);
		heredoc_index++;
	}
	return (1);
}
