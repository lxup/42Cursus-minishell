/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:31:59 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/08 18:00:02 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

// LIBRARIES
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <dirent.h>
# include <sys/wait.h>
# include <limits.h>
# include <errno.h>
# include <signal.h>
# include "libft.h"

// FD
# define STDIN 0
# define STDOUT 1
# define STDERR 2

/* ========== STRUCTURES ========== */

/* Chained list for tokens */
typedef struct s_token
{
	char			*value;
	int				type;
	struct s_token	*next;
	struct s_token	*prev;
}				t_token;

/* Chained list for env */
typedef struct s_env
{
	char			*value;
	struct s_env	*next;
	struct s_env	*prev;
}				t_env;

/* Main structure */
typedef struct s_mini
{
	char	**env;
	char	**path;
	
}				t_mini;

#endif