/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzampier <jzampier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 15:51:55 by jzampier          #+#    #+#             */
/*   Updated: 2026/07/09 12:56:10 by jzampier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *s, char c)
{
	int	words;
	int	i;

	i = 0;
	words = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] == '\0')
			break ;
		words++;
		while (s[i] != '\0' && s[i] != c)
			i++;
	}
	return (words);
}

static char	**free_arr(char **arr, int i)
{
	while (i > 0)
	{
		i--;
		free(arr[i]);
	}
	free(arr);
	return (NULL);
}

static char	**fill_arr(char **arr, char const *s, char c)
{
	int	i;
	int	arr_i;
	int	start;

	i = 0;
	arr_i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
		{
			start = i;
			while (s[i] != '\0' && s[i] != c)
				i++;
			arr[arr_i] = ft_substr(s, start, i - start);
			if (!arr[arr_i])
				return (free_arr(arr, arr_i));
			arr_i++;
		}
	}
	arr[arr_i] = NULL;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;

	if (!s)
		return (NULL);
	arr = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!arr)
		return (NULL);
	return (fill_arr(arr, s, c));
}
