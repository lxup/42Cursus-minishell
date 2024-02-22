/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_err_prohibited_char.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 10:14:31 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/22 12:32:22 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	p_err_prohibited_char(t_mini *mini, char c)
{
	(void)mini;
	g_status = EXEC_SYNTAX_ERROR;
	return (ft_dprintf("%s%s `%c'\n", SHELL, ERR_PROHIBIDED_CHAR, c));
}
