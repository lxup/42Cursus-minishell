/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emehdaou <emehdaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 19:47:56 by emehdaou          #+#    #+#             */
/*   Updated: 2023/11/15 17:25:33 by emehdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

// 0123456 8 20 = 34

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned char	*dest;
	unsigned char	*s1;
	size_t			i;
	size_t			lens1;

	if (!s)
		return (NULL);
	i = 0;
	s1 = (unsigned char *)s;
	lens1 = ft_strlen(s);
	if (start >= lens1)
		return (ft_strdup(""));
	if (lens1 - start < len)
		dest = ft_calloc(sizeof(unsigned char), lens1 - start + 1);
	else
		dest = ft_calloc(sizeof(unsigned char), len + 1);
	if (!dest)
		return (NULL);
	while (i < len && i < lens1 - start)
	{
		dest[i] = s1[start + i];
		i++;
	}
	return ((char *)dest);
}

// int main()
// {
// 	printf("%s\n", ft_substr("tripouille", 0, 4200));
// }