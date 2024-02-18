/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_pipeline.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 12:06:53 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/18 12:13:04 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	count_args(t_token *tokens)
{
	t_token	*cur_token;
	int		i;

	i = 0;
	cur_token = tokens;
	while (cur_token)
	{
		if (cur_token->type == TOKEN_CMD \
			|| cur_token->type == TOKEN_ARGS)
			i++;
		cur_token = cur_token->next;
	}
	return (i);
}

static char	**create_args(t_token *tokens)
{
	char	**args;
	t_token	*cur_token;
	int		i;

	i = count_args(tokens);
	if (i == 0)
		return (NULL);
	args = ft_calloc(i + 1, sizeof(char *));
	if (!args)
		return (NULL); // TODO handle error EXIT !!!!!
	i = 0;
	cur_token = tokens;
	while (cur_token)
	{
		if (cur_token->type == TOKEN_CMD \
			|| cur_token->type == TOKEN_ARGS)
		{
			args[i] = ft_strdup(cur_token->value);
			if (args[i] == NULL)
				return (ft_free_array((void **)args), NULL); // TODO handle error EXIT !!!!!
			i++;
		}
		cur_token = cur_token->next;
	}
	return (args);
}

static int	set_pipeline_args(t_mini *mini)
{
	t_pipeline	*cur_pipeline;

	cur_pipeline = mini->pipeline;
	while (cur_pipeline)
	{
		cur_pipeline->args = create_args(cur_pipeline->tokens);
		cur_pipeline = cur_pipeline->next;
	}
	return (1);
}

int	create_pipeline(t_mini *mini)
{
	t_token		*cur_token;
	t_pipeline	*cur_pipeline;

	cur_token = mini->tokens;
	ft_lstadd_back_pipeline(&mini->pipeline, ft_lstnew_pipeline());
	cur_pipeline = mini->pipeline;
	while (cur_token)
	{
		if (cur_token->type == TOKEN_PIPE)
		{
			ft_lstadd_back_pipeline(&mini->pipeline, ft_lstnew_pipeline());
			cur_pipeline = cur_pipeline->next;
			cur_token = cur_token->next;
			continue ;
		}
		ft_lstadd_back_token(&cur_pipeline->tokens, \
			ft_lstnew_token(ft_strdup(cur_token->value), cur_token->type, cur_token->index));
		cur_token = cur_token->next;
	}
	return (set_pipeline_args(mini));
}
