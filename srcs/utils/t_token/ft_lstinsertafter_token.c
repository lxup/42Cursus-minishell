/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstinsertafter_token.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 12:51:14 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/22 14:21:07 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	update_index_next(t_token *new)
{
	t_token	*tmp;

	tmp = new->next;
	while (tmp)
	{
		tmp->index++;
		tmp = tmp->next;
	}
	return (1);
}

int	ft_lstinsertafter_token(t_token **lst, t_token *target, t_token *new)
{
	t_token	*prev;
	t_token	*next;

	if (!lst || !new)
		return (0);
	if (!*lst)
	{
		*lst = new;
		return (1);
	}
	prev = target;
	next = target->next;
	if (next)
		next->prev = new;
	new->next = next;
	new->prev = prev;
	prev->next = new;
	return(update_index_next(new));
}
