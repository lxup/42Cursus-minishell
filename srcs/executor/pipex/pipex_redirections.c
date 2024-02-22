/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_redirections.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 21:08:27 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/22 17:04:06 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	redir_infile(t_mini *mini, t_pipeline *pipeline, t_token *token)
{
	if (token->type == TOKEN_DLESSER)
	{
		if (pipeline->infile)
			free(pipeline->infile);
		pipeline->infile = ft_strdup(pipeline->heredoc);
		if (pipeline->infile == NULL)
			ft_exit(mini);
	}
	else
	{
		if (pipeline->infile)
			free(pipeline->infile);
		pipeline->infile = ft_strdup(token->next->value);
		if (pipeline->infile == NULL)
			ft_exit(mini);
	}
}

void	redirections(t_pipeline *pipeline, t_mini *mini)
{
	if (pipeline->prev)
	{
		dup2(mini->prevpipe, STDIN_FILENO);
		close(mini->prevpipe);
	}
	if (pipeline->next)
		dup2(mini->pipefd[1], STDOUT_FILENO);
	close(mini->pipefd[1]);
	close(mini->pipefd[0]);
}

void	init_redir(t_mini *mini, t_pipeline *pipeline)
{
	int		fd;
	t_token	*tmp;

	tmp = pipeline->tokens;
	redirections(pipeline, mini);
	while (tmp)
	{
		if (tmp->type == TOKEN_LESSER || tmp->type == TOKEN_DLESSER \
			|| tmp->type == TOKEN_GREATER || tmp->type == TOKEN_DGREATER)
		{
			if (tmp->type == TOKEN_GREATER)
				fd = open(tmp->next->value, O_RDWR | O_CREAT | O_TRUNC, 0644);
			if (tmp->type == TOKEN_DGREATER)
				fd = open(tmp->next->value, O_RDWR | O_CREAT | O_APPEND, 0644);
			if (tmp->type == TOKEN_LESSER)
				fd = open(tmp->next->value, O_RDONLY);
			if (tmp->type == TOKEN_DLESSER)
				fd = open(pipeline->heredoc, O_RDWR);
			if (fd < 0)
				ft_exit(mini);
			dup2(fd, (tmp->type != TOKEN_LESSER && tmp->type != TOKEN_DLESSER));
			close(fd);
		}
		tmp = tmp->next;
	}
}
