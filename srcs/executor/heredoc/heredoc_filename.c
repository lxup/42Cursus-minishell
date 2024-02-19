/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_filename.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 22:06:20 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/19 20:50:34 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*find_name_heredoc(char *str)
{
	int	i;

	i = ft_strlen(str) - 1;
	if (i < 0)
		return (NULL);
	str[i] = '1';
	while (str[i] <= '9' && access(str, F_OK) == 0)
		str[i]++;
	return (str);
}

char	*heredoc_filename(t_pipeline *pipeline)
{
	char	*filename;
	char	*new_filename;

	if (pipeline->heredoc)
		return (unlink(pipeline->heredoc), pipeline->heredoc);
	filename = ft_strdup(HEREDOC_TEMPLATE_PATH_PREFIX);
	if (!filename)
		return (NULL);
	while (access(filename, F_OK) == 0)
	{
		new_filename = ft_strjoin(filename, "1");
		free(filename);
		filename = NULL;
		if (!new_filename)
			return (NULL);
		filename = find_name_heredoc(new_filename);
		if (!filename)
		{
			free(new_filename);
			new_filename = NULL;
			return (NULL);
		}
	}
	unlink(filename);
	return (filename);
}
