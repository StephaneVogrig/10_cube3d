/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 01:30:18 by svogrig           #+#    #+#             */
/*   Updated: 2024/09/16 17:20:44 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include <math.h>
# include "data.h"
# include "draw_line.h"
# include "draw_utils.h"
# include "draw_line_to_border.h"
# include "raycasting.h"

void	render(t_data *data);

#endif