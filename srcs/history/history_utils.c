/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 11:43:29 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/12 10:55:50 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_new_prompt(t_mini *mini)
{
	if (mini->prev_prompt == NULL)
		return (1);
	if (ft_strcmp(mini->prompt, mini->prev_prompt) != 0)
		return (1);
	return (0);
}

int	is_only_space(char *str)
{
	int	i;

	i = -1;
	while (str && str[++i])
	{
		if (str[i] != ' ')
			return (0);
	}
	return (1);
}
