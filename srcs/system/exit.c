/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:19:54 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/13 23:07:30 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_exit(t_mini *mini, int status, char *error)
{
	// if (mini->exit_status != -1)
	// 	status = mini->exit_status;
	if (error)
		ft_putstr_err(error);
	if (mini->env)
		ft_lstclear_env(&mini->env);
	if (mini->pipeline)
		ft_lstclear_pipeline(&mini->pipeline);
	if (mini->cmd_path)
		ft_free_array((void **)mini->cmd_path);
	if (mini->prompt)
		free(mini->prompt);
	if (mini->shell_prompt.prompt)
		free(mini->shell_prompt.prompt);
	if (mini->prompt)
		free(mini->prompt);
	if (mini->prev_prompt)
		free(mini->prev_prompt);
	if (mini->pwd) // using getcwd(NULL, 0)
		free(mini->pwd);
	// if (mini->history)
	// 	ft_lstclear(&mini->history, free);
	rl_clear_history();
	exit(status);
	return (status);
}
