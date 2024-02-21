/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 14:40:29 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/21 12:25:02 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_valid_syntax(t_mini *mini, char *str)
{
	if (ft_count_chars_outside_quotes(str, '(') \
		> ft_count_chars_outside_quotes(str, ')'))
		return (p_err_unclose_char(mini, '('), 0);
	if (ft_count_chars_outside_quotes(str, ')') \
		> ft_count_chars_outside_quotes(str, '('))
		return (p_err_unclose_char(mini, ')'), 0);
	if (ft_count_chars_outside_quotes(str, '\'') % 2 != 0)
		return (p_err_unclose_char(mini, 'a'), 0);
	if (ft_count_chars_outside_quotes(str, '\"') % 2 != 0)
		return (p_err_unclose_char(mini, '\"'), 0);
	if (ft_count_chars_outside_quotes(str, '\\') != 0)
		return (p_err_prohibited_char(mini, '\\'), 0);
	return (1);
}
