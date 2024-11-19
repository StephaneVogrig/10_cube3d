/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chrono.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 22:34:54 by svogrig           #+#    #+#             */
/*   Updated: 2024/11/19 12:11:50 by svogrig          ###   ########.fr       */
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

char	*fps_to_str(long fps, char *buffer)
{
	char	sign;

	sign = '+';
	if (fps == LONG_MIN)
		return ("-9223372036854775808");
	if (fps < 0)
	{
		sign = '-';
		fps = -fps;
	}
	buffer += LEN_LONG;
	*buffer-- = '\0';
	while (fps > 9)
	{
		*buffer-- = '0' + fps % 10;
		fps = fps /10;
	}
	*buffer = '0' + fps;
	if (sign == '-')
	{
		buffer--;
		*buffer = sign;
	}
	return (buffer);
}


void	fps_print(t_time delay, void *mlx, void *win)
{
	char	str[LEN_LONG];
	char	*fps_str;
	long	fps;

	fps = USECOND_PER_SECOND / delay;	
	fps_str = fps_to_str(fps, str);
	
	if (delay == 0)
		printf("fps: infini\n");
	else
		mlx_string_put(mlx, win, 10, 10, 0xFFFFFFFF, fps_str);
		// printf("time: %ld\tfps: %ld\n", delay, USECOND_PER_SECOND / delay);
}
