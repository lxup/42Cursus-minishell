/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_token.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 13:42:05 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/15 10:50:29 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*ft_lstnew_token(char *value, t_token_type type)
{
	t_token	*new_lst;

	new_lst = (t_token *)malloc(sizeof(t_token));
	if (!new_lst)
		return (NULL);
	new_lst->value = value;
	new_lst->type = type;
	new_lst->file = NULL;
	new_lst->next = NULL;
	new_lst->prev = NULL;
	return (new_lst);
}
