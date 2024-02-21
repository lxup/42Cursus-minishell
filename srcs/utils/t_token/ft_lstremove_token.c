/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstremove_token.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 19:49:03 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/21 11:44:42 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	remove_token(t_token *current, t_token *token)
{
	t_token	*next;
	t_token	*prev;

	next = NULL;
	prev = NULL;
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
	return (0);
}

int	ft_lstremove_token(t_token **lst, t_token *token)
{
	t_token	*current;
	t_token	*next;

	current = *lst;
	if (current == token)
	{
		next = current->next;
		if (next)
			next->prev = NULL;
		*lst = current->next;
		if (current->value)
			free(current->value);
		free(current);
		return (1);
	}
	while (current)
	{
		if (remove_token(current, token))
			return (1);
		current = current->next;
	}
	return (0);
}
