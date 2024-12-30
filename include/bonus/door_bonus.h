/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 19:51:31 by svogrig           #+#    #+#             */
/*   Updated: 2024/12/30 15:53:11 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef DOOR_BONUS_H
# define DOOR_BONUS_H

# include "libft.h"
# include "gametime.h"
# include "ray.h"
# include "map.h"
# include "position.h"
# include "utils.h"
# include "cell_bonus.h"

# ifndef TRUE
#  define TRUE 1
# endif

# ifndef FALSE
#  define FALSE 0
# endif

# define DOORS_SIZE		10

# define TIME_OPENING	0.5
# define TIME_CLOSING	0.5
# define TIME_OPEN		1

# define DOOR_OPEN_DIST	1.5

typedef enum e_stage
{
	DOOR_OPENING,
	DOOR_OPEN,
	DOOR_CLOSING
}	t_stage;

typedef struct s_door
{
	char	*ptr_map;
	t_stage	stage;
	float	stage_rate;
}	t_door;

/* door_bonus.c */
int		is_hit_door(float pos_in_side, char *cell, t_door *door_open_list);
int		cell_is_door(char cell);
float	door_get_closing_rate(char *cell, t_door *door_open_list);
void	door_open(char *cell, t_door *door_open_list);
t_door	*door_find(char *cell, t_door *door_open_list);

/* door_collide_bonus.c */
int		is_collide_door(t_ray *ray, t_map *map, t_position *position, t_door *door_open_list);

/* door_open_list_bonus.c */
int		door_open_list_update(t_door *door_open_list, t_time_us dt);
t_door	*door_open_list_add(char *cell, t_door *door_open_list);

#endif