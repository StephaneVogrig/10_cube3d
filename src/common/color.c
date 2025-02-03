/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 02:53:38 by svogrig           #+#    #+#             */
/*   Updated: 2025/02/03 21:27:33 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

void	color_darkened(t_rgb *color, int dark)
{
	if (dark)
	{
		color->integer >>= 2;
		color->integer &= 0xFF3F3F3F;
	}
}

static int	char_to_rgb(char *value, char **endptr, unsigned char *rgb)
{
	int	c;

	c = cub_strtoi(value, endptr);
	if (value == *endptr || c < 0 || c > 255)
		return (FAIL);
	*rgb = (unsigned char)c;
	skip_blank(endptr);
	if (**endptr == '\0' || **endptr == ',')
		return (SUCCESS);
	else
		return (FAIL);
	return (SUCCESS);
}

int	color_set_rgb(t_rgb *rgb, char *value)
{
	int		exit_code;
	char	*current;
	char	*endptr;

	current = value;
	endptr = NULL;
	exit_code = char_to_rgb(current, &endptr, &rgb->r);
	if (exit_code == FAIL || *endptr == '\0')
		return (ft_return(ERROR, FAIL, "Invalid color", value));
	current = endptr + 1;
	exit_code = char_to_rgb(current, &endptr, &rgb->g);
	if (exit_code == FAIL || *endptr == '\0')
		return (ft_return(ERROR, FAIL, "Invalid color", value));
	current = endptr + 1;
	exit_code = char_to_rgb(current, &endptr, &rgb->b);
	if (exit_code == FAIL || *endptr != '\0')
		return (ft_return(ERROR, FAIL, "Invalid color", value));
	rgb->a = 255;
	return (SUCCESS);
}
