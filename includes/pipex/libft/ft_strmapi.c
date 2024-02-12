/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emehdaou <emehdaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 00:36:10 by emehdaou          #+#    #+#             */
/*   Updated: 2023/11/15 17:47:49 by emehdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*dest;

	if (!s || !f)
		return (NULL);
	i = 0;
	dest = ft_calloc(sizeof(char), ft_strlen(s) + 1);
	if (!dest)
		return (NULL);
	while (s[i])
	{
		dest[i] = (*f)(i, (char)s[i]);
		i++;
	}
	return (dest);
}
