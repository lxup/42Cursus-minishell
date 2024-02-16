/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 11:51:13 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/16 12:17:51 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_cmd(t_mini *mini, t_pipeline *pipeline)
{
	if (is_builtin(mini,
		ft_lstfind_type_pipeline(pipeline, TOKEN_CMD), pipeline->args))
		return ;
	cmd_binaries(mini, pipeline);
}
