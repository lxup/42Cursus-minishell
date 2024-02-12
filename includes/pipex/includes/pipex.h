/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emehdaou <emehdaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 22:49:48 by emehdaou          #+#    #+#             */
/*   Updated: 2024/02/10 02:33:08 by emehdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <signal.h>
# include <stdio.h>
# include <sys/fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>

typedef struct s_data
{
	int		nbcmd;
	char	**cmd;
	int		pipefd[2];
	int		prev;
	char	*infile;
	char	*outfile;
	int		*pid;
	char	**envp;
	int		here_doc;
}			t_data;

char		*get_path(char **envp, char *cmd);
void		ft_initdata(int argc, char **argv, char **envp, t_data *data);
void		ft_waitpid(t_data *data);
void		heredoc(char *delim);
void		ft_process(t_data *data);

#endif