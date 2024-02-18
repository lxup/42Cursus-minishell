/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:19:54 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/18 14:30:50 by lquehec          ###   ########.fr       */
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
	close_dup_fds(mini);
	rl_clear_history();
	exit(errno);
	return (errno);
}
