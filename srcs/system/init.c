/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 12:14:28 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/22 19:59:35 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_mini(t_mini *mini, char **env)
{
	(void)env;
	mini->env = NULL;
	mini->env_array = NULL;
	mini->tokens = NULL;
	mini->pipeline = NULL;
	mini->cmd_path = NULL;
	mini->prompt = NULL;
	mini->prev_prompt = NULL;
	mini->shell_prompt.prompt = NULL;
	mini->shell_prompt.prompt_size = 0;
	mini->std_in = -1;
	mini->std_out = -1;
	mini->exec_only_heredoc = -1;
	mini->exit_code = EXIT_SUCCESS;
	env_init(mini, env);
}

void	init(t_mini *mini, char **env)
{
	init_mini(mini, env);
	init_history(mini);
}
