/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 22:47:44 by aska              #+#    #+#             */
/*   Updated: 2025/01/30 14:44:18 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "coordinate.h"
#include <math.h>

int	extract_coordinate_sprite(t_sprite_lst **sprite_lst, t_lstmap **tmp, int id)
{
	*tmp = (*tmp)->next;
	if (tmp == NULL || (*tmp)->line[0] != '[')
		return (ft_return(ERROR, FAIL, "No coordinate for sprite", 
					(*tmp)->prev->line));
	while (tmp != NULL && (*tmp)->line[0] == '[')
	{
		if (set_sprite_coordinate((*tmp)->line, sprite_lst, id) == SUCCESS)
			*tmp = (*tmp)->next;
		else
			return (FAIL);
	}
	return (SUCCESS);
}

static double	build(t_build_double *build)
{
	build->result = build->integer + (build->decimal / pow(10, ft_intlen(build->decimal, 0)));
	return (build->result);
}

static void	skip_blank(char **str)
{
	if (!str)
		return ;
	while (ft_isspace(**str))
		(*str)++;
}

static int	extract_coordinate(char *line, char **endptr, t_build_double *build)
{
	char	*current;

	line++;
	build->integer = cub_strtoi(line, endptr);
	if (line == *endptr || build->integer == INT_MAX)
		return (FAIL);
	if (ft_isthis(**endptr, ".,"))
	{
		(*endptr)++;
		current = *endptr;
		build->decimal = cub_strtoi(current, endptr);
		if (line == *endptr || build->decimal == INT_MAX || build->decimal < 0)
			return (FAIL);
	}
	else if (ft_isthis(**endptr, ";]"))
	{
		build->decimal = 0;
		return (SUCCESS);
	}
	skip_blank(endptr);
	if (**endptr != ';' && **endptr != ']')
		return (FAIL);
	return (SUCCESS);
}

int	set_sprite_coordinate(char *line, t_sprite_lst **head, int id)
{
	t_build_double	x;
	t_build_double	y;
	char			*current;
	char			*endptr;

	current = line;
	if (extract_coordinate(current, &endptr, &x) != SUCCESS)
		return (ft_return(ERROR, FAIL, "Invalid coordinate X position", line));
	if (*endptr != ';')
		return (ft_return(ERROR, FAIL, "Invalid coordinate separator", line));
	current = endptr;
	if (extract_coordinate(current, &endptr, &y) != SUCCESS)
		return (ft_return(ERROR, FAIL, "Invalid coordinate Y position", line));
	if (*endptr != ']' || *(endptr + 1) != '\0')
		return (ft_return(ERROR, FAIL, "Invalid coordinate end line symbol \"]\"", line));
	insert_sprite_lst(head, build(&x), build(&y), id);
	return (SUCCESS);
}
