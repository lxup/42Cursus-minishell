/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 17:57:52 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/16 19:13:30 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_pipe(char *prompt)
{
	return (prompt && prompt[0] == '|');
	// int	i;
	// int	count;

	// i = 0;
	// count = 0;
	// while (prompt && prompt[i] == '|')
	// {
	// 	count++;
	// 	i++;
	// }
	// if (count == 1)
	// 	return (1);
	// return (0);
}
