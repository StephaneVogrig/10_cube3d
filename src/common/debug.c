/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaiffie <ygaiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 17:13:43 by aska              #+#    #+#             */
/*   Updated: 2024/10/24 17:18:51 by ygaiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"

void    print_tab(char **tab)
{
    int i;

    i = 0;
    while (tab[i] != NULL)
    {
        ft_printf("%s\n", tab[i]);
        i++;
    }
}

void textures_print_ptr(t_textures *textures)
{
	printf("north: %p\n", textures->north.img);
	printf("south: %p\n", textures->south.img);
	printf("west: %p\n", textures->west.img);
	printf("east: %p\n", textures->east.img);
}

void	map_print(t_map *map)
{
	printf("width: %i, height: %i\n", map->width, map->height);
	printf("-------------------------------------------------------------\n");
	print_tab(map->grid);
	printf("-------------------------------------------------------------\n");
}

void	lstmap_print(t_lstmap *lstmap)
{
	while (lstmap)
	{
		printf("%s\n", lstmap->line);
		lstmap = lstmap->next;
	}
}

// void    print_t_rgb(t_rgb *rgb)
// {
//     ft_printf(HRED"R "CRESET"= %d\t| ", rgb->r);
//     ft_printf(HGRN"G "CRESET"= %d\t| ", rgb->g);
//     ft_printf(HBLU"B "CRESET"= %d\n", rgb->b);
// }

// void    print_all_path(t_cub *cub)
// {
//     ft_printf("path->no_path = %s\n", cub->img->no_path);
//     ft_printf("path->so_path = %s\n", cub->img->so_path);
//     ft_printf("path->we_path = %s\n", cub->img->we_path);
//     ft_printf("path->ea_path = %s\n", cub->img->ea_path);
//     if (cub->img->c_path != NULL)
//         ft_printf("path->c_path = %s\n", cub->img->c_path);
//     else
//     {
//         ft_printf("path->c_rgb = ");
//         print_t_rgb(&cub->img->c_rgb);
//     }
//     if (cub->img->f_path != NULL)
//         ft_printf("path->f_path = %s\n", cub->img->f_path);
//     else
//     {
//         ft_printf("path->f_rgb = ");
//         print_t_rgb(&cub->img->f_rgb);
//     }
//     ft_printf("path->bgm_path = %s\n", cub->img->bgm_path);
// }

// void print_tab_map(char **tab)
// {
//     int i;

//     i = 0;
//     while (tab[i] != NULL)
//     {
//         ft_printf("%s\n", tab[i]);
//         i++;
//     }
// }

// void debug(t_cub *cub)
// {
//     ft_printf(BHWHT"DEBUG\n"CRESET);
//     print_all_path(cub);
//     // display_lstmap(cub->map);
//     print_tab_map(cub->map_tab);
//     ft_printf(BHWHT"END DEBUG\n"CRESET);
// }