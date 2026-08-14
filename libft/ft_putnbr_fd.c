/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzampier <jzampier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 21:07:22 by jzampier          #+#    #+#             */
/*   Updated: 2026/07/01 21:26:45 by jzampier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	n1;

	n1 = n;
	if (n1 < 0)
	{
		ft_putchar_fd('-', fd);
		n1 *= -1;
	}
	if (n1 > 9)
		ft_putnbr_fd(n1 / 10, fd);
	ft_putchar_fd((n1 % 10) + '0', fd);
}
