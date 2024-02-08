/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:38:04 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/08 21:18:01 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int ac, char **av, char **env)
{
	t_mini	mini;
	
	(void)ac;
	(void)av;
	(void)env;
	(void)mini;
	// for (int i = 0; env[i]; i++)
	// 	printf("%s\n", env[i]);
	for (int i = 0; av[i]; i++)
		printf("%s\n", av[i]);

	/*
		LEXER
		Operators:
			> < += -= = | || >> << & && , . ; : ! ? * % / + - ~ ^
	*/ 
	

	// PARAING

	
	return (0);
}
