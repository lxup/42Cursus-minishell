/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 10:56:17 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/19 19:16:18 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	has_cmd(t_mini *mini)
{
	t_pipeline	*pipeline;
	t_token		*token;

	pipeline = mini->pipeline;
	token = pipeline->tokens;
	if (!token)
		return (0);
	if (token->type == TOKEN_CMD)
		return (1);
	while (pipeline)
	{
		if (ft_lstnext_cmd_token(pipeline->tokens))
			return (1);
		pipeline = pipeline->next;
	}
	return (0);
}

int	create_env(t_mini *mini)
{
	if (mini->env_array)
		free(mini->env_array);
	mini->env_array = env_to_str(mini->env);
	if (!mini->env_array)
		return (ft_exit(mini));
	return (1);
}

int	executor(t_mini *mini)
{
	if (mini->pipeline)
		ft_lstclear_pipeline(&mini->pipeline);
	if (!create_env(mini))
		return (0);
	if (!create_pipeline(mini))
		return (0);
	if (mini->tokens)
		ft_lstclear_token(&mini->tokens);
	handle_heredoc(mini);
	if (mini->exec_only_heredoc <= -1 && has_cmd(mini))
	{
		if (!mini->pipeline->next && is_builtin(mini, mini->pipeline))
			return (1);
		pipex(mini);
	}
	return (1);
}
