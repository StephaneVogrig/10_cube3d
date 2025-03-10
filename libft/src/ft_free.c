/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:25:24 by ygaiffie          #+#    #+#             */
/*   Updated: 2025/01/30 17:38:46 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_free(void *pointer)
{
	if (pointer != NULL)
	{
		if (DEBUG_MODE >= 3)
			ft_printf(BHGRN "FREE\t:" GRN " %p\n" CRESET, pointer);
		free(pointer);
	}
}
