/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcount_type_token.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 19:38:27 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/14 19:38:55 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_lstcount_type_token(t_token *lst, t_token_type type)
{
	int		count;

	count = 0;
	while (lst)
	{
		if (lst->type == type)
			count++;
		lst = lst->next;
	}
	return (count);
}
