/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emehdaou <emehdaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:29:14 by emehdaou          #+#    #+#             */
/*   Updated: 2023/11/11 03:51:25 by emehdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*dest2;
	char	*src2;
	size_t	i;

	dest2 = (char *)dest;
	src2 = (char *)src;
	i = 0;
	if (!dest && !src)
		return (dest);
	if (dest2 > src2)
	{
		while (n--)
			dest2[n] = src2[n];
	}
	else
	{
		i = 0;
		while (n > 0)
		{
			dest2[i] = src2[i];
			i++;
			n--;
		}
	}
	return (dest);
}
