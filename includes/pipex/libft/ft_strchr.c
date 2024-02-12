/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emehdaou <emehdaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:31:17 by emehdaou          #+#    #+#             */
/*   Updated: 2023/11/11 03:41:30 by emehdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	size_t			i;
	unsigned char	*s1;

	i = 0;
	s1 = (unsigned char *)s;
	while (i <= ft_strlen((char *)(s1)))
	{
		if (s1[i] == (unsigned char)c)
			return ((char *)s1 + i);
		i++;
	}
	return (NULL);
}
