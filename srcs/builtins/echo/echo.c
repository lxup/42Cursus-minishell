/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 21:54:15 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/22 12:32:01 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	echo_builtin(t_mini *mini, t_pipeline *pipeline)
{
	int	i;
	int	n_flag;

	(void)mini;
	n_flag = 0;
	i = 1;
	if (pipeline->args[i] && ft_strcmp(pipeline->args[i], "-n") == 0)
	{
		n_flag = 1;
		i++;
	}
	while (pipeline->args[i])
	{
		ft_printf("%s", pipeline->args[i]);
		if (pipeline->args[i + 1])
			ft_printf(" ");
		i++;
	}
	if (!n_flag)
		ft_printf("\n");
	g_status = 0;
}
