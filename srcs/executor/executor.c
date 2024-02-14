/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 10:56:17 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/14 21:40:10 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	executor(t_mini *mini)
{
	(void)mini;
	printf("Executor\n");   
	print_pipeline(mini);                       
	// TODO: Check file ?
	// TODO: Check if command is built-in
	handle_heredoc(mini);
	
	return (0);
}
