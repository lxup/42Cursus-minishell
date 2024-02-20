/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_left_side.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 00:30:40 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/20 12:57:38 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_os(void)
{
	if (ft_strcmp(OS, "macos") == 0)
		return ("");
	else if (ft_strcmp(OS, "linux") == 0)
		return ("🐧");
	else
		return ("?");
}

char	*get_path(t_mini *mini)
{
	char	*path;
	char	*tmp;
	t_env	*home_path;
	t_env	*pwd;

	pwd = ft_lstfind_env(&mini->env, "PWD");
	home_path = ft_lstfind_env(&mini->env, "HOME");
	if (pwd && home_path && !ft_strncmp(pwd->value, home_path->value, ft_strlen(home_path->value)))
	{
		path = ft_strdup(pwd->value + ft_strlen(home_path->value));
		if (!path)
			ft_exit(mini);
		tmp = ft_strjoin("~", path);
		free(path);
		if (!tmp)
			ft_exit(mini);
		return (tmp);
	}
	else if (pwd)
	{
		path = ft_strdup(pwd->value);
		if (!path)
			ft_exit(mini);
		return (path);
	}
	path = ft_strdup("?");
	if (!path)
		ft_exit(mini);
	return (path);
}

int	get_terminal_width(void)
{
	struct winsize	w;

	ioctl(0, TIOCGWINSZ, &w);
	return (w.ws_col);
}

void	build_left_side(t_mini *mini, char *os, char *path)
{
	int		len_path;
	char	*tmp;

	if (!os || !path || !*os || !*path)
		return ;
	len_path = ft_strlen(path);
	mini->shell_prompt.prompt = ft_strjoin(BG_TRANSPARENT C_GRAY "╭─" \
		BG_WHITE C_BLACK " ", os);
	tmp = ft_strjoin(mini->shell_prompt.prompt, " " BG_BLUE C_WHITE "  ");
	free(mini->shell_prompt.prompt);
	mini->shell_prompt.prompt = ft_strjoin(tmp, path);
	free(tmp);
	free(path);
	tmp = ft_strjoin(mini->shell_prompt.prompt, " " BG_BLACK C_BLUE "");
	free(mini->shell_prompt.prompt);
	if (mini->last_exec_status == EXIT_SUCCESS)
		mini->shell_prompt.prompt = ft_strjoin(tmp, PROMPTE_SUCCESS_TEMPLATE);
	else
		mini->shell_prompt.prompt = ft_strjoin(tmp, PROMPTE_ERROR_TEMPLATE);
	free(tmp);
	mini->shell_prompt.prompt_size = 3 + 1 + 5 + len_path + 6;
}
