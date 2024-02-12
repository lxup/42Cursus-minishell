/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emehdaou <emehdaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 22:47:35 by emehdaou          #+#    #+#             */
/*   Updated: 2024/02/10 04:01:06 by emehdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

void	redirections(t_data *data, int i)
{
	if (i != 0)
	{
		dup2(data->prev, STDIN_FILENO);
		close(data->prev);
	}
	if (i != data->nbcmd - 1)
		dup2(data->pipefd[1], STDOUT_FILENO);
	close(data->pipefd[1]);
	close(data->pipefd[0]);
}
// si i != 0
// alors data->cmd[1 - 1 | data->nbcmd]
// donc la condition est a 0
// alors perror(data->cmd[data->nbcmd])
// sinon
// alors perror(data->cmd[i - 1])

void	open_files(int i, t_data *data)
{
	int	fd;

	if (i == 0)
		fd = open(data->infile, O_RDONLY);
	if (i == data->nbcmd - 1)
		fd = open(data->outfile, O_RDWR | O_CREAT | O_TRUNC, 0666);
	if (fd < 0)
	{
		perror(data->cmd[(i != 0) - 1 | data->nbcmd]);
		exit(1);
	}
	dup2(fd, i == data->nbcmd - 1);
	close(fd);
}

void	ft_exec(char *cmd, t_data *data)
{
	char	**args;

	args = ft_split(cmd, ' ');
	if (!args)
		return ;
	cmd = get_path(data->envp, args[0]);
	if (cmd)
		execve(cmd, args, data->envp);
	ft_printf(2, "%s: command not found\n", cmd);
	free(cmd);
	free_tab(args);
}

void	ft_process(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nbcmd)
	{
		pipe(data->pipefd);
		data->pid[i] = fork();
		if (data->pid[i] == 0)
		{
			free(data->pid);
			redirections(data, i);
			if (i == 0 || i == data->nbcmd - 1)
				open_files(i, data);
			ft_exec(data->cmd[i], data);
			exit(127);
		}
		else
		{
			if (i)
				close(data->prev);
			data->prev = data->pipefd[0];
			close(data->pipefd[1]);
		}
	}
	ft_waitpid(data);
}

int	main(int argc, char **argv, char **envp)
{
	static t_data	data = {0};

	if (argc != 5)
		return (0);
	ft_initdata(argc, argv, envp, &data);
	data.pid = malloc(sizeof(int) * data.nbcmd);
	ft_process(&data);
	free(data.pid);
	close(data.pipefd[0]);
	close(data.pipefd[1]);
}
