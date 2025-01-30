/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:25:24 by ygaiffie          #+#    #+#             */
/*   Updated: 2024/07/10 04:50:28 by aska             ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../libft.h"

int	ft_close(int fd)
{
	if (fd != -1)
		fd = close(fd);
	if (DEBUG_MODE >= 3 && fd == 0)
		ft_printf(BYEL"CLOSE\t:" HYEL " fd = %i\n" CRESET, fd);
	else if (DEBUG_MODE >= 3)
		return (ft_return(ERROR, fd, "CLOSE", NULL));
	return (fd);
}
