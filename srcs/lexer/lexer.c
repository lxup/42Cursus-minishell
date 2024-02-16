/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 10:28:00 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/16 11:14:05 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

int	create_token_for_pipeline(t_mini *mini)
{
	t_token_type	type;
	int				i;
	int				start;

	i = 0;
	while (mini->prompt && mini->prompt[i])
	{
		type = TOKEN_NOT_SET;
		while (mini->prompt[i] && ft_iswhitespace(mini->prompt[i]))
			i++;
		if (!mini->prompt[i])
			break ;
		start = i;
		if (!define_token_type(mini->prompt, &type, &i))
			return (p_err_syntax(mini, mini->prompt[i]), 0);
		ft_lstadd_back_token(&mini->tokens, \
			ft_lstnew_token(ft_strndup(mini->prompt + start, \
				i - start, 0), type));
	}
	return (1);
}

// int	create_tokens(t_mini *mini)
// {
// 	t_pipeline	*tmp;

// 	tmp = mini->pipeline;
// 	while (tmp)
// 	{
// 		if (!create_token_for_pipeline(tmp))
// 			return (0);
// 		adjust_token_type(tmp->tokens);
// 		tmp = tmp->next;
// 	}
// 	return (1);
// }

int	create_tokens(t_mini *mini)
{
	if (!create_token_for_pipeline(mini))
		return (0);
	adjust_token_type(mini->tokens);
	return (1);
}

// int	create_pipeline(t_mini *mini)
// {
// 	int		i;
// 	char	**pipelines;
// 	char	*tmp;

// 	pipelines = ft_split(mini->prompt, "|");
// 	if (!pipelines)
// 		return (mini->exec_status = EXEC_FAILURE, 0);
// 	i = -1;
// 	while (pipelines[++i])
// 	{
// 		if (ft_strwhitespace(pipelines[i]))
// 			return (mini->exec_status = EXEC_SYNTAX_ERROR, 0);
// 		tmp = ft_strtrim(pipelines[i], " \n\t\v\f\r");
// 		if (!tmp)
// 			return (mini->exec_status = EXEC_FAILURE, 0);
// 		ft_lstadd_back_pipeline(&mini->pipeline, \
// 			ft_lstnew_pipeline(tmp));
// 		free(tmp);
// 	}
// 	ft_free_array((void **)pipelines);
// 	return (1);
// }

int	lexer(t_mini *mini)
{
	if (ft_strwhitespace(mini->prompt))
		return (0);
	if (!is_valid_syntax(mini, mini->prompt))
		return (0);
		print_tokens(mini->tokens);
	ft_lstclear_token(&mini->tokens);
	if (!create_tokens(mini))
		return (0);
	return (1);
}
