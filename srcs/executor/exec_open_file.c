/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_open_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 08:08:28 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/16 08:58:12 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	exec_open_file(t_mini *mini, t_token_type type, char *filename)
{
	int		fd;

	fd = -1;
	if (type == TOKEN_LESSER)
		fd = open(filename, O_RDONLY);
	else if (type == TOKEN_GREATER)
		fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, PERM_RW);
	else if (type == TOKEN_DGREATER)
		fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, PERM_RW);
	if (fd == -1)
	{
		ft_dprintf("%s%s: %s\n", SHELL, filename, strerror(ENOENT));
		mini->exec_status = 1;
	}
	return (fd);
}
