/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcount_tokentype_pipeline.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 19:40:34 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/14 19:40:50 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_lstcount_tokentype_pipeline(t_pipeline *lst, t_token_type type)
{
	int		count;

	count = 0;
	while (lst)
	{
		count += ft_lstcount_type_token(lst->tokens, type);
		lst = lst->next;
	}
	return (count);
}
