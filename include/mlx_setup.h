/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_setup.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 06:19:04 by aska              #+#    #+#             */
/*   Updated: 2024/11/23 16:37:19 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef MLX_SETUP_H
# define MLX_SETUP_H

# include "libft.h"
# include "mlx.h"
# include "textures_bonus.h"
# include "lstmap_extraction_bonus.h"
#include "window.h"

int						mlx_setup(t_window *win, t_tex_path *tex_path,
							t_textures *textures);
void					tex_path_clean(t_tex_path *tex_path);

#endif