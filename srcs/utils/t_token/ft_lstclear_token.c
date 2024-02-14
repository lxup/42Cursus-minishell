/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_token.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:12:34 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/14 10:18:30 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_lstclear_token(t_token **lst)
{
	t_token	*start;
	t_token	*current;
	t_token	*tmp;

	start = *lst;
	current = start;
	tmp = NULL;
	while (current)
	{
		if (current->next)
			tmp = current->next;
		else
			tmp = NULL;
		if (current->value)
			free(current->value);
		free(current);
		current = tmp;
		// if (current == start)
		// 	break ;
	}
	*lst = NULL;
}
