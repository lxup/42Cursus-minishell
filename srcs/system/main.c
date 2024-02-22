/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:38:04 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/22 19:56:24 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

pid_t	g_status;

int	main(int ac, char **av, char **env)
{
	t_mini	mini;

	(void)ac, (void)av;
	signal(SIGPIPE, SIG_IGN);
	if (!isatty(STDIN_FILENO))
		return (0);
	init(&mini, env);
	minishell(&mini);
	return (ft_exit(&mini));
}
