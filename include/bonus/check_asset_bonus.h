/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_asset_bonus.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 02:54:44 by aska              #+#    #+#             */
/*   Updated: 2025/01/27 16:04:03 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_ASSET_BONUS_H
# define CHECK_ASSET_BONUS_H

# include "asset_lst_bonus.h"
# include "libft.h"

char	chk_save_cell(char cell);
int		cmp_cell_line_to_asset_key(char *line, t_asset_lst *asset_lst);

#endif