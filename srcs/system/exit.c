/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:19:54 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/19 17:26:50 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_exit(t_mini *mini)
{
	if (errno != EXIT_SUCCESS)
		ft_dprintf("%s%s\n", SHELL, strerror(errno));	
	ft_free_mini(mini);
	// close_dup_fds(mini);
	rl_clear_history();
	if (mini->exit_code != EXIT_SUCCESS)
		return (exit(mini->exit_code), mini->exit_code);
	return (exit(errno), errno);
}
