/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaiffie <ygaiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 15:26:02 by ygaiffie          #+#    #+#             */
/*   Updated: 2025/02/04 15:28:02 by ygaiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_utils.h"

bool	is_folder(const char *path)
{
	int	fd;

	fd = open(path, O_DIRECTORY);
	if (fd == -1)
		return (false);
	close(fd);
	return (true);
}
