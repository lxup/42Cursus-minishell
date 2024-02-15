/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 14:37:42 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/15 22:31:11 by lquehec          ###   ########.fr       */
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

void	print_tokens(t_token *token)
{
	t_token	*tmp;

	tmp = token;
	while (tmp)
	{
		printf("value: %s\n", tmp->value);
		if (tmp->type == TOKEN_WORD)
			printf("type: TOKEN_WORD\n");
		else if (tmp->type == TOKEN_GREATER)
			printf("type: TOKEN_GREATER\n");
		else if (tmp->type == TOKEN_DGREATER)
			printf("type: TOKEN_DGREATER\n");
		else if (tmp->type == TOKEN_LESSER)
			printf("type: TOKEN_LESSER\n");
		else if (tmp->type == TOKEN_DLESSER)
			printf("type: TOKEN_DLESSER\n");
		else if (tmp->type == TOKEN_PIPE)
			printf("type: TOKEN_PIPE\n");
		else if (tmp->type == TOKEN_ARGS)
			printf("type: TOKEN_ARGS\n");
		else if (tmp->type == TOKEN_CMD)
			printf("type: TOKEN_CMD\n");
		else if (tmp->type == TOKEN_FILE)
			printf("type: TOKEN_FILE\n");
		else if (tmp->type == TOKEN_UNKNOWN)
			printf("type: TOKEN_UNKNOWN\n");
		else if (tmp->type == TOKEN_NOT_SET)
			printf("type: TOKEN_NOT_SET\n");
		else
			printf("type: UNKNOW\n");
		tmp = tmp->next;
	}
}

void	print_pipeline(t_mini *mini)
{
	int			i;
	t_pipeline	*tmp;
	
	tmp = mini->pipeline;
	i = 0;
	while (tmp)
	{
		printf("Pipeline: %i\n", i);
		printf("file: %s\n", tmp->file);
		print_tokens(tmp->tokens);
		tmp = tmp->next;
		i++;
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
