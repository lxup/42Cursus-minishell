/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 23:05:50 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/21 16:25:45 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	pwd_builtin(t_mini *mini, t_pipeline *pipeline)
{
	char	*pwd;

	(void)pipeline;
	pwd = getcwd(NULL, 0);
	if (pwd)
	{
		ft_printf("%s\n", pwd);
		mini->exec_status = 0;
		free(pwd);
		pwd = NULL;
	}
	else
	{
		ft_dprintf("%spwd: error retrieving current directory: getcwd: "\
		"cannot access parent directories: %s\n", SHELL, \
			strerror(errno));
		mini->exec_status = 1;
	}
}
