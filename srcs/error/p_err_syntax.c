/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_err_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 10:14:31 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/16 10:35:28 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	p_err_syntax(t_mini *mini, char c)
{
	mini->exec_status = EXEC_SYNTAX_ERROR;
	return (ft_dprintf("%s"C_RED"%s `%c'\n"C_END, SHELL, ERR_SYNTAX, c), TRUE);
}
