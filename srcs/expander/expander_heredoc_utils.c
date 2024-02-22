/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_heredoc_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:09:45 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/21 18:12:20 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	expander_heredoc_expand(char **str, char *env_var, int *j)
{
	int	k;

	k = 0;
	if (env_var)
	{
		while (env_var && env_var[k])
			(*str)[*j++] = env_var[k++];
		free(env_var);
	}
}

int	expander_heredoc_set_new_value(t_mini *mini, char **str, char *prev_str)
{
	int		i;
	int		j;
	char	*env_var;

	i = 0;
	j = 0;
	while (prev_str[i])
	{
		if (prev_str[i] == '$' && prev_str[i + 1] \
			&& !ft_iswhitespace(prev_str[i + 1]) \
			&& prev_str[i + 1] != '\'' && prev_str[i + 1] != '\"')
		{
			i++;
			env_var = expander_heredoc_get_env_var(mini, &prev_str[i]);
			expander_heredoc_expand(str, env_var, &j);
			i += expander_heredoc_get_env_var_name_len(&prev_str[i]) - 1;
		}
		else
		{
			(*str)[j] = prev_str[i];
			j++;
		}
		i++;
	}
	return (1);
}
