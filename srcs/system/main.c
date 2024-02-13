/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:38:04 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/13 13:52:28 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	test(t_mini *mini)
{
	char	*buffer = NULL;
	size_t	buf_size = 2048;

	(void)mini;
	// alloc buffer qui stockera la commande entree par l'user
	buffer = (char *)calloc(sizeof(char), buf_size);
	if (buffer == NULL) {
		perror("Malloc failure");
		return (EXIT_FAILURE);
	}

	// ecriture d'un prompt
	write(1, "$> ", 3);

	// lecture de STDIN en boucle
	while (getline(&buffer, &buf_size, stdin) > 0) {
		printf("cmd = %s\n", buffer);
		write(1, "$> ", 3);
	}

	printf("Bye \n");
	free(buffer);
	return (EXIT_SUCCESS);
}



int		main(int ac, char **av, char **env)
{
	t_mini	mini;
	
	(void)ac, (void)av;
	// for (int i = 0; env[i]; i++)
	// 	printf("%s\n", env[i]);
	init(&mini, env);
	minishell(&mini);

	// test(&mini)
	return (ft_exit(&mini, EXIT_SUCCESS, NULL));
}