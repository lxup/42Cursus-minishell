/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 10:28:00 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/22 18:49:09 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// static int	edges_cases(t_mini *mini)
// {
// 	char	*trimmed_prompt;
// 	int		ret;

// 	ret = 1;
// 	trimmed_prompt = ft_strtrim(mini->prompt, " \n\t\v\f\r");
// 	if (!trimmed_prompt)
// 		return (ft_exit(mini), 0);
// 	if (ft_strwhitespace(trimmed_prompt))
// 		return (0);
// 	else if (!ft_strcmp(trimmed_prompt, ":"))
// 		ret = 0;
// 	else if (!ft_strcmp(trimmed_prompt, "!!"))
// 	{
// 		free(mini->prompt);
// 		mini->prompt = ft_strdup(mini->prev_prompt);
// 		if (!mini->prompt)
// 			return (free(trimmed_prompt), \
// 				ft_exit(mini), 0);
// 	}
// 	free(trimmed_prompt);
// 	return (ret);
// }

int	lexer(t_mini *mini)
{
	// if (!edges_cases(mini))
	// 	return (0);
	if (mini->tokens)
		ft_lstclear_token(&mini->tokens);
	if (!create_tokens(mini))
		return (0);
	if (!expander_env_var(mini))
		return (0);
	return (1);
}
