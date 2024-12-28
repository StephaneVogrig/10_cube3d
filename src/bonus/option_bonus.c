/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 01:30:59 by aska              #+#    #+#             */
/*   Updated: 2024/12/28 22:17:11 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "option_bonus.h"

void    option_init_default(t_option *option)
{
    option->win_width = WIN_W;
    option->win_height = WIN_H;
    option->fov = 1;
    option->minimap = FALSE;
}

int    option_init(t_option *option, int ac, char **av)
{
    int i;
    int exit_code;
    t_key_value argument;

    if (ac < 2)
        return (print_help());
    i = 2;
    exit_code = 0;
    option_init_default(option);
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

