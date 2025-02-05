/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 17:38:38 by aska              #+#    #+#             */
/*   Updated: 2025/01/30 17:38:41 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_close(int fd)
{
	if (fd != -1)
		fd = close(fd);
	if (DEBUG_MODE >= 3 && fd == 0)
		ft_printf(BYEL "CLOSE\t:" HYEL " fd = %i\n" CRESET, fd);
	else if (DEBUG_MODE >= 3)
		return (ft_return(ERROR, fd, "CLOSE", NULL));
	return (fd);
}
