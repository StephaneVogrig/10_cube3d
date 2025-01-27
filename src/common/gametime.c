/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gametime.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 13:41:03 by svogrig           #+#    #+#             */
/*   Updated: 2025/01/27 15:49:27 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gametime.h"

t_time_us	gametime(void)
{
	static t_timeval	start;
	t_timeval			current;
	t_time_us			gtime;

	if (start.tv_sec == 0 && start.tv_usec == 0)
		gettimeofday(&start, NULL);
	gettimeofday(&current, NULL);
	gtime = (current.tv_sec - start.tv_sec) * USECOND_PER_SECOND;
	gtime += current.tv_usec - start.tv_usec;
	return (gtime);
}

void	fps_print(t_time_us delay)
{
	if (delay == 0)
		printf("fps: infini\n");
	else
		printf("time: %ld\tfps: %ld\n", delay, USECOND_PER_SECOND / delay);
}
