/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 10:28:00 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/13 21:24:24 by lquehec          ###   ########.fr       */
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

	start_word = start;
	while (prompt[start_word] == '\'' || prompt[start_word] == '\"')
		start_word++;
	end_word = end;
	while (prompt[end_word - 1] == '\'' || prompt[end_word - 1] == '\"')
		end_word--;
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
			break ;
		ft_lstadd_back_token(&pipeline->tokens, \
			ft_lstnew_token(token_clear_quote(pipeline->prompt, \
				i, start), type));
	}
}

void	adjust_token_type(t_token *tokens)
{
	t_token	*tmp;

	tmp = tokens;
	while (tmp)
	{
		if (tmp->type == TOKEN_WORD)
		{
			if (tmp->prev != tmp && (tmp->prev->type == TOKEN_GREATER \
				|| tmp->prev->type == TOKEN_DGREATER \
				|| tmp->prev->type == TOKEN_LESSER \
				|| tmp->prev->type == TOKEN_DLESSER))
				tmp->type = TOKEN_FILE;
			else if (tmp == tokens || tmp->prev->type == TOKEN_FILE)
				tmp->type = TOKEN_CMD;
			else if (tmp->prev != tmp && (tmp->prev->type == TOKEN_CMD \
				|| tmp->prev->type == TOKEN_ARGS))
				tmp->type = TOKEN_ARGS;
		}
		tmp = tmp->next;
		if (tmp == tokens)
			break ;
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
		ft_lstprint_token(tmp->tokens);
		tmp = tmp->next;
		if (tmp == mini->pipeline)
			break ;
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

	if (!is_valid_syntax(mini->prompt))
		return (mini->exec_status = EXEC_SYNTAX_ERROR, 0);
	ft_lstclear_pipeline(&mini->pipeline);
	if (!create_pipeline(mini))
		return (0);
	if (!create_tokens(mini))
		return (mini->exec_status = EXEC_SYNTAX_ERROR, 0);
	return (1);
}
