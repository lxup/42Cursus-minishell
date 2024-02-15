/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 22:06:20 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/15 22:15:11 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*find_name_heredoc(char *str)
{
	int	i;

	i = ft_strlen(str) - 1;
	if (i < 0)
		return (NULL);
	str[i] = 'a';
	while (str[i] <= 'z' && access(str, F_OK) == 0)
		str[i]++;
	return (str);
}

char	*heredoc_filename(t_pipeline *pipeline)
{
	char	*filename;
	char	*new_filename;

	if (pipeline->file)
		return (unlink(pipeline->file),pipeline->file);
	filename = ft_strdup(HEREDOC_TEMPLATE_PATH_PREFIX);
	if (!filename)
		return (NULL);
	while (access(filename, F_OK) == 0)
	{
		new_filename = ft_strjoin(filename, "a");
		free(filename);
		if (!new_filename)
			return (NULL);
		filename = find_name_heredoc(new_filename);
		if (!filename)
		{
			free(new_filename);
			return (NULL);
		}
	}
	unlink(filename);
	return (filename);
}
