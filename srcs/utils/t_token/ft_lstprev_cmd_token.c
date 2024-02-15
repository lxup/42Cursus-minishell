/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprev_cmd_token.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 18:52:12 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/15 19:07:24 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*ft_lstprev_cmd_token(t_token *current)
{
	if (!current || !current->prev)
		return (NULL);
	current = current->prev;
	while (current && current->type != TOKEN_PIPE)
	{
		if (current->type == TOKEN_CMD)
			return (current);
		current = current->prev;
	}
	return (NULL);
}
