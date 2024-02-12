/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emehdaou <emehdaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 03:56:58 by emehdaou          #+#    #+#             */
/*   Updated: 2024/02/10 05:21:20 by emehdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

char	*ft_findpath(char **envp)
{
	int	i;

	i = 0;
	if (!envp)
		return (NULL);
	while (envp[i])
	{
		if (!ft_strncmp(envp[i], "PATH=", 5))
			return (envp[i]);
		i++;
	}
	return (NULL);
}

char	*get_path(char **envp, char *cmd)
{
	int		i;
	char	**path;
	char	*tmp;

	i = 0;
	if (!cmd)
		return (NULL);
	if (ft_strchr(cmd, '/'))
		return (ft_strdup(cmd));
	if (!ft_findpath(envp))
		return (ft_strdup(cmd));
	path = ft_split(&ft_findpath(envp)[5], ':');
	if (!path)
		return (ft_strdup(cmd));
	while (path[i])
	{
		tmp = ft_strjoin(path[i], cmd);
		if (access(tmp, F_OK | X_OK) == 0)
			return (free_tab(path), tmp);
		free(tmp);
		i++;
	}
	return (free_tab(path), ft_strdup(cmd));
}

void	ft_initdata(int argc, char **argv, char **envp, t_data *data)
{
	data->nbcmd = argc - (3 + data->here_doc);
	data->infile = "tmp";
	if (!data->here_doc)
		data->infile = argv[1];
	data->outfile = argv[argc - 1];
	data->envp = envp;
	data->cmd = &argv[2 + data->here_doc];
	data->pid = malloc(sizeof(int) * data->nbcmd);
}

void	ft_waitpid(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nbcmd)
		waitpid(data->pid[i++], NULL, 0);
}
