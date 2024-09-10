/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:07:45 by ygaiffie          #+#    #+#             */
/*   Updated: 2024/07/09 16:42:55 by aska             ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../libft.h"

int	count_words(const char *str, char c)
{
	int	n_words;

	n_words = 0;
	while (*str != 0)
	{
		while (*str == c && *str != 0)
			str++;
		if (*str == 0)
			break ;
		while (*str != c && *str != 0)
			str++;
		n_words++;
	}
	return (n_words);
}

char	**ft_split(char const *str, char c)
{
	char	**dest;
	int		i;
	int		x;

	x = 0;
	if (!str)
		return (NULL);
	dest = ft_calloc(sizeof(char *) * (count_words(str, c) + 1), 1);
	if (!dest)
		return (NULL);
	while (*str)
	{
		if (str[0] == c)
			str++;
		else
		{
			i = 0;
			while (str[i] != '\0' && str[i] != c)
				i++;
			dest[x++] = ft_substr(str, 0, i);
			str = str + i;
		}
	}
	dest[x] = NULL;
	return (dest);
}
