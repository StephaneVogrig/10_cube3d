/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 20:11:05 by svogrig           #+#    #+#             */
/*   Updated: 2025/01/08 02:10:43 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_LINE_BONUS_H
# define DRAW_LINE_BONUS_H

# include "draw_line_utils_bonus.h"
# include "interface_bonus.h"
# include "mlx.h"

void	draw_line(t_interface *minimap, t_vec2i a, t_vec2i b, int color);

#endif