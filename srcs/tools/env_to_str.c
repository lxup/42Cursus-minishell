/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_to_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 00:09:01 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/17 00:09:13 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char **env_to_str(t_env *env)
{
    char **str;
    int i;
    int env_size;
    i = 0;
    env_size = ft_lstsize_env(env);
    str = malloc(sizeof(char *) * (env_size + 1));
    if (!str)
        return (NULL);
    while (i < env_size )
    {
        str[i] = ft_strjoin(env->name, "=");
        str[i] = ft_strjoin(str[i], env->value);
        env = env->next;
        i++;
    }
    str[i] = NULL;
    return (str);
}
