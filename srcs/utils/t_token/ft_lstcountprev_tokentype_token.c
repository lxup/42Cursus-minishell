/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcountprev_tokentype_token.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 18:52:12 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/16 10:05:34 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_lstcountprev_tokentype_token(t_token *current, t_token_type type)
{
	int	count;

	count = 0;
	if (!current || !current->prev)
		return (count);
	current = current->prev;
	while (current)
	{
		if (current->type == type)
			count++;
		current = current->prev;
	}
	return (count);
}
