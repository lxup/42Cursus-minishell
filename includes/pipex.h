/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emehdaou <emehdaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 15:59:40 by emehdaou          #+#    #+#             */
/*   Updated: 2024/02/16 18:36:34 by emehdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#ifndef PIPEX_H
# define PIPEX_H

char	*get_path_pipex(t_mini *mini, char *cmd);
void		ft_waitpid(t_pipeline *pipeline);
void		heredoc(char *delim);
void		ft_process(t_pipeline *pipeline, t_mini *mini);

#endif