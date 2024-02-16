/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnext_tokentype_pipeline.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 20:01:53 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/16 07:23:19 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*ft_lstnext_tokentype_pipeline(t_pipeline *lst, \
	t_token_type type, t_token *current, t_pipeline **current_pipeline)
{
	t_token	*tmp;

	if (*current_pipeline == NULL)
		*current_pipeline = lst;
	while (*current_pipeline)
	{
		tmp = ft_lstnext_tokentype_token((*current_pipeline)->tokens, type, current);
		if (tmp)
			return (tmp);
		*current_pipeline = (*current_pipeline)->next;
	}
	return (NULL);
}
