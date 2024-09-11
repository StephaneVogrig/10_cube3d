/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 02:16:47 by aska              #+#    #+#             */
/*   Updated: 2024/09/11 17:29:08 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int main(int ac, char **av)
{
    t_cub *cub;
    
    title();
    check_entry_arg(ac, av);
    cub = ft_calloc(1, sizeof(t_cub));
	if (cub == NULL)
		ft_exit(ERROR, 1, "Allocation For Struct 'cub'");
    init_organizer(cub, av[1]);
    debug(cub);
    helltrain(cub, INFO, 0, "END OF PROGRAM");
    return (SUCCESS);
}
