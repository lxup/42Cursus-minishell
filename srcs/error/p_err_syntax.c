/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_err_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 10:14:31 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/18 12:33:51 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	p_err_syntax(t_mini *mini, char c)
{
	mini->exec_status = EXEC_SYNTAX_ERROR;
	if (c == '\n')
		return (ft_dprintf("%s%s `%s'\n", SHELL, ERR_SYNTAX, "newline"));
	return (ft_dprintf("%s%s `%c'\n", SHELL, ERR_SYNTAX, c));
}
