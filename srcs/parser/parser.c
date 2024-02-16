/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 10:44:39 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/16 23:05:50 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	parser(t_mini *mini)
{
	if (!parser_fix_quote(mini))
		return (0);
	if (!adjust_token_type(mini->tokens))
		return (0);
	if (!parser_check_token_type(mini))
		return (0);
	if (!parser_check_order(mini))
		return (0);
	return (1);
}
