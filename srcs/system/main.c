/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:38:04 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/20 20:43:31 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

pid_t	g_status;

static t_mini	*set_static(void)
{
	static t_mini	mini;

	return (&mini);
}

int	main(int ac, char **av, char **env)
{
	t_mini	*mini;

	(void)ac, (void)av;
	if (!isatty(STDIN_FILENO))
		return (0);
	mini = set_static();
	init(mini, env);
	minishell(mini);
	return (ft_exit(mini));
}
