/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emehdaou <emehdaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:33:10 by emehdaou          #+#    #+#             */
/*   Updated: 2024/02/05 04:16:35 by emehdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*res;

	if (!s1)
		res = ft_calloc(1, ft_strlen(s2) + 1);
	else
		res = ft_calloc(1, ft_strlen(s1) + ft_strlen(s2) + 2);
	if (!res)
		return (NULL);
	i = 0;
	j = 0;
	if (s1)
	{
		while (s1[i])
			res[j++] = s1[i++];
	}
	res[j++] = '/';
	i = 0;
	while (s2[i])
		res[j++] = s2[i++];
	res[j] = '\0';
	return (res);
}
