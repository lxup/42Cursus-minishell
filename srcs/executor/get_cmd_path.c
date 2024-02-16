/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 17:53:18 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/17 00:11:45 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_cmd_path(t_mini *mini, char *cmd)
{
	int		i;
	char	**path;
	char	*tmp;

	i = 0;
	if (ft_strchr(cmd, '/'))
		return (cmd);
	while (mini->cmd_path[i])
	{
		tmp = ft_strjoin(path[i], cmd);
		if (access(tmp, F_OK | X_OK) == 0)
			return (tmp);
		free(tmp);
		i++;
	}
	return (cmd);
}
