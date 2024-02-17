/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_quote.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 17:59:37 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/17 11:29:37 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_quote(char *prompt, char *quote, t_token_type *type)
{
	if (!prompt)
		return (0);
	if (prompt[0] == '\'' && (*quote == '\'' || !*quote))
	{
		if (*quote == '\'')
			*quote = 0;
		else
			*quote = prompt[0];
		*type = TOKEN_DQUOTE;
		return (1);
	}
	return (0);
}
