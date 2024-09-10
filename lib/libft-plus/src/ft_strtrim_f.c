/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_f.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:24:13 by ygaiffie          #+#    #+#             */
/*   Updated: 2024/07/10 18:22:22 by aska             ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../libft.h"

char	*ft_strtrim_f(char *s1, char *set)
{
	char	*trimed_str;
	int		hold_start;
	int		i;
	int		j;

	if (!s1)
		return (NULL);
	hold_start = 0;
	while (s1[hold_start] && ft_strchr(set, s1[hold_start]))
		hold_start++;
	i = ft_strlen(s1) - 1;
	while (i >= hold_start && ft_strchr(set, s1[i]))
		i--;
	i = i - hold_start + 1;
	if (i < 0)
		i = 0;
	trimed_str = (char *)ft_calloc(sizeof(char), (i + 1));
	if (!trimed_str)
		return (NULL);
	j = 0;
	while (i--)
		trimed_str[j++] = s1[hold_start++];
	ft_char_f(s1);
	return (trimed_str);
}
