/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_manda.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 01:52:20 by svogrig           #+#    #+#             */
/*   Updated: 2025/02/01 12:59:09 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DDA_MANDA_H
# define DDA_MANDA_H

# include "data_manda.h"
# include "dda_utils.h"
# include "map.h"
# include "position.h"
# include "ray.h"

void	dda(t_ray *ray, t_position *start, t_data *data);

#endif