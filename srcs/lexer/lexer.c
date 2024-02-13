/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 10:28:00 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/13 02:22:40 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	create_tokens(t_mini *mini, char **tokens)
{
	int	i;
	int	j;

	(void)mini;
	i = -1;
	while (tokens && tokens[++i])
	{
		j = -1;
		while (tokens[i][++j])
		{
			return ;
		}
			// define_token(mini, tokens[i][j]);
	}
}

int	lexer(t_mini *mini)
{
	char	**tokens;

	(void)mini;
	(void)tokens;
	if (!is_valid_syntax(mini->prompt))
		return (mini->exec_status = EXEC_SYNTAX_ERROR, 0);
	tokens = ft_split(mini->prompt, " \n\t\f\r\v");
	if (!tokens)
		return (mini->exec_status = EXEC_FAILURE, 0); // TODO: handle error
	print_2d_array(tokens);
	create_tokens(mini, tokens);
	return (1);
}
