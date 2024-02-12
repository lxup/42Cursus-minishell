/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emehdaou <emehdaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 21:44:37 by emehdaou          #+#    #+#             */
/*   Updated: 2024/02/10 04:21:17 by emehdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_hex(long unsigned int nbr, char *base, int *cnt, int fd)
{
	if (nbr >= ft_strlen(base))
		ft_putnbr_hex(nbr / ft_strlen(base), base, cnt, fd);
	ft_putchar(base[nbr % ft_strlen(base)], fd, cnt);
}

void	ft_putnbr(int nbr, int *cnt, int fd)
{
	if (nbr == INT_MIN)
		return (ft_putstr("-2147483648", 1, cnt));
	if (nbr < 0)
	{
		nbr = -nbr;
		ft_putchar('-', fd, cnt);
	}
	if (nbr >= 10)
		ft_putnbr(nbr / 10, cnt, fd);
	ft_putchar((nbr % 10) + 48, fd, cnt);
}

void	print_arg(char c, va_list args, int *cnt, long *j)
{
	if (c == 'c')
		ft_putchar(va_arg(args, int), 2, cnt);
	else if (c == 's')
		ft_putstr(va_arg(args, char *), 2, cnt);
	else if (c == 'p')
	{
		*j = va_arg(args, size_t);
		if (*j == 0)
			ft_putstr("(nil)", 2, cnt);
		else
			return (ft_putstr("0x", 2, cnt), ft_putnbr_hex(*j, HEXBASE_MIN, cnt,
					2));
	}
	else if (c == 'd')
		ft_putnbr(va_arg(args, int), cnt, 2);
	else if (c == 'i')
		ft_putnbr(va_arg(args, int), cnt, 2);
	else if (c == 'u')
		ft_putnbr_u(va_arg(args, unsigned int), cnt, 2);
	else if (c == 'x')
		ft_putnbr_hex(va_arg(args, unsigned int), HEXBASE_MIN, cnt, 2);
	else if (c == 'X')
		ft_putnbr_hex(va_arg(args, unsigned int), HEXBASE_MAJ, cnt, 2);
	else if (c == '%')
		ft_putchar('%', 2, cnt);
}

void	ft_putnbr_u(unsigned int nbr, int *cnt, int fd)
{
	if (nbr >= 10)
		ft_putnbr(nbr / 10, cnt, fd);
	ft_putchar((nbr % 10) + 48, fd, cnt);
}

int	ft_printf(int fd, const char *str, ...)
{
	va_list	args;
	int		i;
	int		cnt;
	long	j;

	if (!str)
		return (-1);
	va_start(args, str);
	i = 0;
	j = 0;
	cnt = 0;
	while (str[i])
	{
		if (str[i] == '%')
			print_arg(str[++i], args, &cnt, &j);
		else
			ft_putchar(str[i], fd, &cnt);
		i++;
	}
	return (cnt);
}

// int	main(void)
// {
// 	ft_printf(NULL, NULL);
// 	ft_printf(" %s ", NULL);
// 	return (0);
// }