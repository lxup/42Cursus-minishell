/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstremove_env.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 19:49:03 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/18 15:20:02 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_lstremove_env(t_env **lst, t_env *env)
{
	t_env	*current;
	t_env	*next;
	t_env	*prev;

	current = *lst;
	next = NULL;
	while (current)
	{
		if (current == env)
		{
			next = current->next;
			prev = current->prev;
			if (prev)
				prev->next = next;
			if (next)
				next->prev = prev;
			if (current->value)
				free(current->value);
			if (current->name)
				free(current->name);
			return (free(current), 1);
		}
		current = current->next;
	}
	return (0);
}
