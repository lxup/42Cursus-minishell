/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 10:28:00 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/13 15:37:22 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	define_tokens(t_mini *mini)
{
	t_pipeline	*curr_pipeline;
	t_token		*curr_token;
	int			i;

	(void)mini;
	(void)curr_pipeline;
	(void)curr_token;
	(void)i;
	curr_pipeline = mini->pipeline;
	while (curr_pipeline)
	{
		curr_token = curr_pipeline->tokens;
		// while (curr_token)
		// {
		// 	if (ft_strcmp)
		// }
		curr_pipeline = curr_pipeline->next;
		if (curr_pipeline == mini->pipeline)
			break ;
	}
	return (1);
}

int	create_tokens(t_mini *mini)
{
	t_pipeline	*tmp;
	int			i;
	char		**tokens;

	tmp = mini->pipeline;
	while (tmp)
	{
		tokens = ft_split_sep(tmp->prompt, " \n\t\f\r\v", "<>");
		if (!tokens)
			return (0);
		i = -1;
		print_2d_array(tokens);
		while (tokens[++i])
			ft_lstadd_back_token(&tmp->tokens, ft_lstnew_token(tokens[i], TOKEN_NOT_SET));
		ft_free_array((void **)tokens);
		tmp = tmp->next;
		if (tmp == mini->pipeline)
			break ;
	}
	return (define_tokens(mini));
}

int	create_pipeline(t_mini *mini)
{
	int		i;
	char	**pipelines;

	pipelines = ft_split(mini->prompt, "|");
	if (!pipelines)
		return (0);
	i = -1;
	while (pipelines[++i])
		ft_lstadd_back_pipeline(&mini->pipeline, ft_lstnew_pipeline(pipelines[i]));
	ft_free_array((void **)pipelines);
	return (1);
}


int	lexer(t_mini *mini)
{

	if (!is_valid_syntax(mini->prompt))
		return (mini->exec_status = EXEC_SYNTAX_ERROR, 0);
	ft_lstclear_pipeline(&mini->pipeline);
	if (!create_pipeline(mini))
		return (mini->exec_status = EXEC_FAILURE, 0);
	if (!create_tokens(mini))
		return (mini->exec_status = EXEC_FAILURE, 0);
	// tokens = ft_split(mini->prompt, " \n\t\f\r\v");
	// if (!tokens)
	// 	return (mini->exec_status = EXEC_FAILURE, 0); // TODO: handle error
	// print_2d_array(tokens);
	// if (!create_tokens(mini, tokens))
	// 	return (ft_free_array((void **)tokens), 0);
	return (1);
}
