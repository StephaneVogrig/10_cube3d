/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_update_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 01:27:28 by svogrig           #+#    #+#             */
/*   Updated: 2024/12/22 19:40:31 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "sprite_bonus.h"

int	sprite_update_state(float *state, int nbr_state, t_time_us dt)
{
	int	state_start;

	if (nbr_state == 1)
		return (FALSE);
	state_start = (int)*state;
	*state += 25 * (float)dt / USECOND_PER_SECOND;
	if (*state >= nbr_state)
		*state -= (nbr_state);
	if ((int)*state == state_start)
		return (FALSE);
	return (TRUE);
}

int	sprite_update(t_sprite *sprite, t_time_us dt)
{
	int render_needed;
	int	i;

	render_needed = FALSE;
	i = 0;
	while (i < sprite->nbr)
	{
		render_needed |= sprite_update_state(&sprite->state[i], sprite->nbr_state[i], dt);
		i++;
	}
	return (render_needed);	
}
