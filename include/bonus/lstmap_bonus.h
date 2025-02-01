/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstmap_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 21:06:08 by aska              #+#    #+#             */
/*   Updated: 2025/02/01 17:21:43 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LSTMAP_BONUS_H
# define LSTMAP_BONUS_H

# include "libft.h"
# include "parsing_utils.h"
# include "lstmap.h"

void	next_line_not_empty(t_lstmap **tmp);
t_bool	next_valid_asset(t_lstmap **tmp);

#endif