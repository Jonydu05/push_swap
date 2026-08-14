/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzampier <jzampier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 15:51:38 by jzampier          #+#    #+#             */
/*   Updated: 2026/07/03 16:28:31 by jzampier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *mem, int ch, size_t count)
{
	const unsigned char	*ptr;
	unsigned char		chr;
	size_t				i;

	ptr = (unsigned char *)mem;
	chr = (unsigned char)ch;
	i = 0;
	while (i < count)
	{
		if (chr == ptr[i])
			return ((void *)&mem[i]);
		i++;
	}
	return (NULL);
}
