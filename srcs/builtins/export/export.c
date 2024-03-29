/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 20:03:07 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/23 21:32:38 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	export_builtin(t_mini *mini, t_pipeline *pipeline)
{
	g_status = 0;
	if (pipeline->args[1] == NULL)
		export_print(mini);
	else if (pipeline->args[1] != NULL
		&& ft_lstsize_pipeline(mini->pipeline) == 1)
		export_add(mini, pipeline);
}
