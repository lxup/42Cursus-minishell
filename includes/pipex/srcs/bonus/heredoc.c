/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emehdaou <emehdaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 18:39:17 by emehdaou          #+#    #+#             */
/*   Updated: 2024/02/10 04:20:59 by emehdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

//  ./pipex here_doc LIMITER cmd cmd1 file

void	heredoc(char *delim)
{
	int		fd;
	char	*str;

	fd = open("tmp", O_RDWR | O_CREAT, 0644);
	while (1)
	{
		str = get_next_line(0, 0);
		str[ft_strlen(str) - 1] = '\0';
		if (!ft_strcmp(delim, str))
			break ;
		ft_putendl_fd(str, fd);
		free(str);
	}
	get_next_line(128, 1);
	free(str);
	close(fd);
}
