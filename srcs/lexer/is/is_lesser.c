/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_lesser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 17:57:04 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/21 12:03:56 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_lesser(char *prompt, t_token_type *type)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (prompt && prompt[i] == '<')
	{
		count++;
		i++;
	}
	if (count == 1)
	{
		*type = TOKEN_LESSER;
		return (1);
	}
	return (0);
}
