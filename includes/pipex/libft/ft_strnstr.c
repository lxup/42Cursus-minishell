/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emehdaou <emehdaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:35:13 by emehdaou          #+#    #+#             */
/*   Updated: 2023/11/15 19:03:28 by emehdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if ((!big || !little) && len == 0)
		return (NULL);
	if (!*little)
		return ((char *)big);
	i = 0;
	while (big[i] && i < len)
	{
		j = 0;
		while ((big[i + j]) && (big[i + j] == little[j]) && (i + j < len))
			j++;
		if (!little[j])
			return ((char *)big + i);
		i++;
	}
	return (NULL);
}

// int main(){
// 	char *s1 = "oh no not the empty string !";
// 	char *s2 = "";
// 	size_t max = 0;
// 	// printf("%s\n", strnstr(s1, s2, max));
// 	printf("%s\n", ft_strnstr(s1, s2, max));

// 	// if (i1 == i2)
// }