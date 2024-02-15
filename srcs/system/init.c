/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 12:14:28 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/15 16:54:26 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	init_shell_level(t_mini *mini)
{
	char	*env;
	char	*level;

	env = ft_lstfind_env(&mini->env, "SHLVL");
	if (env)
	{
		level = ft_itoa(ft_atoi(env) + 1);
		if (!level)
			ft_exit(mini, EXIT_FAILURE, ERR_MALLOC);
		if (!ft_lstreplace_env(&mini->env, "SHLVL", level))
			ft_lstadd_back_env(&mini->env, ft_lstnew_env("SHLVL", level));
	}
	else
	{		
		level = ft_itoa(1);
		if (!level)
			ft_exit(mini, EXIT_FAILURE, ERR_MALLOC);
		ft_lstadd_back_env(&mini->env, ft_lstnew_env("SHLVL", level));
	}
}

static void	init_env(t_mini *mini, char **env)
{
	int		i;
	char	**tmp;

	i = -1;
	while (env && env[++i])
	{
		tmp = ft_split(env[i], "=");
		if (!tmp)
			ft_exit(mini, EXIT_FAILURE, ERR_MALLOC); // TODO: handle error and free memory
		ft_lstadd_back_env(&mini->env, ft_lstnew_env(tmp[0], tmp[1]));
		ft_free_array((void **)tmp);
	}
	mini->cmd_path = ft_split(ft_lstfind_env(&mini->env, "PATH"), ":");
	if (!mini->cmd_path)
		ft_exit(mini, EXIT_FAILURE, ERR_MALLOC);
	// if (ft_lstfind_env(&mini->env, "USER"))
	// 	init_no_env(mini); TODO: handler no env (create env)
	init_shell_level(mini);
}

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
	
	init_env(mini, env);
	// print_env(mini); // -> DEBUG
	mini->std_in = dup(STDIN_FILENO);
	if (mini->std_in == -1)
		ft_exit(mini, EXIT_FAILURE, ERR_DUP);
	mini->std_out = dup(STDOUT_FILENO);
	if (mini->std_out == -1)
		ft_exit(mini, EXIT_FAILURE, ERR_DUP);
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