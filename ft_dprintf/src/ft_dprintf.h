/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzampier <jzampier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 12:22:45 by jzampier          #+#    #+#             */
/*   Updated: 2026/07/16 16:40:41 by jzampier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DPRINTF_H
# define FT_DPRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_dprintf(int fd, const char *str, ...);
int	do_check(int fd, char c, va_list *args);
int	ft_putchar(int fd, char c);
int	ft_putstr(int fd, char *str);
int	ft_putnbr(int fd, long n);
int	ft_putptr(int fd, unsigned long ptr);
int	ft_puthex(int fd, unsigned long n, char *base);

#endif