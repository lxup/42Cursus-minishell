/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_err_unclose_char.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 10:14:31 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/21 11:13:36 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	p_err_unclose_char(t_mini *mini, char c)
{
	mini->exec_status = EXEC_SYNTAX_ERROR;
	return (ft_dprintf("%s%s `%c'\n", SHELL, ERR_UNCLOSE_CHAR, c));
}
