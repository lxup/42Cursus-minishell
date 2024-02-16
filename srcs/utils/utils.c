/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emehdaou <emehdaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 13:39:06 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/16 21:43:59 by emehdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>

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
        // str[i] = malloc(sizeof(char) * (ft_strlen(env->name) + ft_strlen(env->value) + 2));
        str[i] = ft_strjoin(env->name, "=", 0);
        str[i] = ft_strjoin(str[i], env->value, 0);
        env = env->next;
        i++;
    }
    str[i] = NULL;
    return (str);
}