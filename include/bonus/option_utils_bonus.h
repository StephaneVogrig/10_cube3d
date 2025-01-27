/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_utils_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 16:11:00 by aska              #+#    #+#             */
/*   Updated: 2025/01/27 16:11:03 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPTION_UTILS_BONUS_H
# define OPTION_UTILS_BONUS_H

# include "libft.h"
# include "lstmap_extraction_utils_bonus.h"
# include "option_bonus.h"

typedef struct s_option
{
	int		win_width;
	int		win_height;
	float	fov;
	t_bool	minimap;
}			t_option;

int			option_tokenizer(char **key, char **value, char *line);
int			option_get_resolution(t_option *option, char *resolution);
int			is_valid_resolution(char *resolution);
void		print_option(t_option *option);
int			print_help(void);

#endif