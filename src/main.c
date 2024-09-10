/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 02:16:47 by aska              #+#    #+#             */
/*   Updated: 2024/09/08 22:33:01 by aska             ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../include/cub3d.h"

int main(int ac, char **av)
{
    t_cub *cub;
    
    title();
    cub = ft_calloc(1, sizeof(t_cub));
	if (cub == NULL)
		ft_exit(ERROR, 1, "Allocation For Struct 'cub'");
    entry_arg_checker(ac, av);
    init_organizer(cub, av[1]);
    debug(cub);
    helltrain(cub, INFO, 0, "END OF PROGRAM");
    return (SUCCESS);
}
