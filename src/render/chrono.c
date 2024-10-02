/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chrono.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 22:34:54 by svogrig           #+#    #+#             */
/*   Updated: 2024/09/17 23:02:16 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "chrono.h"

clock_t	chrono(int action)
{
	static clock_t	time;

	if (action == START)
		time = clock();
	else
		return (clock() - time);
	return (time);
}

void	fps_print(clock_t delay)
{
	if (delay == 0)
		printf("fps: infini\n");
	else
		printf("time: %ld fps: %ld\n", delay, CLOCKS_PER_SEC / delay);
}
