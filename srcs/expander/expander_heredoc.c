/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_heredoc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 20:49:58 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/18 15:33:52 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*get_env_var_name(char *str)
{
	int		i;
	char	*env_var;

	i = 0;
	while (str[i] && !ft_iswhitespace(str[i]) \
		&& str[i] != '\'' && str[i] != '\"' && str[i] != '$')
		i++;
	env_var = ft_calloc(i + 1, sizeof(char));
	if (!env_var)
		return (NULL);
	i = 0;
	while (str[i] && !ft_iswhitespace(str[i]) \
		&& str[i] != '\'' && str[i] != '\"' && str[i] != '$')
	{
		env_var[i] = str[i];
		i++;
	}
	return (env_var);
}

static int	get_env_var_name_len(char *str)
{
	int		i;
	char	*var_name;

	i = 0;
	var_name = get_env_var_name(str);
	if (!var_name)
		return (0);
	i = ft_strlen(var_name);
	free(var_name);
	return (i);
}

static char	*get_env_var(t_mini *mini, char *str)
{
	t_env	*env_var;
	char	*env_var_value;
	char	*var_name;

	env_var = NULL;
	env_var_value = NULL;
	var_name = get_env_var_name(str);
	if (!var_name)
		return (NULL);
	if (ft_strcmp(var_name, "?") == 0)
		env_var_value = ft_itoa(mini->last_exec_status);
	else
	{
		env_var = ft_lstfind_env(&mini->env, var_name);
		if (env_var)
			env_var_value = ft_strdup(env_var->value);
	}
	free(var_name);
	if (!env_var_value)
		return (NULL);
	return (env_var_value);
}

static int	get_new_len(t_mini *mini, char *str)
{
	int		i;
	int		len;
	char	*env_var;

	i = 0;
	len = 0;
	while (str[i])
	{
		env_var = NULL;
		if (str[i] == '$' && str[i + 1] && !ft_iswhitespace(str[i + 1]) \
			&& str[i + 1] != '\'' && str[i + 1] != '\"')
		{
			i++;
			env_var = get_env_var(mini, &str[i]);
			i += get_env_var_name_len(&str[i]);
			len += ft_strlen(env_var);
			if (env_var)
				free(env_var);
		}
		else
		{
			(void)len++, (void)i++;
		}
	}
	return (len);
}

static int	set_new_value(t_mini *mini, char **str, char *prev_str)
{
	int		i;
	int		j;
	int		k;
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
			env_var = get_env_var(mini, &prev_str[i]);
			k = 0;
			if (env_var)
			{
				while (env_var && env_var[k])
					(*str)[j++] = env_var[k++];
				free(env_var);
			}
			i += get_env_var_name_len(&prev_str[i]) - 1;
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

char	*expander_heredoc(t_mini *mini, char *str)
{
	char	*new_value;
	char	*tmp;
	int		new_len;

	if (!ft_contains_char(str, '$'))
		return (str);
	new_len = get_new_len(mini, str);
	new_value = ft_calloc(new_len + 1, sizeof(char));
	if (!new_value)
		return (str);
	set_new_value(mini, &new_value, str);
	tmp = str;
	str = new_value;
	free(tmp);
	return (str);
}
