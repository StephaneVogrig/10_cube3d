/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictionarie.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 23:08:55 by aska              #+#    #+#             */
/*   Updated: 2024/11/27 03:20:20 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DICTIONARIE_H
# define DICTIONARIE_H

# include "libft.h"
# include "texture.h"

typedef struct s_dictionarie
{
	char					*key;
	char					*path;
	t_texture				*texture;
	struct s_dictionarie	*next;
}							t_dictionarie;

int							dict_insert(t_dictionarie **dict, char *key,
								void *value);
char						*dict_get(t_dictionarie *dict, char *key);
void						dict_destroy(t_dictionarie **dict);

#endif