/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 18:11:58 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/24 12:32:52 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	get_shell_prompt(t_mini *mini)
{
	if (mini->shell_prompt.prompt != NULL)
		free(mini->shell_prompt.prompt);
	mini->shell_prompt.prompt_size = 0;
	build_left_side(mini, get_os(), get_path(mini));
	if (mini->shell_prompt.prompt == NULL)
		ft_exit(mini);
	if (ft_strcmp(OS, "linux") == 0)
		mini->shell_prompt.prompt_size++;
}

	// build_separator(mini);
	// if (mini->shell_prompt.prompt == NULL)
	// 	ft_exit(mini);