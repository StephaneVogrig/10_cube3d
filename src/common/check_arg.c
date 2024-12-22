/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 04:12:46 by aska              #+#    #+#             */
/*   Updated: 2024/12/22 13:47:54 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_arg.h"

int	check_entry_arg(int ac, char **av)
{
	char *ext;
	
	// if (ac != 2)
	// 	return (ft_return(ERROR, 3, INVALID_NUM_OF_ARG));
	(void)ac;
	ext = ft_strrchr(av[1], '.');
	if (ext == NULL || ft_strcmp(ext, ".cub") != 0)
		return (ft_return(ERROR, 4, NO_CUB_EXT));
	return (SUCCESS);
}

int	check_line(char *line)
{
	if (line == NULL)
		return (ERROR);
	if (is_empty(line) == TRUE || is_map_valid(line) == FALSE)
		return (ft_return(ERROR, 272, "Invalid character on map"));
	return (SUCCESS);
}

int	is_valid_color(char *rgb)
{
	int	i;
	int	rgb_len;
	int	atoi_rgb;

	rgb_len = ft_strlen(rgb);
	if (rgb_len > 3)
		return (FALSE);
	i = 0;
	while (rgb[i])
		if (ft_isdigit(rgb[i++]) == FALSE)
			return (FALSE);
	atoi_rgb = ft_atoi(rgb);
	if (atoi_rgb < 0 || atoi_rgb > 255)
		return (FALSE);
	return (TRUE);
}