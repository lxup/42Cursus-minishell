/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_chars_outside_quote.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 11:01:32 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/21 11:04:19 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	inside_quotes(char *str, int *i, char quote)
{
	while (str[*i] && str[*i] != quote)
		(*i)++;
}

int	ft_count_chars_outside_quotes(char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str && str[i])
	{
		if (str[i] == '\'' || str[i] == '\"')
			inside_quotes(str, &i, str[i]);
		if (str[i] == c)
			count++;
		i++;
	}
	return (count);
}