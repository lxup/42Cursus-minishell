/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emehdaou <emehdaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 18:12:02 by emehdaou          #+#    #+#             */
/*   Updated: 2023/11/15 19:10:03 by emehdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int				i;
	unsigned char	*str;
	char			*var;

	if (!s1)
		return (NULL);
	i = 0;
	str = (unsigned char *)s1;
	while (str[i] && ft_strchr(set, str[i]))
		i++;
	if (!str[i])
		return (ft_strdup(""));
	str = &str[i];
	i = ft_strlen((const char *)str) - 1;
	while (str[i] && ft_strchr(set, str[i]))
		i--;
	var = ft_calloc(++i + 1, 1);
	if (var)
		ft_memcpy(var, str, i);
	return (var);
}
// int main()
// {
// 	char * s = ft_strtrim("   xxxtripouille", " x");
// // 	char *s = ft_strtrim(ft_strdup("1231231321123"), "231");
// 	printf("%s\n", s);
// }
//1231223123231avi12on12311231233 charset 123