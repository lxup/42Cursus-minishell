/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 13:42:05 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/22 21:51:45 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*ft_lstnew_env(char *name, char *value, int equal_sign)
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
	new_lst->equal_sign = equal_sign;
	new_lst->next = NULL;
	new_lst->prev = NULL;
	return (new_lst);
}
