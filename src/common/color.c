/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 02:53:38 by svogrig           #+#    #+#             */
/*   Updated: 2025/01/30 12:41:33 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

int	color_darkened(int color, int dark)
{
	if (dark)
		return ((color >> 2) & 0xFF3F3F3F);
	return (color);
}

static void	skip_blank(char **str)
{
	if (!str)
		return ;
	while (ft_isspace(**str))
		(*str)++;
}

static int	char_to_rgb(char *value, char **endptr, unsigned char *rgb)
{
	int c;
	
	c = cub_strtoi(value, endptr);
	if (c < 0 || c > 255)
		return (FAIL);
	*rgb = (unsigned char)c;
	skip_blank(endptr);
	if (**endptr == ',')
		(*endptr)++;
	else if (**endptr == '\0')
		return (SUCCESS);
	else
		return (FAIL);
	return (SUCCESS);
}

int	color_set_rgb(t_rgb *rgb, char *value)
{
	int		exit_code;
	char	*tmp_value;
	char	*endptr;

	tmp_value = value;
	endptr = NULL;
	exit_code = char_to_rgb(value, &endptr, &rgb->r);
	if (exit_code == FAIL || *endptr == '\0')
		return (ft_return(ERROR, FAIL, "Invalid color", value));
	tmp_value = endptr;
	exit_code = char_to_rgb(tmp_value, &endptr, &rgb->g);
	if (exit_code == FAIL || *endptr == '\0')
		return (ft_return(ERROR, FAIL, "Invalid color", value));
	tmp_value = endptr;
	exit_code = char_to_rgb(tmp_value, &endptr, &rgb->b);
	if (exit_code == FAIL)
		return (ft_return(ERROR, FAIL, "Invalid color", value));
	rgb->a = 255;
	return (SUCCESS);
}

int color_set_rgb_2(t_rgb *rgb, char *str)
{
	char *current;
	char *endptr;

	rgb->a = 255;
	
	current = str;
	rgb->r = cub_strtoi(current, &endptr);
	if (current == endptr || rgb->r < 0 || rgb->r >255)
		return (ft_return(ERROR, FAIL, "Invalid color red", str));
	
	current = endptr;
	skip_blank(&current);
	if (*current != '.' && *current != ',')
		return (ft_return(ERROR, FAIL, "Invalid color", str));
	current++;

	rgb->g = cub_strtoi(current, &endptr);
	if (current == endptr || rgb->g < 0 || rgb->g >255)
		return (ft_return(ERROR, FAIL, "Invalid color red", str));

	current = endptr;
	skip_blank(&current);
	if (*current != '.' && *current != ',')
		return (ft_return(ERROR, FAIL, "Invalid color", str));
	current++;

	rgb->b = cub_strtoi(current, &endptr);
	if (current == endptr || rgb->b < 0 || rgb->b >255)
		return (ft_return(ERROR, FAIL, "Invalid color red", str));

	
	skip_blank(&endptr);
	if (*endptr != '\0')
		return (ft_return(ERROR, FAIL, "Invalid color red", str));
	return (SUCCESS);	
}
