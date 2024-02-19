/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:38:04 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/19 22:06:29 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int ac, char **av, char **env)
{
	t_mini	mini;

	(void)ac, (void)av;
	if (!isatty(STDIN_FILENO))
		return (0);
	init(&mini, env);
	minishell(&mini);
	return (ft_exit(&mini));
}
