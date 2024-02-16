/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 12:14:28 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/16 06:41:53 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_mini(t_mini *mini, char **env)
{
	(void)env;
	mini->env = NULL;
	mini->tokens = NULL;
	mini->pipeline = NULL;
	mini->cmd_path = NULL;
	mini->prompt = NULL;
	mini->prev_prompt = NULL;
	// mini->prompt_size = 0;
	mini->shell_prompt.prompt = NULL;
	mini->shell_prompt.prompt_size = 0;
	mini->std_in = -1;
	mini->std_out = -1;
	mini->pwd = NULL;
	// mini->history = NULL;
	mini->last_exec_status = EXEC_SUCCESS;
	mini->exec_status = EXEC_SUCCESS;
	mini->exit_code = -1;
	
	// print_env(mini); // -> DEBUG
	mini->std_in = dup(STDIN_FILENO);
	if (mini->std_in == -1)
		ft_exit(mini, EXIT_FAILURE, ERR_DUP);
	mini->std_out = dup(STDOUT_FILENO);
	if (mini->std_out == -1)
		ft_exit(mini, EXIT_FAILURE, ERR_DUP);
	env_init(mini, env);
	print_env(mini); // -> DEBUG
	// reset_fds(mini);
	// signal(SIGINT, sig_handler);
	// signal(SIGQUIT, sig_handler);
}

void	init(t_mini *mini, char **env)
{
	init_mini(mini, env);
	init_history(mini);
	// if (tgetent(NULL, ft_lstfind_env(&mini->env, "TERM")) != 1)
	// 	ft_exit(mini, EXIT_FAILURE, ERR_TERM);

}