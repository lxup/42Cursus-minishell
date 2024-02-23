/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_tilde.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 12:30:34 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/23 12:33:33 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_tilde(char *prompt, int *i)
{
	if (!prompt)
		return (0);
	if (!i)
		return (prompt[0] == '~');
	if (prompt[*i] == '~')
		return (*i = *i + 1, 1);
	return (0);
}
