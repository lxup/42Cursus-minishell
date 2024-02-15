/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 19:56:03 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/15 11:42:11 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// void	reset_fds(t_mini *mini)
// {
// 	mini->fd_in = -1;
// 	mini->fd_out = -1;
// 	mini->pip_in = -1;
// 	mini->pip_in = -1;
// 	mini->pid = -1;
// }

// void	ft_close_fd(int fd)
// {
// 	if (fd > 0)
// 		close(fd);
// }

// void	close_fds(t_mini *mini)
// {
// 	ft_close_fd(mini->fd_in);
// 	ft_close_fd(mini->fd_out);
// 	ft_close_fd(mini->pip_in);
// 	ft_close_fd(mini->pip_out);
// }

void close_dup_fds(t_mini *mini) {
    if (mini->std_in != -1) {
        close(mini->std_in);
        mini->std_in = -1;
    }
    if (mini->std_out != -1) {
        close(mini->std_out);
        mini->std_out = -1;
    }
}

void	reset_stds(t_mini *mini)
{
	dup2(mini->std_in, STDIN_FILENO);
	dup2(mini->std_out, STDOUT_FILENO);
}
