/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaiffie <ygaiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 20:01:25 by aska              #+#    #+#             */
/*   Updated: 2024/10/02 12:26:22 by ygaiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flood_fill.h"

void	print_tabl(char **tab, int height, int width)
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (tab[i][j] == '\0')
			{
				printf(".");
			}
			else
			{
				printf("%c", tab[i][j]);
			}
		}
		printf("\n");
	}
}

void	clear_screen(void)
{
	// Séquence d'échappement ANSI pour effacer l'écran
	printf("\033[H\033[J");
}

void	print_char_array(char **array, int size)
{
	clear_screen(); // Efface l'écran avant d'imprimer
	for (int j = 0; j < size; j++)
	{
		printf("%s\n", array[j]);
	}
	fflush(stdout); // On force l'affichage immédiat
	usleep(10000);  // Pause d'une seconde pour voir l'évolution
}

int	map_checker(t_map *map, t_player *player)
{
	char	**map_ff;
	t_bool	ff_ok;

	ff_ok = TRUE;
	map_ff = set_var_creation_map_ff(map);
	if (map_ff == NULL)
		return (ft_return(ERROR, ERROR, "Error on Initialization Map"));
	print_tabl(map_ff, map->height + 2, map->width + 2);
	if (chk_box(player_finder(map, player), EQ, SUCCESS, "Find player") == -1)
		return (ft_return(ERROR, ERROR, "No player on map"));
	map_ff[player->grid.y][player->grid.x] = '0';
	map->grid[player->grid.y][player->grid.x] = '0';
	// print_char_array(map_ff, 7);
	ft_exit(INFO, 1, "map_checker");
	chk_flood_fill(map_ff, player->grid.x, player->grid.y, &ff_ok);
	printf("ff_ok = %d\n", ff_ok);
	if (ff_ok == FALSE)
		return (ft_return(ERROR, ERROR, "Map Invalid"));
	ft_tab_f(map_ff);
	return (SUCCESS);
}

char	**set_var_creation_map_ff(t_map *map)
{
	int		y;
	char	**map_ff;

	y = 0;
	map_ff = ft_calloc(map->height + 2, sizeof(char *));
	if (map_ff == NULL)
		return (NULL);
	while (y != map->height + 2)
	{
		map_ff[y] = ft_calloc(map->width + 2, sizeof(char));
		if (map_ff[y] == NULL)
			return (NULL);
		if (y != 0 && y != map->height + 1)
		{
			printf("map->grid[%d] = %s\n", y - 1, map->grid[y - 1]);
			ft_memcpy(map_ff[y] + 1, map->grid[y - 1], map->width);
		}
		else
			fprintf(stderr, "Erreur: map->grid[%d] est NULL\n", y - 1);
		y++;
		print_tab(map_ff);
		return (map_ff);
	}
	return (map_ff);
}

void	chk_flood_fill(char **map_ff, int x, int y, t_bool *ff_ok)
{
	if (map_ff[y][x] == 'X' || map_ff[y][x] == '1')
		return ;
	if (map_ff[y][x] == ' ' || map_ff[y][x] == 0)
	{
		ff_ok = FALSE;
		return ;
	}
	map_ff[y][x] = 'X';
	chk_flood_fill(map_ff, x + 1, y, ff_ok);
	chk_flood_fill(map_ff, x - 1, y, ff_ok);
	chk_flood_fill(map_ff, x, y + 1, ff_ok);
	chk_flood_fill(map_ff, x, y - 1, ff_ok);
}
