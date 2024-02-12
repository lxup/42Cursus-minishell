/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emehdaou <emehdaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 23:57:50 by emehdaou          #+#    #+#             */
/*   Updated: 2023/12/05 19:46:16 by emehdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*current;
	int		i;

	i = 0;
	current = lst;
	while (current)
	{
		i++;
		current = current->next;
	}
	return (i);
}
