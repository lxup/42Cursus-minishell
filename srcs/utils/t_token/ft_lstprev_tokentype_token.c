/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprev_tokentype_token.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 18:52:12 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/16 09:58:01 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*ft_lstprev_tokentype_token(t_token *current, t_token_type type)
{
	if (!current || !current->prev)
		return (NULL);
	current = current->prev;
	while (current && current->type != TOKEN_PIPE)
	{
		if (current->type == type)
			return (current);
		current = current->prev;
	}
	return (NULL);
}
