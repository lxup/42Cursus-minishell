/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnext_tokentype_token.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 20:05:26 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/16 07:28:53 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*ft_lstnext_tokentype_token(t_token *lst, t_token_type type, \
	t_token *current)
{	
	if (!lst)
		return (NULL);
	if (current == NULL)
	{
		while (lst)
		{
			if (lst->type == type)
				return (lst);
			lst = lst->next;
		}
	}
	else
	{
		while (lst && lst != current)
			lst = lst->next;
		if (lst == current)
			lst = lst->next;
		while (lst)
		{
			if (lst->type == type)
				return (lst);
			lst = lst->next;
		}
	}
	return (NULL);
}
