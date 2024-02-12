/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 00:30:40 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/11 14:21:17 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_os(void)
{
	if (ft_strcmp(OS, "macos") == 0)
		return ("");
	else if (ft_strcmp(OS, "Linux") == 0)
		return ("🐧");
	else
		return ("?");
}

char	*get_path(t_mini *mini)
{
	char	*path;
	char	*tmp;
	char	*home_path;

	mini->pwd = ft_lstfind_env(&mini->env, "PWD");
	home_path = ft_lstfind_env(&mini->env, "HOME");
	if (mini->pwd && ft_strncmp(mini->pwd, home_path, \
		ft_strlen(home_path)) == 0)
	{
		path = ft_strdup(mini->pwd + ft_strlen(home_path));
		if (!path)
			ft_exit(mini, EXIT_FAILURE, ERR_MALLOC);
		tmp = ft_strjoin("~", path);
		free(path);
		if (!tmp)
			ft_exit(mini, EXIT_FAILURE, ERR_MALLOC);
		return (tmp);
	}
	else
	{
		path = ft_strdup(mini->pwd);
		if (!path)
			ft_exit(mini, EXIT_FAILURE, ERR_MALLOC);
		return (path);
	}
}

int	get_terminal_width(void)
{
	struct winsize	w;

	ioctl(0, TIOCGWINSZ, &w);
	return (w.ws_col);
}

// char	*build_separator(t_mini *mini)
// {
// 	char		*separator;
// 	char		*tmp;
// 	char		*tmp2;
// 	size_t		len;
// 	int			i;
// 	len = get_terminal_width() - mini->shell_prompt.prompt_size;
// 	separator = ft_strdup(C_GRAY "─");
// 	if (!separator)
// 		return (NULL);
// 	i = -1;
//     while (++i < len)
//     {
// 		if (i == len - 1)
// 			tmp = ft_strdup("╮\n╰─" C_WHITE);
// 		else
//         	tmp = ft_strdup("─");
//         if (!tmp)
//             return (free(separator), NULL);
// 		tmp2 = separator;
//         separator = ft_strjoin(separator, tmp);
//         free(tmp);
// 		free(tmp2);
//         if (!separator)
//             return (NULL);
//     }
//     return (separator);
// }

void	build_left_side(t_mini *mini, char *os, char *path)
{
	char	*tmp;

	if (!os || !path || !*os || !*path)
		return ;
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
	mini->shell_prompt.prompt_size = ft_strlen("╭─     ") \
		+ ft_strlen(os) + ft_strlen(path);
	if (mini->last_exec_status == EXIT_SUCCESS)
		mini->shell_prompt.prompt_size += ft_strlen(" ✔ ");
	else
		mini->shell_prompt.prompt_size += ft_strlen(" ✘ ");
}
