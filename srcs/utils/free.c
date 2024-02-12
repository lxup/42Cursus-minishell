/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 13:51:22 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/11 10:31:35 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
