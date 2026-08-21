/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_put.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzampier <jzampier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 12:22:50 by jzampier          #+#    #+#             */
/*   Updated: 2026/08/10 17:29:20 by jzampier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

int	ft_putchar(int fd, char c)
{
	return (write(fd, &c, 1));
}

int	ft_putstr(int fd, char *str)
{
	int	i;

	i = 0;
	if (!str)
		i += ft_putstr(fd, "(null)");
	while (str && str[i])
		i += ft_putchar(fd, str[i]);
	return (i);
}

int	ft_putnbr(int fd, long n)
{
	long	n1;
	int		count;

	n1 = n;
	count = 0;
	if (n1 < 0)
	{
		count += ft_putchar(fd, '-');
		n1 *= -1;
	}
	if (n1 > 9)
		count += ft_putnbr(fd, n1 / 10);
	count += ft_putchar(fd, (n1 % 10) + '0');
	return (count);
}

int	ft_puthex(int fd, unsigned long n, char *base)
{
	int	count;

	count = 0;
	if (n >= 16)
		count += ft_puthex(fd, n / 16, base);
	count += ft_putchar(fd, base[n % 16]);
	return (count);
}

int	ft_putptr(int fd, unsigned long ptr)
{
	int	count;

	if (!ptr)
		return (ft_putstr(fd, "(nil)"));
	count = 0;
	count += ft_putstr(fd, "0x");
	count += ft_puthex(fd, ptr, "0123456789abcdef");
	return (count);
}
