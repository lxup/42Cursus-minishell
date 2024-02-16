/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnext_cmd_token.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 18:52:12 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/16 06:01:53 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*ft_lstnext_cmd_token(t_token *current)
{
	if (!current || !current->next)
		return (NULL);
	current = current->next;
	while (current && current->type != TOKEN_PIPE)
	{
		if (current->type == TOKEN_CMD)
			return (current);
		current = current->next;
	}
	return (NULL);
}
