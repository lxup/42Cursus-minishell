/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_pipeline.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 13:40:57 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/14 10:24:12 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_lstadd_back_pipeline(t_pipeline **lst, t_pipeline *new)
{
	t_pipeline	*last;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast_pipeline(*lst);
	last->next = new;
	new->prev = last;
	// new->next = *lst;
	// (*lst)->prev = new;
}
