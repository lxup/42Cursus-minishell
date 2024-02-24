/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:40:59 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/23 21:33:13 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_valid_identifier(const char *str)
{
	int	i;

	i = 0;
	if (!ft_isalpha(str[i]) && str[i] != '_')
		return (0);
	i++;
	while (str[i] != '\0')
	{
		if (!ft_isalnum(str[i]) && str[i] != '_')
			return (0);
		i++;
	}
	return (1);
}

int	export_is_valid_env(t_pipeline *pipeline, char **env)
{
	int	i;

	(void)pipeline;
	if (ft_2d_strlen(env) == 0 || ft_2d_strlen(env) > 2)
		return (0);
	if (!is_valid_identifier(env[0]))
		return (0);
	i = 0;
	while (env[1] && env[1][i])
	{
		if (env[1][i] == '=')
			return (0);
		i++;
	}
	return (1);
}
