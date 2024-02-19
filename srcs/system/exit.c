/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:19:54 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/19 12:53:17 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_exit(t_mini *mini)
{
	if (errno != EXIT_SUCCESS)
		ft_dprintf("%s%s\n", SHELL, strerror(errno));	
	if (mini->env)
		ft_lstclear_env(&mini->env);
	if (mini->tokens)
		ft_lstclear_token(&mini->tokens);
	if (mini->pipeline)
		ft_lstclear_pipeline(&mini->pipeline);
	if (mini->cmd_path)
		ft_free_array((void **)mini->cmd_path);
	if (mini->shell_prompt.prompt)
		free(mini->shell_prompt.prompt);
	if (mini->prompt)
		free(mini->prompt);
	if (mini->prev_prompt)
		free(mini->prev_prompt);
	// close_dup_fds(mini);
	rl_clear_history();
	if (mini->exit_code != EXIT_SUCCESS)
		return (exit(mini->exit_code), mini->exit_code);
	else
		return (exit(errno), errno);
}
