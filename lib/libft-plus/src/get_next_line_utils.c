/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 15:00:35 by ygaiffie          #+#    #+#             */
/*   Updated: 2024/07/21 08:46:09 by aska             ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../libft.h"

void	*ft_calloc_gnl(size_t elementCount, size_t elementSize)
{
	size_t	size;
	void	*init;

	if (elementCount <= 0 || elementSize <= 0)
		return (malloc(0));
	if ((long long)elementCount < 0 || (long long)elementSize < 0)
		return (0);
	size = elementCount * elementSize;
	init = malloc(size);
	if (!(init))
		return (NULL);
	return (ft_bzero(init, size));
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*str_dest;
	size_t	len_dest;
	size_t	i;
	size_t	j;

	if (!s1)
		return (NULL);
	len_dest = (ft_strlen(s1) + ft_strlen(s2) + 1);
	str_dest = ft_calloc_gnl(len_dest, 1);
	if (str_dest == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[j] != '\0')
		str_dest[i++] = s1[j++];
	j = 0;
	while (s2[j] != '\0')
		str_dest[i++] = s2[j++];
	str_dest[i] = '\0';
	free(s1);
	return (str_dest);
}

char	*ft_substr_gnl(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	size;
	char	*sub_str;

	if (!s)
		return (0);
	size = ft_strlen(s);
	if (start > size)
		return (ft_calloc_gnl(1, 1));
	if (start + len > size)
		len = size - start;
	sub_str = ft_calloc_gnl(len + 1, 1);
	if (sub_str == NULL)
		return (NULL);
	i = -1;
	while (++i < len)
		sub_str[i] = s[i + start];
	sub_str[i] = 0;
	return (sub_str);
}

char	*free_char_gnl(char *str)
{
	if (str)
	{
		free(str);
		str = NULL;
	}
	return (NULL);
}

int	ft_strlen_endc(const char *str, int c)
{
	size_t	i;

	if (str == 0)
		return (0);
	i = 0;
	while (str[i] != 0 && str[i] != c)
		i++;
	return (i);
}
