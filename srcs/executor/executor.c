/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 10:56:17 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/17 14:58:08 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	executor(t_mini *mini)
{
	if (mini->pipeline)
		ft_lstclear_pipeline(&mini->pipeline);
	if (!create_pipeline(mini))
		return (0); // TODO handle error
	if (mini->tokens)
		ft_lstclear_token(&mini->tokens);
	handle_heredoc(mini);
	if (mini->exec_only_heredoc <= -1)
		pipex(mini);
	return (1);
}
