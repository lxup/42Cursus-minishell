/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_env_var.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 20:49:58 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/17 14:46:00 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// static char	*get_env_var_name(char *str)
// {
// 	int		i;
// 	char	*env_var;

// 	i = 0;
// 	while (str[i] && !ft_iswhitespace(str[i]) \
// 		&& str[i] != '\'' && str[i] != '\"' && str[i] != '$')
// 		i++;
// 	env_var = ft_calloc(i + 1, sizeof(char));
// 	if (!env_var)
// 		return (NULL);
// 	i = 0;
// 	while (str[i] && !ft_iswhitespace(str[i]) \
// 		&& str[i] != '\'' && str[i] != '\"' && str[i] != '$')
// 	{
// 		env_var[i] = str[i];
// 		i++;
// 	}
// 	return (env_var);
// }

// static int	get_env_var_name_len(char *str)
// {
// 	int		i;
// 	char	*var_name;

// 	i = 0;
// 	var_name = get_env_var_name(str);
// 	if (!var_name)
// 		return (0);
// 	i = ft_strlen(var_name);
// 	free(var_name);
// 	return (i);
// }

// static char	*get_env_var(t_mini *mini, char *str)
// {
// 	char	*env_var;
// 	char	*var_name;

// 	env_var = NULL;
// 	var_name = get_env_var_name(str);
// 	if (!var_name)
// 		return (NULL);
// 	if (ft_strcmp(var_name, "?") == 0)
// 		env_var = ft_itoa(mini->last_exec_status);
// 	else
// 	{
// 		env_var = ft_lstfind_env(&mini->env, var_name);
// 		if (env_var)
// 			env_var = ft_strdup(ft_lstfind_env(&mini->env, var_name));
// 	}
// 	free(var_name);
// 	if (!env_var)
// 		return (NULL);
// 	return (env_var);
// }

// static int	get_new_len(t_mini *mini, char *str)
// {
// 	int		i;
// 	int		len;
// 	char	*env_var;

// 	i = 0;
// 	len = 0;
// 	while (str[i])
// 	{
// 		env_var = NULL;
// 		if (str[i] == '$' && str[i + 1] && !ft_iswhitespace(str[i + 1]) \
// 			&& str[i + 1] != '\'' && str[i + 1] != '\"')
// 		{
// 			i++;
// 			env_var = get_env_var(mini, &str[i]);
// 			i += get_env_var_name_len(&str[i]);
// 			len += ft_strlen(env_var);
// 			if (env_var)
// 				free(env_var);
// 		}
// 		else
// 		{
// 			(void)len++, (void)i++;
// 		}
// 	}
// 	return (len);
// }

// static int	set_new_value(t_mini *mini, char **str, t_token *token)
// {
// 	int		i;
// 	int		j;
// 	int		k;
// 	char	*env_var;

// 	i = 0;
// 	j = 0;
// 	while (token->value[i])
// 	{
// 		if (token->value[i] == '$' && token->value[i + 1] \
// 			&& !ft_iswhitespace(token->value[i + 1]) \
// 			&& token->value[i + 1] != '\'' && token->value[i + 1] != '\"')
// 		{
// 			i++;
// 			env_var = get_env_var(mini, &token->value[i]);
// 			k = 0;
// 			if (env_var)
// 			{
// 				while (env_var && env_var[k])
// 					(*str)[j++] = env_var[k++];
// 				free(env_var);
// 			}
// 			i += get_env_var_name_len(&token->value[i]) - 1;
// 		}
// 		else
// 		{
// 			(*str)[j] = token->value[i];
// 			j++;
// 		}
// 		i++;
// 	}
// 	return (1);
// }

// static int	fix_env_var(t_mini *mini, t_token *token)
// {
// 	char	*new_value;
// 	char	*tmp;
// 	int		new_len;

// 	new_len = get_new_len(mini, token->value);
// 	if (new_len == -1)
// 		return (p_err_syntax(mini, '\0'), 0);
// 	if (new_len == (int)ft_strlen(token->value) || new_len == 0)
// 		return (1);
// 	new_value = ft_calloc(new_len + 1, sizeof(char));
// 	if (!new_value)
// 		return (0);
// 	set_new_value(mini, &new_value, token);
// 	if (ft_strlen(new_value) != (size_t)new_len)
// 		return (free(new_value), 0);
// 	tmp = token->value;
// 	token->value = new_value;
// 	free(tmp);
// 	return (1);
// }

static t_token_type	prev_token_type(t_token *token)
{
	t_token	*tmp;

	tmp = token;
	while (tmp && tmp->index == token->index)
		tmp = tmp->prev;
	if (tmp)
		return (tmp->type);
	return (TOKEN_NOT_SET);
}


static int	expand_env_var(t_mini *mini, t_token *token)
{
	char	*env_var;
	char	*tmp;

	if (prev_token_type(token) == TOKEN_DLESSER)
		return (1);
	if (ft_strcmp(token->value + 1, "?") == 0)
		env_var = ft_itoa(mini->last_exec_status);
	else
		env_var = ft_lstfind_env(&mini->env, token->value + 1);
	tmp = token->value;
	if (env_var)
		token->value = ft_strdup(env_var);
	else
		token->value = ft_strdup("");
	free(tmp);
	if (!token->value)
		return (ft_exit(mini, EXIT_FAILURE, 0)); // TODO: EXIT MALLOC FAILED
	return (1);
}

int	expander_env_var(t_mini *mini)
{
	t_token		*tmp_token;

	tmp_token = mini->tokens;
	while (tmp_token)
	{
		if (tmp_token->type == TOKEN_ENV_VAR)
			if (expand_env_var(mini, tmp_token) == 0)
				ft_lstremove_token(&mini->tokens, tmp_token);
		tmp_token = tmp_token->next;
	}
	return (1);
}
