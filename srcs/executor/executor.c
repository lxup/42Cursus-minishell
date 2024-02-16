/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 10:56:17 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/16 10:41:29 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// void	ft_exec(t_mini *mini, t_pipeline *pipeline)
// {
// 	char	*cmd_path;
	
// 	cmd_path = get_cmd_path(mini, ft_lstfind_cmd_pipeline(pipeline));
// 	// if (cmd_path)
// 	// 	execve(cmd_path, args, data->envp);
// 	// ft_dprintf("%s: command not found\n", cmd_path);
// 	// free(cmd_path);
// }
// infile ls ls ls ls outfile
// void	redirections(t_data *data, int i)
// {
// 	if (i != 0)
// 	{
// 		dup2(data->prev, STDIN_FILENO);
// 		close(data->prev);
// 	}
// 	if (i != data->nbcmd - 1)
// 		dup2(data->pipefd[1], STDOUT_FILENO);
// 	close(data->pipefd[1]);
// 	close(data->pipefd[0]);
// }


int	create_pipeline(t_mini *mini)
{
	t_token		*cur_token;
	t_pipeline	*cur_pipeline;

	cur_token = mini->tokens;
	ft_lstadd_back_pipeline(&mini->pipeline, ft_lstnew_pipeline());
	cur_pipeline = mini->pipeline;
	while (cur_token)
	{
		if (cur_token->type == TOKEN_PIPE)
		{
			ft_lstadd_back_pipeline(&mini->pipeline, ft_lstnew_pipeline());
			cur_pipeline = cur_pipeline->next;
			cur_token = cur_token->next;
		}
		ft_lstadd_back_token(&cur_pipeline->tokens, ft_lstnew_token(ft_strdup(cur_token->value), cur_token->type));
		cur_token = cur_token->next;
	}

	return (1);
}


// void	*ft_child_proc(t_mini *mini, t_pipeline *pipeline)
// {
// 	t_pipexcmd	*cmd;

// 	cmd = cmd_head->content;
// 	close(fd[0]);
// 	if (cmd_head->next && dup2(fd[1], STDOUT_FILENO) == -1)
// 		return (ft_exit(NULL, DUP_ERR, info, NULL));
// 	if (!cmd_head->next && dup2(info->fd_out, STDOUT_FILENO) == -1)
// 		return (ft_exit(NULL, DUP_ERR, info, NULL));
// 	close(fd[1]);
// 	close(info->fd_in);
// 	close(info->fd_out);
// 	if (execve(cmd->path, cmd->cmd, envp) == -1)
// 		return (ft_exit(*cmd->cmd, EXEC_ERR, info, NULL));
// 	return (NULL);
// }

int	reset_mini(t_mini *mini)
{
	if (mini->pipeline)
		ft_lstclear_pipeline(&mini->pipeline);
	if (mini->tokens)
		ft_lstclear_token(&mini->tokens);
	mini->last_exec_status = mini->exec_status;
	return (1);
}

void	exec_pipeline(t_mini *mini, t_pipeline *pipeline)
{
	redirections(mini, pipeline);
	// MAKE AFTER
}
	
int	executor(t_mini *mini)
{
	t_pipeline	*cur_pipeline;
	
	(void)mini, (void)cur_pipeline;
	printf("Executor\n");
	if (mini->pipeline)
		ft_lstclear_pipeline(&mini->pipeline);
	if (!create_pipeline(mini))
		return (0); // TODO handle error
	if (mini->tokens)
		ft_lstclear_token(&mini->tokens);
	print_pipeline(mini);
	cur_pipeline = mini->pipeline;
	handle_heredoc(mini);
	if (mini->exec_only_heredoc == -1)
	{
		printf("EXEC \n");
		/*EXECUTE EACH PIPELINE */
		while (cur_pipeline)
		{
			exec_pipeline(mini, cur_pipeline);
			cur_pipeline = cur_pipeline->next;
		}
		/**/
	}
	reset_mini(mini);
	return (0);
}
