/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 01:30:59 by aska              #+#    #+#             */
/*   Updated: 2024/12/23 03:13:12 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "option_bonus.h"

int    option_init(t_option *option, int ac, char **av)
{
    int i;
    t_key_value argument;
    int exit_code;

    i = 2;
    exit_code = 0;
    option->win_width = 1280;
    option->win_height = 768;
    option->fov = 1;
    option->minimap = FALSE;

    while (i < ac)
    {
        exit_code = option_tokenizer(&argument.key, &argument.value, av[i++]);
        if (exit_code == SUCCESS && ft_strcmp(argument.key, "--resolution") == 0)
            option_get_resolution(option, argument.value);
        else if (exit_code == SUCCESS && ft_strcmp(argument.key, "--fov") == 0 && is_valid_color(argument.value))
            option->fov = ft_atoi(argument.value);
        else if (ft_strcmp(argument.key, "--minimap") == 0)
            option->minimap = TRUE;
        else
            return (print_help());
    }
    return (exit_code);
}

