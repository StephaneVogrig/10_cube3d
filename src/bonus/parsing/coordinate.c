/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaiffie <ygaiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 22:47:44 by aska              #+#    #+#             */
/*   Updated: 2025/01/29 17:46:35 by ygaiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "coordinate.h"
#include "math.h"

int	extract_coordinate_sprite(t_sprite_lst **sprite_lst, t_lstmap **tmp, int id)
{
	*tmp = (*tmp)->next;
	if (tmp == NULL || (*tmp)->line[0] != '[')
		return (ft_return(ERROR, FAIL, "No coordinate for sprite"));
	while (tmp != NULL && (*tmp)->line[0] == '[')
	{
		if (set_sprite_coordinate((*tmp)->line, sprite_lst, id) == SUCCESS)
			*tmp = (*tmp)->next;
		else
			return (FAIL);
	}
	return (SUCCESS);
}

static double	custom_atof(char *str)
{
	char	*tmp;
	double	integer;
	double	decimal;
	int		sign;

	sign = 1;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	tmp = str;
	while (*str != '.' && *str != ',' && *str != '\0')
		str++;
	if (*str == '\0')
		return ((double)ft_atoi(tmp));
	*str = '\0';
	integer = ft_atoi(tmp);
	tmp = ++str;
	while (*str != '.' && *str != ',' && *str != '\0')
		str++;
	*str = '\0';
	decimal = ft_atoi(tmp);
	return (sign * (integer + (decimal / pow(10, ft_intlen(decimal, 0)))));
}

static t_bool	is_valid_coordinate(char c)
{
	if (c == ';' && c == ']' && c == '\0')
		return (FALSE);
	if (ft_isthis(c, "-0123456789.,") == FALSE)
		return (FALSE);
	return (TRUE);

}

static int	extract_raw_coordinate(char *line, char **x, char **y)
{
	line++;
	*x = line;
	if (is_valid_coordinate(*line) == FALSE)
		return (FAIL);
	while (*line != ';' && *line != '\0')
		if (is_valid_coordinate(*line++) == FALSE)
			return (FAIL);
	*line = '\0';
	line++;
	*y = line;
	while (*line != ']' && *line != '\0')
		if (is_valid_coordinate(*line++) == FALSE)
			return (FAIL);
	if (*++line != '\0')
		return (FAIL);
	return (SUCCESS);
}

int	set_sprite_coordinate(char *line, t_sprite_lst **head, int id)
{
	char	*x;
	char	*y;
	t_vec2d	result;
	int		exit_code;

	exit_code = extract_raw_coordinate(line, &x, &y);
	if (exit_code != SUCCESS)
		return (ft_return(ERROR, FAIL, "Invalid coordinate"));
	result.x = custom_atof(x);
	result.y = custom_atof(y);
	insert_sprite_lst(head, result.x, result.y, id);
	return (SUCCESS);
}
