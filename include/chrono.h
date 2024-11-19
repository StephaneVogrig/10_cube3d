/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chrono.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 22:32:25 by svogrig           #+#    #+#             */
/*   Updated: 2024/11/19 00:55:11 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHRONO_H
# define CHRONO_H

# include <time.h>
# include <stdio.h>
# include <sys/time.h>
# include <limits.h>
# include "mlx.h"

# define START 0
# define STOP 1

# define USECOND_PER_SECOND 1000000
# define LEN_LONG 21

typedef struct	timeval t_timeval;
typedef long 	t_time;

t_time	chrono(int action);
void	fps_print(t_time delay, void *mlx, void *win);

#endif