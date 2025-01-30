/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gametime.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:02:44 by svogrig           #+#    #+#             */
/*   Updated: 2025/01/27 17:33:39 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAMETIME_H
# define GAMETIME_H

# include <stddef.h>
# include <stdio.h>
# include <sys/time.h>

# ifndef USECOND_PER_SECOND
#  define USECOND_PER_SECOND 1000000
# endif

typedef unsigned long	t_time_us;
typedef struct timeval	t_timeval;

t_time_us				gametime(void);
void					fps_print(t_time_us delay);

#endif