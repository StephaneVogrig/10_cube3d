/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 01:30:59 by aska              #+#    #+#             */
/*   Updated: 2024/12/22 14:38:01 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "option_bonus.h"

t_option	*option_get_ptr(void)
{
	static t_option option;

	return (&option);
}

void print_option(t_option *option)
{
    printf("option->win_width: %d\n", option->win_width);
    printf("option->win_height: %d\n", option->win_height);
    printf("option->fov: %d\n", option->fov);
    printf("option->minimap: %d\n", option->minimap);
}

void    option_init(t_option *option, int ac, char **av)
{
    int i;
    t_key_value argument;

    i = 2;
    option->win_width = 1280;
    option->win_height = 768;
    option->fov = 1;
    option->minimap = FALSE;

    print_option(option);
    if (ac < 3)
        return;
    while (i < ac)
    {
        option_tokenizer(&argument.key, &argument.value, av[i]);
        if (ft_strcmp(argument.key, "--resolution") == 0)
            option_get_resolution(option, argument.value);
        else if (ft_strcmp(argument.key, "--fov") == 0 && is_valid_color(argument.value))
            option->fov = ft_atoi(argument.value);
        else if (ft_strcmp(argument.key, "--minimap") == 0)
            option->minimap = TRUE;
        i++;
    }
    print_option(option);
}
