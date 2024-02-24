/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_left_side.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 00:30:40 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/24 12:35:21 by lquehec          ###   ########.fr       */
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
	tmp = ft_strjoin(BG_WHITE C_BLACK " ", os);
	mini->shell_prompt.prompt = ft_strjoin(tmp, " " BG_BLUE C_WHITE "  ");
	free(tmp);
	tmp = ft_strjoin(mini->shell_prompt.prompt, path);
	free(mini->shell_prompt.prompt);
	free(path);
	if (g_status == EXIT_SUCCESS)
		mini->shell_prompt.prompt = ft_strjoin(tmp, " " BG_BLACK C_BLUE "" \
			BG_BLACK C_GREEN " ✔ " \
			BG_TRANSPARENT C_BLACK "" C_WHITE " ");
	else
		mini->shell_prompt.prompt = ft_strjoin(tmp, " " BG_RED C_BLUE "" \
			BG_RED C_BEIGE " ✘ " \
			BG_TRANSPARENT C_RED "" C_WHITE " ");
	free(tmp);
	mini->shell_prompt.prompt_size = 3 + 1 + 5 + len_path + 6;
}

// void	build_left_side(t_mini *mini, char *os, char *path)
// {
// 	int		len_path;
// 	char	*tmp;
// 	if (!os || !path || !*os || !*path)
// 		return ;
// 	len_path = ft_strlen(path);
// 	mini->shell_prompt.prompt = ft_strjoin(BG_TRANSPARENT 
// 		C_GRAY "╭─" \
// 		BG_WHITE C_BLACK " ", os);
// 	tmp = ft_strjoin(mini->shell_prompt.prompt, " " BG_BLUE 
// 		C_WHITE "  ");
// 	free(mini->shell_prompt.prompt);
// 	mini->shell_prompt.prompt = ft_strjoin(tmp, path);
// 	free(tmp);
// 	free(path);
// 	tmp = ft_strjoin(mini->shell_prompt.prompt, " " BG_BLACK 
// 		C_BLUE "");
// 	free(mini->shell_prompt.prompt);
// 	if (g_status == EXIT_SUCCESS)
// 		mini->shell_prompt.prompt = ft_strjoin(tmp, BG_BLACK 
// 			C_GREEN " ✔ " \
// 			BG_TRANSPARENT C_BLACK "");
// 	else
// 		mini->shell_prompt.prompt = ft_strjoin(tmp, BG_BLACK 
// 			C_RED " ✘ " \
// 			BG_TRANSPARENT C_BLACK "");
// 	free(tmp);
// 	mini->shell_prompt.prompt_size = 3 + 1 + 5 + len_path + 6;
// }
