/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emehdaou <emehdaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 23:57:50 by emehdaou          #+#    #+#             */
/*   Updated: 2024/01/16 04:21:04 by emehdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	strrev(char *str)
{
	int		i;
	int		size;
	char	tmp;

	i = 0;
	size = 0;
	while (str[size])
		size++;
	while (i < size / 2)
	{
		tmp = str[i];
		str[i] = str[size - 1 - i];
		str[size - 1 - i] = tmp;
		i++;
	}
}

int	count_num(int nb)
{
	int	i;

	i = 1;
	while (nb / 10 != 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int nb)
{
	int		i;
	char	*res;
	int		sign;

	i = 0;
	sign = (nb < 0);
	if (nb == INT_MIN)
		return (ft_strdup("-2147483648"));
	nb = -(nb < 0) * (nb) + (nb > 0) * (nb);
	res = malloc(sizeof(char) * count_num(nb) + sign + 1);
	if (!res)
		return (NULL);
	while (nb >= 10)
	{
		res[i++] = nb % 10 + 48;
		nb = nb / 10;
	}
	res[i++] = nb + 48;
	if (sign == 1)
		res[i++] = '-';
	res[i] = '\0';
	strrev(res);
	return (res);
}

// int main(int ac, char **av)
// {
//     if (ac != 2)
//         return (1);
//     printf("%s\n", ft_itoa(atoi(av[1])));
// }