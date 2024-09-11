/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 02:34:42 by aska              #+#    #+#             */
/*   Updated: 2024/09/11 14:38:36 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../lib/MacroLibx/includes/mlx.h"
# include "../lib/MacroLibx/includes/mlx_profile.h"
# include "../lib/libft-plus/libft.h"
# include "init.h"
# include "msg.h"
# include "typedef.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <unistd.h>

#define BLOK 35
#define MEDIUM_BLOK 43
#define FLOOR 32

void	title(void);

/**
 * @brief Check a fd is open
 *
 * @param fd fd for test
 * @param msg print information message
 * @return int
 */
int		check_open_path(int fd, char *msg);
void	helltrain(t_cub *cub, t_state state, int return_code, char *msg);
void	debug(t_cub *cub);
void	print_tab(char **tab);
int		attrib_path(t_cub *cub, char *key, char *value);
char	*path_seletor(t_cub *cub, char *key, char *img_path);
int		return_value(t_cub *cub, char *line, char *key, char **value);
int		return_key(t_cub *cub, char *line, char **key);
void	init_organizer(t_cub *cub, char *file);
int		asset_discovery(t_cub *cub);
void	entry_arg_checker(int ac, char **av);
int		mlx_initialize(t_cub *cub);
int		open_cub(t_cub *cub, char *file);
void	goto_exit(int check, int err, t_state state, char *msg);
void    mlx_free(t_cub *cub);
int     init_map_process(t_cub *cube);
void    get_max_map_size(t_cub *cube);
char    get_blok_type(t_cub *cube, char c, int x, int y);
int	    is_empty_line(char *line);
int	    is_map_valid(char *line);
int     map_creation(t_cub *cube);
int     set_var_creation_map(t_cub *cube);
int	    map_checker(t_cub *cub);
int	    set_var_creation_map_ff(t_cub *cub);
void	chk_flood_fill(t_cub *cub, int x, int y);


void	insert_front_lstmap(t_lstmap **head, char *line);
void	insert_after_lstmap(t_lstmap *prev_node, char *line);
void	insert_end_lstmap(t_lstmap **head, char *line);
void	display_lstmap(t_lstmap *node);
void	delete_lstmap(t_lstmap **head, t_lstmap *del_node);
void	delete_all_lstmap(t_lstmap **head);
void	explicit_display_all_dlst_node(t_lstmap *node);


void free_mlx_img(t_cub *cub);
void free_mlx_win(t_cub *cub);

#endif