/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_pipeline.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:12:34 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/13 15:13:34 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_lstclear_pipeline(t_pipeline **lst)
{
	t_pipeline	*start;
	t_pipeline	*current;
	t_pipeline	*tmp;

	start = *lst;
	current = start;
	tmp = NULL;
	while (current)
	{
		if (current->next)
			tmp = current->next;
		else
			tmp = NULL;
		if (current->tokens)
			ft_lstclear_token(&current->tokens);
		if (current->prompt)
			free(current->prompt);
		free(current);
		current = tmp;
		if (current == start)
			break ;
	}
	*lst = NULL;
}