/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_map.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 16:10:08 by aska              #+#    #+#             */
/*   Updated: 2024/10/26 14:08:08 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LST_MAP_H
# define LST_MAP_H

# include "libft.h"
typedef struct s_lstmap
{
	char			*line;
	struct s_lstmap	*next;
	struct s_lstmap	*prev;
}					t_lstmap;

t_lstmap			*insert_end_lstmap(t_lstmap **head, char *line);
void				delete_node_lstmap(t_lstmap **head, t_lstmap *del_node);
void				delete_all_lstmap(t_lstmap **head);

#endif