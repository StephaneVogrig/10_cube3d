/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 17:13:43 by aska              #+#    #+#             */
/*   Updated: 2024/12/27 23:10:38 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"

void print_exit_code(int exit_code)
{
	if (exit_code == SUCCESS)
		ft_printf("%i\t: "HGRN"SUCCESS\n"CRESET, exit_code);
	else if (exit_code == FAIL)
		ft_printf("%i\t: "HRED"FAIL\n"CRESET, exit_code);
	else
		ft_printf("%i\t: "HYEL"OTHER\n"CRESET, exit_code);
}

void print_buffer(t_texture *t)
{
	int i;

	i = 0;
	while (i < t->height * t->width)
	{
		ft_printf("%i\t", i);
		ft_printf("%i\n", t->buffer[i]);
		i++;
	}
}

void print_texture(t_texture *t)
{
	if (t == NULL)
	{
		printf("texture is NULL\n");
		return ;
	}
	printf(HYEL"texture = %p\t| ", t);
	printf("width: %i,\theight: %i\n", t->width, t->height);
	printf("buffer = %p\n" CRESET, t->buffer);
	print_buffer(t);
}

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

void	map_print_ptr(t_map *map)
{
	int i;

	printf("tab_ptr = %p\n", map->grid);
	printf("-------------------------------------------------------------\n");
	i = 0;
    while (map->grid[i] != NULL)
    {
        printf("ptr = %p\n", map->grid[i]);
        i++;
    }
	printf("-------------------------------------------------------------\n");
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
	printf("lst_map -----------------\n");
	while (lstmap)
	{
		printf("%s\n", lstmap->line);
		lstmap = lstmap->next;
	}
	printf("lst_map ----------------- end\n");
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