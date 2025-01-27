/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_setup_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 06:19:04 by aska              #+#    #+#             */
/*   Updated: 2025/01/27 16:07:03 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_SETUP_BONUS_H
# define MLX_SETUP_BONUS_H

# include "asset_bonus.h"
# include "libft.h"
# include "lstmap_extraction_bonus.h"
# include "mlx.h"
# include "window.h"

int		mlx_setup(t_window *win, t_asset *textures, t_asset_lst **head);
void	tex_path_clean(t_tex_path *tex_path);

#endif