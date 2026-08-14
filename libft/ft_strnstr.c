/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzampier <jzampier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 15:52:11 by jzampier          #+#    #+#             */
/*   Updated: 2026/07/03 16:51:15 by jzampier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	sub_i;

	i = 0;
	if (!little[i])
		return ((char *)big);
	while (big[i] && i < len)
	{
		sub_i = 0;
		while (big[i + sub_i] == little[sub_i] && (i + sub_i) < len)
		{
			sub_i++;
			if (!little[sub_i])
				return ((char *)&big[i]);
		}
		i++;
	}
	return (NULL);
}
