/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asset.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:06:58 by aska              #+#    #+#             */
/*   Updated: 2024/11/26 02:35:34 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASSETS_H
# define ASSETS_H

# include "libft.h"
# include "dictionarie.h"
# include "img_mlx.h"
# include "color.h"
# include "mlx.h"

typedef struct s_img
{
	int			*buffer;
	int			width;
	int			height;
}				t_texture;

typedef struct s_assets
{
	t_dictionaries	*textures;
}				t_assets;

int	asset_get_color(t_assets *t, int x, int y);
int asset_load_to_buffer(void *mlx, t_texture *t, char *path);
#endif