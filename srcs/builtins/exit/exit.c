/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:55:09 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/22 22:09:31 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_atol(char *str)
{
	int				i;
	unsigned long	res;
	int				sign;

	sign = 1;
	res = 0;
	i = 0;
	while (ft_iswhitespace(str[i]))
		i++;
	str = str + i;
	i = 0;
	i = (str[i] == '-' || str[i] == '+');
	if (str[i] == '-')
		sign = -1;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		res = res * 10 + str[i] - '0';
		if (res * sign > LONG_MAX || (long long)res * sign < LONG_MIN)
			return (0);
		i++;
	}
	return (1);
}

static int	check_arguments(t_mini *mini, t_pipeline *pipeline)
{
	int	argc;

	(void)mini;
	argc = ft_2d_strlen(pipeline->args);
	if (argc > 1 && !check_atol(pipeline->args[1]))
	{
		ft_dprintf("%s%s: %s: %s\n", SHELL, pipeline->args[0],
			pipeline->args[1], "numeric argument required");
		g_status = EXIT_BUILTIN_NONUM;
	}
	else if (argc > 2)
	{
		ft_dprintf("%s%s: %s\n", SHELL, pipeline->args[0],
			"too many arguments");
		g_status = 1;
		return (0);
	}
	else if (argc == 2)
	{
		g_status = ft_atol(pipeline->args[1]);
	}
	return (1);
}

void	exit_builtin(t_mini *mini, t_pipeline *pipeline)
{
	g_status = 0;
	if (!check_arguments(mini, pipeline))
		return ;
	if (ft_lstsize_pipeline(mini->pipeline) == 1 && write(STDERR_FILENO,
			"exit\n", 5) == -1)
		ft_dprintf("%s%s\n", SHELL, strerror(errno));
	ft_exit(mini);
}
