/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_manda.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:13:53 by svogrig           #+#    #+#             */
/*   Updated: 2024/12/26 13:46:33 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef RAYCASTING_MANDA_H
# define RAYCASTING_MANDA_H

# include "player.h"
# include "ray.h"
# include "vector.h"
# include "data_manda.h"
# include "dda_manda.h"

void	raycasting(t_ray *rays, t_data *data);

#endif
