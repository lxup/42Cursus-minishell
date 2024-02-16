/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emehdaou <emehdaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 18:11:58 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/16 18:39:06 by emehdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	get_shell_prompt(t_mini *mini)
{
	char	*tmp;
	
	mini->exec_status = EXEC_SUCCESS;
	if (mini->shell_prompt.prompt != NULL)
		free(mini->shell_prompt.prompt);
	mini->shell_prompt.prompt_size = 0;
	build_left_side(mini, get_os(), get_path(mini));
	tmp = mini->shell_prompt.prompt;
	mini->shell_prompt.prompt = ft_strjoin(mini->shell_prompt.prompt, C_GRAY "\n╰─ " C_WHITE, 0);
	free(tmp);
	mini->shell_prompt.prompt_size += ft_strlen("\n╰─ ");
}