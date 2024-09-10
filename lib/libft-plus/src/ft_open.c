/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 04:35:10 by aska              #+#    #+#             */
/*   Updated: 2024/07/10 05:15:18 by aska             ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../libft.h"

int    ft_open(char *pathname, int flag)
{
    int fd;

    fd = open(pathname, flag);
    if (fd == -1 )
        return (-1);
    if (DEBUG_MODE >= 3)
        ft_printf(BLU"OPEN\t: "HBLU"fd = %d\t" CRESET":%s\n", fd,pathname);
    return (fd);
}