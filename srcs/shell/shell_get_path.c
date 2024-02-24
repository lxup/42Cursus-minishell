/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_get_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 18:13:57 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/24 12:00:58 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*shell_get_path_in_home(t_mini *mini, t_env *home_path, t_env *pwd)
{
	char	*path;
	char	*tmp;

	tmp = ft_strdup(pwd->value + ft_strlen(home_path->value));
	if (!tmp)
		return (ft_exit(mini), NULL);
	path = ft_strjoin("~", tmp);
	free(tmp);
	if (!path)
		return (ft_exit(mini), NULL);
	return (path);
}

char	*get_path(t_mini *mini)
{
	char	*path;
	t_env	*home_path;
	t_env	*pwd;

	pwd = ft_lstfind_env(&mini->env, "PWD");
	home_path = ft_lstfind_env(&mini->env, "HOME");
	if (pwd && home_path && !ft_strncmp(pwd->value, home_path->value, \
		ft_strlen(home_path->value)))
		return (shell_get_path_in_home(mini, home_path, pwd));
	else if (pwd)
	{
		path = ft_strdup(pwd->value);
		if (!path)
			return (ft_exit(mini), NULL);
		return (path);
	}
	path = ft_strdup("?");
	if (!path)
		return (ft_exit(mini), NULL);
	return (path);
}

// char	*get_path(t_mini *mini)
// {
// 	char	*path;
// 	t_env	*home_path;
// 	t_env	*pwd;

// 	pwd = ft_lstfind_env(&mini->env, "PWD");
// 	home_path = ft_lstfind_env(&mini->env, "HOME");
// 	if (pwd && home_path && !ft_strncmp(pwd->value, 
//		home_path->value, \
// 		ft_strlen(home_path->value)))
// 		return (shell_get_path_in_home(mini, home_path, pwd));
// 	else if (pwd)
// 	{
// 		path = ft_strdup(pwd->value);
// 		if (!path)
// 			return (ft_exit(mini), NULL);
// 		return (path);
// 	}
// 	path = ft_strdup("?");
// 	if (!path)
// 		return (ft_exit(mini), NULL);
// 	return (path);
// }
