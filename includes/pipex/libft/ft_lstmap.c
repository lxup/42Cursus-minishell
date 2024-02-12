/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emehdaou <emehdaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 03:01:57 by emehdaou          #+#    #+#             */
/*   Updated: 2023/12/05 16:59:53 by emehdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, int (*f)(int), void (*del)(int))
{
	t_list	*head;
	t_list	*tmp;

	if (!lst || !f || !del)
		return (NULL);
	head = ft_lstnew((f)(lst->content));
	lst = lst->next;
	if (!head)
		return (NULL);
	while (lst)
	{
		tmp = ft_lstnew((f)(lst->content));
		if (!tmp)
		{
			ft_lstclear(&tmp, del);
			return (NULL);
		}
		ft_lstadd_back(&head, tmp);
		lst = lst->next;
	}
	return (head);
}
