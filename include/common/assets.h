/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaiffie <ygaiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:06:58 by aska              #+#    #+#             */
/*   Updated: 2024/11/26 12:12:45 by ygaiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASSETS_H
# define ASSETS_H

# include "dictionarie.h"
# include "texture.h"

typedef struct s_assets
{
	t_dictionarie	*entry;
	char **array_key;
	t_texture *array_value;
}				t_assets;

int		asset_load_to_buffer(void *mlx, t_texture *t, char *path);
void 	array_init(t_assets *assets, t_dictionarie *dict);

#endif