/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   profiling.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 01:28:30 by svogrig           #+#    #+#             */
/*   Updated: 2024/11/28 13:50:09 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "profiling.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h> 

static long gettime_ns(clockid_t clockid)
{
	static struct timespec	timespec_start;
	struct timespec			timespec_current;
	long					time_ns;

	if (timespec_start.tv_nsec == 0 && timespec_start.tv_sec == 0)
	{
		if (clock_gettime(clockid, &timespec_start) == -1)
		{
			perror("get_cpu_time: clock_gettime");
			exit(EXIT_FAILURE);
		}
	}
	if (clock_gettime(clockid, &timespec_current) == -1)
	{
		perror("clock_gettime");
		exit(EXIT_FAILURE);
	}
	time_ns = timespec_current.tv_sec - timespec_start.tv_sec;
	if (time_ns != 0)
		time_ns *= 1000000000;
	time_ns += timespec_current.tv_nsec - timespec_start.tv_nsec;
	return (time_ns);
}

void profile(int n, t_profile action)
{
	static long count[1001];
	static long time_cumul[1001];

	if (action == P_START)
	{
		time_cumul[n] -= gettime_ns(CLOCK_THREAD_CPUTIME_ID);
	}
	else if (action == P_STOP)
	{
		time_cumul[n] += gettime_ns(CLOCK_THREAD_CPUTIME_ID);
		count[n]++;
	}
	else
	{
		printf("profile %3i - "
				"total time: %' 15.0lf - "
				"count: %'6li - "
				"average time %' 15.0f\n",
				n,
				(float)time_cumul[n],
				count[n],
				(double)time_cumul[n] / count[n]);
	}
}
