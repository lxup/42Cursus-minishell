/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_pipeline.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:12:34 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/20 16:13:42 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	clear_file(t_pipeline *pipeline)
{
	if (pipeline->infile)
	{
		free(pipeline->infile);
		pipeline->infile = NULL;
	}
	if (pipeline->outfile)
	{
		free(pipeline->outfile);
		pipeline->outfile = NULL;
	}
}

static void	clear_heredoc(t_pipeline *pipeline)
{
	if (pipeline->heredoc)
	{
		free(pipeline->heredoc);
		pipeline->heredoc = NULL;
	}
}

void	ft_lstclear_pipeline(t_pipeline **lst)
{
	t_pipeline	*start;
	t_pipeline	*current;
	t_pipeline	*tmp;

	start = *lst;
	current = start;
	while (current)
	{
		if (current->next)
			tmp = current->next;
		else
			tmp = NULL;
		if (current->tokens)
			ft_lstclear_token(&current->tokens);
		clear_heredoc(current);
		clear_file(current);
		if (current->args)
			ft_free_array((void **)current->args);
		free(current);
		current = tmp;
	}
	*lst = NULL;
}
