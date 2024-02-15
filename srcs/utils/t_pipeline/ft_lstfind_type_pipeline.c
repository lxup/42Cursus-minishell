/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfind_pipeline.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:33:05 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/15 17:58:06 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_lstfind_type_pipeline(t_pipeline *pipeline, t_token_type type)
{
	t_token	*tmp;

	if (!pipeline || !pipeline->tokens)
		return (NULL);
	tmp = pipeline->tokens;
	while (tmp)
	{
		if (tmp->type == type)
			return (tmp->value);
		tmp = tmp->next;
	}
	return (NULL);
}
