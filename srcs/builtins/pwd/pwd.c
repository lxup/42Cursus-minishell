/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 23:05:50 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/18 17:03:38 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	pwd_builtin(t_mini *mini, t_pipeline *pipeline)
{
	char	*pwd;

	ft_printf("pwd_builtin\n");
	(void)pipeline;
	pwd = getcwd(NULL, 0);
	if (pwd)
	{
		ft_printf("%s\n", pwd);
		mini->exec_status = 0;
	}
	else
	{
		ft_dprintf("%spwd: %s\n", SHELL, ERR_PWD_NOT_SET);
		mini->exec_status = 1;
	}
}
