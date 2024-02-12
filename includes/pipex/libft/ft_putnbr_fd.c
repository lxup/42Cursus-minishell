/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emehdaou <emehdaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:48:34 by emehdaou          #+#    #+#             */
/*   Updated: 2023/11/11 04:09:35 by emehdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	nb2;

	nb2 = n;
	if (nb2 < 0)
	{
		nb2 *= -1;
		ft_putchar_fd('-', fd);
	}
	if (nb2 > 9)
	{
		ft_putnbr_fd(nb2 / 10, fd);
	}
	ft_putchar_fd((nb2 % 10) + 48, fd);
}
