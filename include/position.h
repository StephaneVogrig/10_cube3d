/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 01:38:10 by svogrig           #+#    #+#             */
/*   Updated: 2024/10/31 02:22:07 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POSITION_H
# define POSITION_H

# include "vec2i.h"

typedef struct s_position{
	t_vec2i	grid;
	t_vec2d	box;
}	t_position;

#endif
