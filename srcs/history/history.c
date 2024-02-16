/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emehdaou <emehdaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:31:56 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/16 18:40:41 by emehdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_history_fd_write(t_mini *mini)
{
	char	*file_path;
	int		fd;

	if (!ft_lstfind_env(&mini->env, "HOME"))
		return (-1);
	file_path = ft_strjoin(ft_lstfind_env(&mini->env, "HOME"), \
		"/.minishell_history", 0);
	if (!file_path)
		return (ft_exit(mini, EXIT_FAILURE, ERR_MALLOC), -1);
	fd = open(file_path, O_CREAT | O_RDWR | O_APPEND, 0644);
	if (fd < 0)
		return (free(file_path), -1);
	free(file_path);
	return (fd);
}

int	get_history_fd_read(t_mini *mini)
{
	char	*file_path;
	int		fd;

	if (!ft_lstfind_env(&mini->env, "HOME"))
		return (-1);
	file_path = ft_strjoin(ft_lstfind_env(&mini->env, "HOME"), \
		"/.minishell_history", 0);
	if (!file_path)
		return (ft_exit(mini, EXIT_FAILURE, ERR_MALLOC), -1);
	fd = open(file_path, O_RDONLY, 0600);
	if (fd < 0)
		return (free(file_path), -1);
	free(file_path);
	return (fd);
}

void	*init_history(t_mini *mini)
{
	int		fd;
	char	*line;
	char	*tmp;

	fd = get_history_fd_read(mini);
	if (fd < 0)
		return (NULL);
	while (1)
	{
		line = get_next_line(fd);
		if (!line || !ft_strlen(line))
			break ;
		tmp = ft_strtrim(line, " \n");
		if (!tmp)
			return (free(line), close(fd), NULL);
		add_history(tmp);
		free(line);
		free(tmp);
	}
	return (close(fd), NULL);
}

void	*add_to_history(t_mini *mini)
{
	int		fd;

	if (!ft_strlen(mini->prompt) || is_new_prompt(mini) == 0)
		return (free(mini->prompt), NULL);
	fd = get_history_fd_write(mini);
	if (fd >= 0)
	{
		write(fd, mini->prompt, ft_strlen(mini->prompt));
		write(fd, "\n", 1);
		close(fd);
	}
	add_history(mini->prompt);
	if (mini->prev_prompt)
		free(mini->prev_prompt);
	mini->prev_prompt = mini->prompt;
	mini->prompt = NULL;
	return (NULL);
}
