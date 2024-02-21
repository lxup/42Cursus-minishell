/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_dgreater.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 17:56:31 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/21 12:03:29 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_dgreater(char *prompt, t_token_type *type)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (prompt && prompt[i] == '>')
	{
		count++;
		i++;
	}
	if (count == 2)
	{
		*type = TOKEN_DGREATER;
		return (1);
	}
	return (0);
}
