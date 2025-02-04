/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_asset_bonus.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaiffie <ygaiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 02:54:44 by aska              #+#    #+#             */
/*   Updated: 2025/02/04 22:15:11 by ygaiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_ASSET_BONUS_H
# define CHECK_ASSET_BONUS_H

# include <stdbool.h>
# include "asset_lst_bonus.h"
# include "asset_bonus.h"
# include "asset_lst_utils_bonus.h"
# include "libft.h"

char	chk_save_cell(char cell);
int		cmp_cell_line_to_asset_key(char *line, t_asset_lst *asset_lst);

#endif