/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emehdaou <emehdaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 18:37:27 by emehdaou          #+#    #+#             */
/*   Updated: 2024/01/19 00:14:09 by emehdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_letter(char const *str, char c, int *k)
{
	int	i;

	*k = 0;
	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

int	count_words(char const *str, char c, int *j, int *i)
{
	int	l;
	int	cnt;

	l = 0;
	*i = 0;
	*j = 0;
	cnt = 0;
	while (str[l])
	{
		if (str[l] != c)
		{
			cnt++;
			while (str[l] && str[l] != c)
				l++;
		}
		else
			l++;
	}
	return (cnt);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

char	**ft_split(char const *str, char c)
{
	int		i;
	int		j;
	int		k;
	char	**res;

	if (!str)
		return (NULL);
	res = ft_calloc(sizeof(char *), count_words((char *)str, c, &j, &i) + 1);
	if (!res)
		return (free(res), NULL);
	while (str[i])
	{
		if (str[i] != c)
		{
			res[j] = ft_calloc(sizeof(char), count_letter(&str[i], c, &k) + 1);
			if (!res[j])
				return (free_tab(res), NULL);
			while (str[i] && str[i] != c)
				res[j][k++] = str[i++];
			j++;
		}
		else
			i++;
	}
	return (res);
}
