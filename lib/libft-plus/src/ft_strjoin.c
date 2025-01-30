/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:44:57 by ygaiffie          #+#    #+#             */
/*   Updated: 2025/01/30 17:42:09 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str_dest;
	size_t	len_dest;
	size_t	i;

	if (!s1 || !s2)
		return (0);
	len_dest = (ft_strlen(s1) + ft_strlen(s2) + 1);
	str_dest = (char *)ft_calloc(len_dest, 1);
	if (str_dest == 0)
		return (0);
	i = 0;
	while (*s1 != 0)
	{
		str_dest[i] = *s1++;
		i++;
	}
	while (*s2 != 0)
	{
		str_dest[i] = *s2++;
		i++;
	}
	str_dest[i] = 0;
	return (str_dest);
}

char	*ft_strjoin_f(char *s1, char *s2)
{
	char	*str_dest;
	size_t	len_dest;
	size_t	i;
	size_t	j;

	if (!s1)
		return (NULL);
	len_dest = (ft_strlen(s1) + ft_strlen(s2) + 1);
	str_dest = ft_calloc(len_dest, 1);
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
	ft_free(s1);
	return (str_dest);
}

char	*ft_strjoin_f2(char *s1, char *s2)
{
	char	*str_dest;
	size_t	len_dest;
	size_t	i;
	size_t	j;

	if (!s1)
		return (NULL);
	len_dest = (ft_strlen(s1) + ft_strlen(s2) + 1);
	str_dest = ft_calloc(len_dest, 1);
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
	ft_free(s2);
	return (str_dest);
}

char	*ft_strjoin_ff(char *s1, char *s2)
{
	char	*str_dest;
	size_t	len_dest;
	size_t	i;
	size_t	j;

	if (!s1)
		return (NULL);
	len_dest = (ft_strlen(s1) + ft_strlen(s2) + 1);
	str_dest = ft_calloc(len_dest, 1);
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
	ft_free(s1);
	ft_free(s2);
	return (str_dest);
}
