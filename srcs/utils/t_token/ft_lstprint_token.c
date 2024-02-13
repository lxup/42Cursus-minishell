/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint_token.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 17:17:10 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/13 19:42:14 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_lstprint_token(t_token *token)
{
	t_token	*tmp;

	tmp = token;
	while (tmp)
	{
		printf("value: %s\n", tmp->value);
		if (tmp->type == TOKEN_WORD)
			printf("type: TOKEN_WORD\n");
		else if (tmp->type == TOKEN_GREATER)
			printf("type: TOKEN_GREATER\n");
		else if (tmp->type == TOKEN_DGREATER)
			printf("type: TOKEN_DGREATER\n");
		else if (tmp->type == TOKEN_LESSER)
			printf("type: TOKEN_LESSER\n");
		else if (tmp->type == TOKEN_DLESSER)
			printf("type: TOKEN_DLESSER\n");
		else if (tmp->type == TOKEN_ARGS)
			printf("type: TOKEN_ARGS\n");
		else if (tmp->type == TOKEN_CMD)
			printf("type: TOKEN_CMD\n");
		else if (tmp->type == TOKEN_FILE)
			printf("type: TOKEN_FILE\n");
		else if (tmp->type == TOKEN_UNKNOW)
			printf("type: TOKEN_UNKNOW\n");
		else if (tmp->type == TOKEN_NOT_SET)
			printf("type: TOKEN_NOT_SET\n");
		else
			printf("type: UNKNOW\n");
		tmp = tmp->next;
		if (tmp == token)
			break ;
	}
}
