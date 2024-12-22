/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 02:30:22 by aska              #+#    #+#             */
/*   Updated: 2024/12/22 07:55:55 by aska             ###   ########.fr       */
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

void option_tokenizer(char **key, char **value, char *line)
{
   	*key = line;
	while (*line != '\0' && *line != '=')
		line++;
	if (*line == '\0')
		ft_display(ERROR, "Invalid option");
	*line = '\0';
	line++;
	if (*line == '\0')
		ft_display(ERROR, "No Value in option");
	*value = line;
}

int	option_get_resolution(t_option *option, char *resolution)
{
    char *width = NULL;
    char *height = NULL;

	printf("resolution: %s\n", resolution);
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
	printf("width: %s\n", width);
    if (is_valid_resolution(width) == FALSE || is_valid_resolution(height) == FALSE)
        return (ft_return(ERROR, 266, "Invalid resolution"));
    option->win_width = ft_atoi(width);
    option->win_height = ft_atoi(height);
    return (SUCCESS);
}