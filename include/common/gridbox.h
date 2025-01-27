/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gridbox.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 14:55:27 by svogrig           #+#    #+#             */
/*   Updated: 2025/01/27 16:04:35 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRIDBOX_H
# define GRIDBOX_H

typedef struct s_gridbox
{
	int		grid;
	float	box;
}			t_gridbox;

void		gridbox_add_double(t_gridbox *gb, double d);
double		gridbox_to_double(t_gridbox gridbox);

#endif
