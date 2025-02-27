/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 19:51:31 by svogrig           #+#    #+#             */
/*   Updated: 2025/02/03 00:12:47 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOOR_BONUS_H
# define DOOR_BONUS_H

# include <stdbool.h>
# include "cell_bonus.h"
# include "gametime.h"
# include "libft.h"
# include "map.h"
# include "position.h"
# include "ray.h"
# include "utils.h"

// size of the array to store the open door list
# define DOORS_SIZE 10

// time of differents states of the doors in second
# define TIME_OPENING 0.5
# define TIME_CLOSING 0.5
# define TIME_OPEN 1

// DOOR_OPEN_DIST is the minimale distance needed for open a door
// by clicking on a mousebutton
# define DOOR_OPEN_DIST 1.5

// DOOR_THICK is the door thickness in percent of the wall
// It must be between 0.0 and 1.0
# define DOOR_THICK_T 0.1
# define DOOR_THICK_L 0.4
# define DOOR_THICK_R 0.4

// we have three opening door (only by sliding)
// type T opening by the middle
// type R opening to the right, when looking north
// type L opening to the left, when looking north
# define DOOR_OPEN_TYPE_T 0
# define DOOR_OPEN_TYPE_R 1
# define DOOR_OPEN_TYPE_L 2

// to find out what a ray hit when it is a door
# define SIDE_DOOR_X 0
# define SIDE_DOOR_Y 1
# define SIDE_EDGE_X 2
# define SIDE_EDGE_Y 3

typedef enum e_stage
{
	DOOR_OPENING,
	DOOR_OPEN,
	DOOR_CLOSING,
	DOOR_CLOSE
}			t_stage;

typedef struct s_door_open
{
	char	*cell;
	t_stage	stage;
	float	stage_rate;
}			t_door_open;

typedef struct s_door
{
	char	open_type;
	float	thick;
	float	pos_edge;
	float	pos_edge_closed;
	float	pos_side_down;
	float	pos_side_up;
}			t_door;

typedef struct s_lenpos
{
	float	pos;
	double	len;
}			t_lenpos;

/* door_bonus.c */

float		door_get_closing_rate(t_door_open *door);
void		door_open(char *cell, t_door_open *door_open_list);
t_door_open	*door_find(char *cell, t_door_open *door_open_list);
void		door_init(t_door *door, char *cell, t_door_open *door_open_list);

/* door_open_list_bonus.c */

bool		door_open_list_update(t_door_open *door_open_list, t_time_us dt);
t_door_open	*door_open_list_add(char *cell, t_door_open *door_open_list);

/* door_inside_bonus.c */

bool		is_inside_door(t_axis x, t_ray *ray, t_position *start,
				t_door *door);

/* door_hit_bonus.c */

bool		is_hit_doorside(t_axis x, t_ray *ray, t_position *start,
				t_door *door);
bool		is_hit_dooredge(t_axis x, t_ray *ray, t_position *start,
				t_door *door);

/* door_utils_bonus.c */

t_axis		door_get_direction(const t_map *map, t_position position);
bool		is_in_closepart(float start_y, t_door *door);
bool		is_between_doorside(float start_x, t_door *door);
bool		is_outside_door(float start_x, float start_y, t_door *door);

#endif
