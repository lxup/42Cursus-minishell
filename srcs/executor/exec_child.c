/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_child.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 23:03:47 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/16 05:57:36 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_child(t_mini *mini, t_pipeline *cur_pipeline)
{
	(void)mini;
	(void)cur_pipeline;
	exit(0);
}

void	exec_child_builtins(t_mini *mini, t_pipeline *cur_pipeline)
{
	(void)mini;
	(void)cur_pipeline;
	exit(0);
}