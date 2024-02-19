/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 13:51:22 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/19 19:16:45 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_free_mini_2(t_mini *mini)
{
	if (mini->cmd_path)
	{
		ft_free_array((void **)mini->cmd_path);
		mini->cmd_path = NULL;
	}
	if (mini->shell_prompt.prompt)
	{
		free(mini->shell_prompt.prompt);
		mini->shell_prompt.prompt = NULL;	
	}
	if (mini->prompt)
	{
		free(mini->prompt);
		mini->prompt = NULL;
	}
	if (mini->prev_prompt)
	{
		free(mini->prev_prompt);	
		mini->prev_prompt = NULL;
	}
}

void	ft_free_mini(t_mini *mini)
{
	if (mini->env)
		ft_lstclear_env(&mini->env);
	if (mini->env_array)
	{
		ft_free_array((void **)mini->env_array);
		mini->env_array = NULL;
	}
	if (mini->tokens)
		ft_lstclear_token(&mini->tokens);
	if (mini->pipeline)
		ft_lstclear_pipeline(&mini->pipeline);
	ft_free_mini_2(mini);
}
