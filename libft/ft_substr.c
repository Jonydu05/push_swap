/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzampier <jzampier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 16:00:19 by jzampier          #+#    #+#             */
/*   Updated: 2026/07/09 12:18:24 by jzampier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	s_len;
	size_t	memo;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		memo = 0;
	else if (len > s_len - start)
		memo = s_len - start;
	else
		memo = len;
	substr = malloc(sizeof (char) * (memo + 1));
	if (!substr)
		return (NULL);
	if (memo > 0)
		ft_strlcpy(substr, s + start, memo + 1);
	else
		substr[0] = '\0';
	return (substr);
}
