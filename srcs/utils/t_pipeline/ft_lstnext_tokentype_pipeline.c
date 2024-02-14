/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnext_tokentype_pipeline.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 20:01:53 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/14 20:25:47 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*ft_lstnext_tokentype_pipeline(t_pipeline *lst, \
	t_token_type type, t_token *current)
{
	t_token	*tmp;

	while (lst)
	{
		tmp = ft_lstnext_tokentype_token(lst->tokens, type, current);
		if (tmp)
			return (tmp);
		lst = lst->next;
	}
	return (NULL);
}
