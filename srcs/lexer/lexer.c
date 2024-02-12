/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 10:28:00 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/12 19:49:58 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	lexer(t_mini *mini)
{
	char	**token;

	(void)mini;
	(void)token;
	if (!is_valid_syntax(mini->prompt))
		return (mini->exec_status = EXEC_SYNTAX_ERROR, 0);
	token = ft_split(mini->prompt, " \n\t\f\r\v");
	print_2d_array(token);
	return (1);
}
