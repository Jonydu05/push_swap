/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzampier <jzampier@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 12:22:53 by jzampier          #+#    #+#             */
/*   Updated: 2026/08/22 15:34:13 by pezio            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

int	ft_dprintf(int fd, const char *str, ...)
{
	va_list	args;
	int		count;
	int		ret;

	if (!str)
		return (-1);
	va_start(args, str);
	count = 0;
	while (*str)
	{
		if (*str == '%')
			ret = do_check(fd, *(++str), &args);
		else
			ret = ft_putchar(fd, *str);
		if (ret == -1)
		{
			va_end(args);
			return (-1);
		}
		count += ret;
		str++;
	}
	va_end(args);
	return (count);
}
