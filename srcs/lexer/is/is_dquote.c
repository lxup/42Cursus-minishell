/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_dquote.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 18:01:00 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/16 22:16:15 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_dquote(char *prompt, char *quote, t_token_type *type)
{
	if (!prompt)
		return (0);
	if (prompt[0] == '\"' &&  (*quote == '\"' || !*quote))
	{
		if (*quote == '\"')
			*quote = 0;
		else
			*quote = prompt[0];
		*type = TOKEN_DQUOTE;
		return (1);
	}
	return (0);
}
