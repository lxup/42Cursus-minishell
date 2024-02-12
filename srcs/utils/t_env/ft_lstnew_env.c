/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 13:42:05 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/11 10:31:56 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*ft_lstnew_env(char *name, char *value)
{
	t_env	*new_lst;

	new_lst = (t_env *)malloc(sizeof(t_env));
	if (!new_lst)
		return (NULL);
	new_lst->name = ft_strdup(name);
	if (!new_lst->name)
		return (free(new_lst), NULL);
	if (!value)
		new_lst->value = ft_strdup("");
	else
		new_lst->value = ft_strdup(value);
	if (!new_lst->value)
		return (free(new_lst->name), free(new_lst), NULL);
	new_lst->next = new_lst;
	new_lst->prev = new_lst;
	return (new_lst);
}
