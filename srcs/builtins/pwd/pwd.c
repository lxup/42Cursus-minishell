/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 23:05:50 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/18 14:41:00 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	pwd_builtin(t_mini *mini, t_pipeline *pipeline)
{
	char	*pwd;

	ft_printf("pwd_builtin\n");
	(void)pipeline;
	pwd = ft_lstfind_env(&mini->env, "PWD");
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
