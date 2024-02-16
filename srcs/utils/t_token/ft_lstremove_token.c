/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstremove_token.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 19:49:03 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/16 19:52:59 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_lstremove_token(t_token **lst, t_token *token)
{
	t_token	*current;
	t_token	*next;
	t_token	*prev;

	current = *lst;
	next = NULL;
	while (current)
	{
		if (current == token)
		{
			next = current->next;
			prev = current->prev;
			if (prev)
				prev->next = next;
			if (next)
				next->prev = prev;
			if (current->value)
				free(current->value);
			free(current);
			return (1);
		}
		current = current->next;
	}
	return (0);
}
