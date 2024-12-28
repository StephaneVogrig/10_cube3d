/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 02:30:22 by aska              #+#    #+#             */
/*   Updated: 2024/12/27 19:31:21 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "option_utils_bonus.h"

int	is_valid_resolution(char *resolution)
{
	int	i;
	int	resolution_len;
	int	atoi_resolution;

	resolution_len = ft_strlen(resolution);
	if (resolution_len > 4)
		return (FALSE);
	i = 0;
	while (resolution[i])
		if (ft_isdigit(resolution[i++]) == FALSE)
			return (FALSE);
	atoi_resolution = ft_atoi(resolution);
	if (atoi_resolution < 480 || atoi_resolution > 8192)
		return (FALSE);
	return (TRUE);
}

int option_tokenizer(char **key, char **value, char *line)
{
   	*key = line;
	while (*line != '\0' && *line != '=')
		line++;
	if (*line == '\0')
		return(SUCCESS);
	*line = '\0';
	line++;
	if (*line == '\0')
	{
		*value = NULL;
		return(FAIL);
	}
	*value = line;
	return(SUCCESS);
}

int	option_get_resolution(t_option *option, char *resolution)
{
    char *width = NULL;
    char *height = NULL;

    width = resolution;
	while (*resolution != '\0' && *resolution != 'x')
		resolution++;
	if (*resolution == '\0')
		return (ft_return(ERROR, 264, "Invalid width in resolution"));
	*resolution = '\0';
	resolution++;
	if (*resolution == '\0')
		return (ft_return(ERROR, 265, "Invalid height in resolution"));
	height = resolution;
    if (is_valid_resolution(width) == FALSE || is_valid_resolution(height) == FALSE)
        return (ft_return(ERROR, 266, "Invalid resolution"));
    option->win_width = ft_atoi(width);
    option->win_height = ft_atoi(height);
    return (SUCCESS);
}

void print_option(t_option *option)
{
    printf("option->win_width: %d\n", option->win_width);
    printf("option->win_height: %d\n", option->win_height);
    printf("option->fov: %f\n", option->fov);
    printf("option->minimap: %d\n", option->minimap);
}

int print_help()
{
	printf("Usage: ./cub3d_bonus [map_path] (options)\n");
	printf("Options:\n");
	printf("--resolution=[width]x[height]\n");
	printf("--fov=[ratio]\t Value between 0 and 1\n");
	printf("--minimap\n");
	return (EXIT_FAILURE);
}
