/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 11:03:49 by ygaiffie          #+#    #+#             */
/*   Updated: 2024/07/09 16:45:27 by aska             ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../libft.h"

char	*ft_strdup(char *src)
{
	int		i;
	char	*dest;

	if (!src)
		return (NULL);
	i = ft_strlen(src);
	dest = (char *)malloc(sizeof(char) * (i + 1));
	if (DEBUG_MODE >= 3)
		ft_printf(BMAG"ALLOC\t:" HMAG " %p" CRESET ": %u bytes\n", dest,i + 1);
	if (dest == 0)
		return (0);
	dest[i] = '\0';
	while (i-- != 0)
		dest[i] = src[i];
	return (dest);
}
