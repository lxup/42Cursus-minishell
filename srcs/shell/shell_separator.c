/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_separator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 12:18:56 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/20 12:59:02 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	*build_separator(t_mini *mini)
{
	int		sep_count;
	int		sep_size;
	char	*sep;
	char	*tmp;
	int		i;

	sep_count = get_terminal_width() - mini->shell_prompt.prompt_size;
	sep_size = (sep_count * (int)ft_strlen("─")) \
		+ (int)ft_strlen("╰─" C_GRAY) + (int)ft_strlen(C_WHITE);
	sep = ft_calloc(sep_size + 1, sizeof(char));
	if (!sep)
		return (ft_exit(mini), NULL);
	ft_strlcat(sep, C_GRAY, sep_size + 1);
	i = (int)ft_strlen(C_GRAY);
	while (i < sep_size)
	{
		if (i == sep_size - (int)ft_strlen("╰─" C_GRAY))
			ft_strlcat(sep, "╰─" C_WHITE, sep_size + 1);
		else
			ft_strlcat(sep, "─", sep_size + 1);
		i += (int)ft_strlen("─");
	}
	tmp = mini->shell_prompt.prompt;
	mini->shell_prompt.prompt = ft_strjoin(mini->shell_prompt.prompt, sep);
	return (free(tmp), free(sep), NULL);
}
