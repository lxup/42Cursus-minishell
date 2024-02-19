/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 13:39:06 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/19 11:40:30 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_2d_strlen(char **array)
{
	int	i;

	i = 0;
	while (array && array[i])
		i++;
	return (i);
}

void	ft_free_array(void **array)
{
	int	i;

	if (!array)
		return ;
	i = -1;
	while (array && array[++i])
		free(array[i]);
	free(array);
}
