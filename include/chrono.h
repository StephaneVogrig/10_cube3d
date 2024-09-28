/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chrono.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 22:32:25 by svogrig           #+#    #+#             */
/*   Updated: 2024/09/17 23:02:48 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHRONO_H
# define CHRONO_H

# include <time.h>
# include <stdio.h>

# define START 0
# define STOP 1

long	chrono(int action);
void	fps_print(clock_t delay);

#endif