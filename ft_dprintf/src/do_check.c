/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzampier <jzampier@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 12:22:48 by jzampier          #+#    #+#             */
/*   Updated: 2026/08/22 15:33:40 by pezio            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

int	do_check(int fd, char c, va_list *args)
{
	if (c == 'c')
		return (ft_putchar(fd, va_arg(*args, int)));
	if (c == 's')
		return (ft_putstr(fd, va_arg(*args, char *)));
	if (c == 'p')
		return (ft_putptr(fd, va_arg(*args, unsigned long)));
	if (c == 'd' || c == 'i')
		return (ft_putnbr(fd, va_arg(*args, int)));
	if (c == 'u')
		return (ft_putnbr(fd, va_arg(*args, unsigned int)));
	if (c == 'x')
		return (ft_puthex(fd, va_arg(*args, unsigned int), "0123456789abcdef"));
	if (c == 'X')
		return (ft_puthex(fd, va_arg(*args, unsigned int), "0123456789ABCDEF"));
	if (c == '%')
		return (ft_putchar(fd, '%'));
	return (-1);
}
