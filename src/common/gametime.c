/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gametime.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 13:41:03 by svogrig           #+#    #+#             */
/*   Updated: 2024/12/03 13:50:19 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "gametime.h"

t_time_us	gametime(void)
{
	static t_timeval	start;
	t_timeval			current;
	t_time_us				gtime;

	if (start.tv_sec == 0 && start.tv_usec == 0)
		gettimeofday(&start, NULL);
	gettimeofday(&current, NULL);
	gtime = (current.tv_sec - start.tv_sec) * USECOND_PER_SECOND;
	gtime += current.tv_usec - start.tv_usec;
	return (gtime);
}
