/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 10:56:17 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/20 10:02:55 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_token	*get_cmd(t_mini *mini, t_pipeline *pipeline)
{
	t_pipeline	*cur_pipeline;
	t_token		*token;

	token = pipeline->tokens;
	if (!token)
		return (NULL);
	if (token->type == TOKEN_CMD)
		return (token);
	cur_pipeline = mini->pipeline;
	while (cur_pipeline)
	{
		token = ft_lstnext_cmd_token(pipeline->tokens);
		if (token)
			return (token);
		cur_pipeline = cur_pipeline->next;
	}
	return (NULL);
}

static int	not_in_fork(t_mini *mini, t_pipeline *pipeline)
{
	t_token	*token;

	token = get_cmd(mini, pipeline);
	if (!token)
		return (0);
	else if (ft_strcmp(token->value, "cd") == 0)
		return (1);
	else if (ft_strcmp(token->value, "exit") == 0)
		return (1);
	return (0);
}

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
	{
		free(mini->env_array);
		mini->env_array = NULL;
	}
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
	if (!handle_heredoc(mini))
		return (0);
	if (mini->exec_only_heredoc <= -1)
	{
		if (!mini->pipeline->next && not_in_fork(mini, mini->pipeline) \
			&& is_builtin(mini, mini->pipeline))
			return (1);
		pipex(mini);
	}
	return (1);
}
