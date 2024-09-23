/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stephane <stephane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 19:11:26 by stephane          #+#    #+#             */
/*   Updated: 2024/09/23 22:16:23 by stephane         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef TEXTURE_H
# define TEXTURE_H

# include "mlx.h"
# include "typedef.h"
# include "stdio.h"

typedef struct s_texture
{
	void	*mlx;
	void	*img;
	int		width;
	int		height;
}	t_texture;

typedef struct s_textures{
	t_texture	north;
	t_texture	south;
	t_texture	east;
	t_texture	west;
} t_textures;

int		texture_setup(t_texture *t, void *mlx, char *path);
void	textures_clean(t_textures *t, void *mlx);
int	texture_jpg_setup(t_texture *t, void *mlx, char *path);

#endif
