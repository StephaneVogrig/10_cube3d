/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gametime.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:02:44 by svogrig           #+#    #+#             */
/*   Updated: 2024/11/19 14:26:21 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_TIME_H
# define GET_TIME_H

# include <stddef.h>
# include <sys/time.h>

# ifndef USECOND_PER_SECOND
#  define USECOND_PER_SECOND 1000000
# endif

typedef unsigned long t_gtime;
typedef struct timeval t_timeval;

t_gtime	gametime(void);

#endif