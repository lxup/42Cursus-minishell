/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 18:43:41 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/14 20:28:13 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	heredoc(char *delim)
{
	int		fd;
	char	*str;

	fd = open("tmp", O_RDWR | O_CREAT, 0644);
	while (1)
	{
		str = get_next_line(0);
		str[ft_strlen(str) - 1] = '\0';
		if (!ft_strcmp(delim, str))
			break ;
		ft_putstr_fdnl(fd, str);
		free(str);
	}
	free(str);
	close(fd);
}

int	handle_heredoc(t_mini *mini)
{
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
	while (token && heredoc_index < heredoc_count)
	{
		heredoc(token->next->value);
		token = ft_lstnext_tokentype_pipeline(mini->pipeline, \
			TOKEN_DLESSER, token);
		heredoc_index++;
	}
	return (1);
}
