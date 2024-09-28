/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_map.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 16:10:08 by aska              #+#    #+#             */
/*   Updated: 2024/09/27 01:53:35 by aska             ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef LST_MAP_H
# define LST_MAP_H

typedef struct s_lstmap
{
	char			*line;
	struct s_lstmap	*next;
	struct s_lstmap	*prev;
}					t_lstmap;

void				insert_front_lstmap(t_lstmap **head, char *line);
void				insert_after_lstmap(t_lstmap *prev_node, char *line);
void				insert_end_lstmap(t_lstmap **head, char *line);
void				display_lstmap(t_lstmap *node);
void				delete_lstmap(t_lstmap **head, t_lstmap *del_node);
void				delete_all_lstmap(t_lstmap **head);
void				explicit_display_all_dlst_node(t_lstmap *node);
int					is_empty_line(char *line);
int					is_map_valid(char *line);

#endif