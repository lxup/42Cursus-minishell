/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emehdaou <emehdaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:28:44 by emehdaou          #+#    #+#             */
/*   Updated: 2023/11/10 04:02:52 by emehdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>
#define MAXSIZET 18446744073709551615UL

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*s;

	if (nmemb == 0 || size == 0)
		return (ft_calloc(1, 1));
	if (size != 0 && MAXSIZET / size < nmemb)
		return (NULL);
	s = malloc(nmemb * size);
	if (!s)
		return (NULL);
	ft_bzero(s, nmemb * size);
	return (s);
}
