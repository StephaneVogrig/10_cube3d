/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:22:33 by ygaiffie          #+#    #+#             */
/*   Updated: 2025/01/30 17:38:27 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_calloc(size_t elementCount, size_t elementSize)
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
	if (DEBUG_MODE >= 3)
		ft_printf(BMAG "ALLOC\t:" HMAG " %p" CRESET ": %u bytes\n", init, size);
	return (ft_bzero(init, size));
}
