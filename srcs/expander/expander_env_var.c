/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_env_var.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 20:49:58 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/14 22:00:51 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*get_env_var_name(char *str)
{
	int		i;
	char	*env_var;

	i = 0;
	while (str[i] && str[i] != ' ' && str[i] != '\'' && str[i] != '\"' && str[i] != '$')
		i++;
	env_var = ft_calloc(i + 1, sizeof(char));
	if (!env_var)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != ' ' && str[i] != '\'' && str[i] != '\"' && str[i] != '$')
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
	char	*env_var;
	char	*var_name;

	var_name = get_env_var_name(str);
	if (!var_name)
		return (NULL);
	env_var = ft_lstfind_env(&mini->env, var_name);
	free(var_name);
	if (!env_var)
		return (NULL);
	return (env_var);
}

static int	get_new_len(t_mini *mini, char *str)
{
	int		i;
	int		len;
	char	quote_type;
	char	*env_var;

	i = 0;
	len = 0;
	quote_type = 0;
	while (str[i])
	{
		env_var = NULL;
		if (str[i] == '$')
		{
			i++;
			env_var = get_env_var(mini, &str[i]);
			i += get_env_var_name_len(&str[i]);
			len += ft_strlen(env_var);
		}
		else
		{
			len++;
			i++;
		}
	}
	return (len);
}

static int	set_new_value(t_mini *mini, char **str, t_token *token)
{
	int		i;
	int		j;
	int		k;
	char	*env_var;
	

	i = 0;
	j = 0;
	while (token->value[i])
	{
		if (token->value[i] == '$')
		{
			i++;
			env_var = get_env_var(mini, &token->value[i]);
			k = 0;
			if (env_var)
				while (env_var && env_var[k])
				{
					(*str)[j] = env_var[k];
					k++;
					i++;
					j++;
				}
			else
			{
				printf("env_var not found\n");
				i += get_env_var_name_len(&token->value[i]);
			}
		}
		else
		{
			(*str)[j] = token->value[i];
			j++;
		}
		i++;
	}
	return (1);
}

static int	fix_env_var(t_mini *mini, t_token *token)
{
	char	*new_value;
	char	*tmp;
	int		new_len;

	new_len = get_new_len(mini, token->value);
	if (new_len == -1)
		return (mini->exec_status = EXEC_SYNTAX_ERROR, 0);
	printf("new_len = %d\n", new_len);
	if (new_len == (int)ft_strlen(token->value) || new_len == 0)
		return (1);
	new_value = ft_calloc(new_len + 1, sizeof(char));
	if (!new_value)
		return (0);
	set_new_value(mini, &new_value, token); // TODO: fix this
	printf("new_value = %s\n", new_value);
	if (ft_strlen(new_value) != (size_t)new_len)
		return (free(new_value), 0);
	tmp = token->value;
	token->value = new_value;
	free(tmp);
	return (1);
}

int	expander_env_var(t_mini *mini)
{
	t_pipeline	*tmp_pipeline;
	t_token		*tmp_token;

	print_pipeline(mini);
	tmp_pipeline = mini->pipeline;
	while (tmp_pipeline)
	{
		tmp_token = tmp_pipeline->tokens;
		while (tmp_token)
		{
			if (ft_contains_char(tmp_token->value, '$'))
			{
				if (!fix_env_var(mini, tmp_token))
					return (0);
			}
			tmp_token = tmp_token->next;
		}
		tmp_pipeline = tmp_pipeline->next;
	}
	return (1);
}
