/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_greater.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 17:55:55 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/21 12:13:40 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_greater(char *prompt, t_token_type *type)
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
	if (count == 1)
	{
		*type = TOKEN_GREATER;
		return (1);
	}
	return (0);
}
