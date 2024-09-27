/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 13:55:14 by aska              #+#    #+#             */
/*   Updated: 2024/09/27 03:10:10 by aska             ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef MAP_H
# define MAP_H

# include "lst_map.h"

typedef struct
{
	t_lstmap	*lst_map;
	char		**map_ff;
	char		**map;
	int			max_x;
	int			max_y;
}				t_map;

int	init_map_process(t_map *map, int fd);

#endif