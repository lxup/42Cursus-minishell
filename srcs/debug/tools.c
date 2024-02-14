/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 14:37:42 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/14 10:22:47 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_2d_array(char **str)
{
	int	i;
	int	j;

	i = -1;
	printf("Print array:\n");
	while (str && str[++i])
	{
		printf("i = %d : ", i);
		j = -1;
		while (str[i][++j])
			printf("%c",str[i][j]);
		printf("\n");
	}
}	

void	print_env(t_mini *mini)
{
	t_env	*start;
	t_env	*tmp;

	if (!mini->env)
		return ;
	start = mini->env;
	tmp = start;
	while (tmp)
	{
		printf("%s=%s\n", tmp->name, tmp->value);
		tmp = tmp->next;
		if (tmp == start)
			break ;
	}
}

void	print_history(t_list *history)
{
	t_list	*tmp;

	tmp = history;
	while (tmp)
	{
		printf("%s", (char *)tmp->content);
		tmp = tmp->next;
	}
}
