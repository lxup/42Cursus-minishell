/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 10:28:00 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/14 11:55:51 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	define_token_type(char *prompt, t_token_type *type, int *i)
{
if (is_greater(prompt + *i))
		return (*type = TOKEN_GREATER, *i += 1, 1);
	else if (is_dgreater(prompt + *i))
		return (*type = TOKEN_DGREATER, *i += 2, 1);
	else if (is_lesser(prompt + *i))
		return (*type = TOKEN_LESSER, *i += 1, 1);
	else if (is_dlesser(prompt + *i))
		return (*type = TOKEN_DLESSER, *i += 2, 1);
	else if (is_word(prompt, i))
		return (*type = TOKEN_WORD, 1);
	return (0);
}

char	*token_clear_quote(char *prompt, int end, int start)
{
	char	*token;
	int		start_word;
	int		end_word;
	char	quote;

	start_word = start;
	end_word = end;
	if (prompt[start_word] == '\'' || prompt[start_word] == '\"')
		quote = prompt[start_word];
	while (start_word < end_word \
		&& (prompt[start_word] == quote && prompt[end_word - 1] == quote))
	{
		start_word++;
		end_word--;
	}
	token = ft_strndup(prompt + start_word, end_word - start_word, 0);
	if (!token)
		return (NULL);
	return (token);
}

void	create_token_for_pipeline(t_pipeline *pipeline)
{
	t_token_type	type;
	int				i;
	int				start;

	i = 0;
	while (pipeline->prompt && pipeline->prompt[i])
	{
		type = TOKEN_NOT_SET;
		while (pipeline->prompt[i] && ft_iswhitespace(pipeline->prompt[i]))
			i++;
		start = i;
		define_token_type(pipeline->prompt, &type, &i);
		if (type == TOKEN_NOT_SET)
			printf("Error: Token not set\n");
			// break ;
		ft_lstadd_back_token(&pipeline->tokens, \
			ft_lstnew_token(ft_strndup(pipeline->prompt + start, i - start, 0), type));
		// ft_lstadd_back_token(&pipeline->tokens, \
		// 	ft_lstnew_token(token_clear_quote(pipeline->prompt, \
		// 		i, start), type));
	}
}

int	create_tokens(t_mini *mini)
{
	t_pipeline	*tmp;
	
	tmp = mini->pipeline;
	while (tmp)
	{
		create_token_for_pipeline(tmp);
		adjust_token_type(tmp->tokens);
		printf("Pipeline: %s\n", tmp->prompt);
		ft_lstprint_token(tmp->tokens);
		tmp = tmp->next;
	}
	return (1);
}

int	create_pipeline(t_mini *mini)
{
	int		i;
	char	**pipelines;

	pipelines = ft_split(mini->prompt, "|");
	if (!pipelines)
		return (mini->exec_status = EXEC_FAILURE, 0);
	i = -1;
	while (pipelines[++i])
	{
		if (ft_strwhitespace(pipelines[i]))
			return (mini->exec_status = EXEC_SYNTAX_ERROR, 0);
		ft_lstadd_back_pipeline(&mini->pipeline, ft_lstnew_pipeline(pipelines[i]));
	}
	ft_free_array((void **)pipelines);
	return (1);
}

int	lexer(t_mini *mini)
{
	printf("Step->lexer\n");
	if (!is_valid_syntax(mini->prompt))
		return (mini->exec_status = EXEC_SYNTAX_ERROR, 0);
	ft_lstclear_pipeline(&mini->pipeline);
	if (!create_pipeline(mini))
		return (0);
	if (!create_tokens(mini))
		return (mini->exec_status = EXEC_SYNTAX_ERROR, 0);
	return (1);
}
