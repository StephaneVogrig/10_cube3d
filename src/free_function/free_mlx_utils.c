/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mlx_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 20:07:53 by aska              #+#    #+#             */
/*   Updated: 2024/08/03 20:19:32 by aska             ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../../include/cub3d.h"

void free_mlx_img(t_cub *cub)
{
    if (cub->img != NULL)
    {
        if (cub->img->no != NULL)
            mlx_destroy_image(cub->mlx, cub->img->no);
        if (cub->img->so != NULL)
            mlx_destroy_image(cub->mlx, cub->img->so);
        if (cub->img->we != NULL)
            mlx_destroy_image(cub->mlx, cub->img->we);
        if (cub->img->ea != NULL)
            mlx_destroy_image(cub->mlx, cub->img->ea);
        if (cub->img->f != NULL)
            mlx_destroy_image(cub->mlx, cub->img->f);
        if (cub->img->c != NULL)
            mlx_destroy_image(cub->mlx, cub->img->c);
    }
    cub->img->no_path = ft_char_f(cub->img->no_path);
    cub->img->so_path = ft_char_f(cub->img->so_path);
    cub->img->we_path = ft_char_f(cub->img->we_path);
    cub->img->ea_path = ft_char_f(cub->img->ea_path);
    cub->img->f_path = ft_char_f(cub->img->f_path);
    cub->img->c_path = ft_char_f(cub->img->c_path);
    cub->img->bgm_path = ft_char_f(cub->img->bgm_path);
}

void free_mlx_win(t_cub *cub)
{
    if (cub->win != NULL)
    {
        if (cub->win->w_game != NULL)
            mlx_destroy_window(cub->mlx, cub->win->w_game);
        if (cub->win->w_mini != NULL)
            mlx_destroy_window(cub->mlx, cub->win->w_mini);
    }
}