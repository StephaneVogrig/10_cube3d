/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 20:11:05 by svogrig           #+#    #+#             */
/*   Updated: 2024/09/12 23:21:18 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAWLINE_H
# define DRAWLINE_H

# include "draw_line_utils.h"

void	draw_line(t_screen *screen, t_vec2i a, t_vec2i b, int color);

#endif