/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnext_tokentype_token.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 20:05:26 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/14 20:25:53 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*ft_lstnext_tokentype_token(t_token *lst, t_token_type type, \
	t_token *current)
{
	if (!lst)
		return (NULL);
	while (lst)
	{
		if (lst == current)
			return (ft_lstnext_tokentype_token(lst->next, type, current));
		if (lst->type == type)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}
