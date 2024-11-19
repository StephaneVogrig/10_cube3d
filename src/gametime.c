/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gametime.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 13:41:03 by svogrig           #+#    #+#             */
/*   Updated: 2024/11/19 14:30:57 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gametime.h"

t_gtime	gametime(void)
{
	static t_timeval	start;
	t_timeval			current;
	t_gtime				gtime;

	if (start.tv_sec == 0 && start.tv_usec == 0)
		gettimeofday(&start, NULL);
	gettimeofday(&current, NULL);
	gtime = (current.tv_sec - start.tv_sec) * USECOND_PER_SECOND;
	gtime += current.tv_usec - start.tv_usec;
	return (gtime);
}
