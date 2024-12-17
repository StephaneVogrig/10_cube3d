/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gametime.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:02:44 by svogrig           #+#    #+#             */
/*   Updated: 2024/12/17 14:22:02 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef GET_TIME_H
# define GET_TIME_H

# include <stddef.h>
# include <sys/time.h>
# include <stdio.h>

# ifndef USECOND_PER_SECOND
#  define USECOND_PER_SECOND 1000000
# endif

typedef unsigned long t_time_us;
typedef struct timeval t_timeval;

t_time_us	gametime(void);
void		fps_print(t_time_us delay);

#endif