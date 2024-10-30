/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chrono.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaiffie <ygaiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 22:34:54 by svogrig           #+#    #+#             */
/*   Updated: 2024/10/30 17:13:07 by ygaiffie         ###   ########.fr       */
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
		printf("time: %ld\tfps: %ld\n", delay, CLOCKS_PER_SEC / delay);
}
