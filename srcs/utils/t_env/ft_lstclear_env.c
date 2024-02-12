/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_env.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:12:34 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/11 10:31:42 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_lstclear_env(t_env **lst)
{
	t_env	*start;
	t_env	*current;
	t_env	*tmp;

	start = *lst;
	current = start;
	tmp = NULL;
	while (current)
	{
		if (current->next)
			tmp = current->next;
		else
			tmp = NULL;
		if (current->name)
			free(current->name);
		if (current->value)
			free(current->value);
		free(current);
		current = tmp;
		if (current == start)
			break ;
	}
	*lst = NULL;
}
