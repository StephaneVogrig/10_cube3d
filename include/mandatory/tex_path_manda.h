/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tex_path_manda.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaiffie <ygaiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 16:06:57 by aska              #+#    #+#             */
/*   Updated: 2025/02/04 16:40:45 by ygaiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEX_PATH_MANDA_H
# define TEX_PATH_MANDA_H

# include "libft.h"
# include "key_value.h"
# include "parsing_utils.h"
# include "stdbool.h"
# include "file_utils.h"
# include "check_arg.h"

typedef struct s_tex_path
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
}			t_tex_path;

void	tex_path_clean(t_tex_path *tex_path);
int		set_path(char *root_path, t_key_value *kv, t_tex_path *tex_path);

#endif