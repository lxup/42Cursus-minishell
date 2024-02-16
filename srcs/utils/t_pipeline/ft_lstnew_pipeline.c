/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_pipeline.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 13:42:05 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/16 16:39:35 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_pipeline	*ft_lstnew_pipeline(void)
{
	t_pipeline	*new_lst;

	new_lst = (t_pipeline *)malloc(sizeof(t_pipeline));
	if (!new_lst)
		return (NULL);
	new_lst->tokens = NULL;
	new_lst->pid = 0;
	// new_lst->redir_in = 0;
	// new_lst->redir_out = 0;
	// new_lst->redir_append = 0;
	new_lst->heredoc = NULL;
	new_lst->args = NULL;
	new_lst->next = NULL;
	new_lst->prev = NULL;
	return (new_lst);
}
