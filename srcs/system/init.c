/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 12:14:28 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/19 17:40:49 by lquehec          ###   ########.fr       */
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
	mini->last_exec_status = EXEC_SUCCESS;
	mini->exec_status = EXEC_SUCCESS;
	mini->exit_code = EXIT_SUCCESS;
	// mini->std_in = dup(STDIN_FILENO);
	// if (mini->std_in == -1)
	// 	ft_exit(mini);
	// mini->std_out = dup(STDOUT_FILENO);
	// if (mini->std_out == -1)
	// 	ft_exit(mini);
	env_init(mini, env);
}

void	init(t_mini *mini, char **env)
{
	init_mini(mini, env);
	init_history(mini);
	// if (tgetent(NULL, ft_lstfind_env(&mini->env, "TERM")) != 1)
	// 	ft_exit(mini, EXIT_FAILURE, ERR_TERM);

}