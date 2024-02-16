/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emehdaou <emehdaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 15:59:21 by emehdaou          #+#    #+#             */
/*   Updated: 2024/02/16 22:43:29 by emehdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "pipex.h"

// char	*ft_findpath(char **envp)
// {
// 	int	i;

// 	i = 0;
// 	if (!envp)
// 		return (NULL);
// 	while (envp[i])
// 	{
// 		if (!ft_strncmp(envp[i], "PATH=", 5))
// 			return (envp[i]);
// 		i++;
// 	}
// 	return (NULL);
// }

char	*get_path_pipex(t_mini *mini, char *cmd)
{
	int		i;
	char	*tmp;

	i = 0;
	if (!cmd)
		return (NULL);
	if (ft_strchr(cmd, '/'))
		return (ft_strdup(cmd));
	while (mini->cmd_path[i])
    {
        tmp = ft_strjoin(mini->cmd_path[i], cmd, 1);
        if (access(tmp, F_OK | X_OK) == 0)
            return (tmp);
        free(tmp);
        i++;
    }
	return (ft_strdup(cmd));
}

void	ft_waitpid(t_pipeline *pipeline)
{
    t_pipeline	*curr_pipeline;

    curr_pipeline = pipeline;
    while (curr_pipeline)
    {
        waitpid(curr_pipeline->pid, NULL, 0);
        curr_pipeline = curr_pipeline->next;
    }
}