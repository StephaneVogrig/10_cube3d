/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chrono.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 22:34:54 by svogrig           #+#    #+#             */
/*   Updated: 2024/11/18 22:15:52 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "chrono.h"

t_time	chrono(int action)
{
	static t_timeval	init;
	t_timeval			current;
	t_time				time;

	if (action == START)
	{
		gettimeofday(&init, NULL);
		return (0);
	}
	gettimeofday(&current, NULL);
	time = (current.tv_sec - init.tv_sec) * USECOND_PER_SECOND;
	time += current.tv_usec - init.tv_usec;
	return (time);

}

void	fps_print(t_time delay)
{
	if (delay == 0)
		printf("fps: infini\n");
	else
		printf("time: %ld\tfps: %ld\n", delay, USECOND_PER_SECOND / delay);
}
