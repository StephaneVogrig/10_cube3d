/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 11:31:39 by ygaiffie          #+#    #+#             */
/*   Updated: 2024/08/03 17:32:31 by aska             ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../libft.h"

int	ft_atoi(const char *str)
{
	int	int_dest;
	int	sign;

	sign = 1;
	int_dest = 0;
	while (*str == ' ' || ft_isprint(*str) == 0)
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str != 0)
	{
		if (*str > 47 && *str < 58)
			int_dest = int_dest * 10 + (*str - 48);
		else
			return (int_dest * sign);
		str++;
	}
	return (int_dest * sign);
}
