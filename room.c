/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvann <mvann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 22:05:53 by mvann             #+#    #+#             */
/*   Updated: 2018/06/29 16:45:36 by mvann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room	*get_room_at_name(t_list *list, char *name)
{
	while (list)
	{
		if (!ft_strcmp(((t_room*)list->content)->name, name))
			return ((t_room*)list->content);
		list = list->next;
	}
	return (NULL);
}

void	add_room(t_env *env, char *name, int x, int y)
{
	t_list **l;
	t_room room;

	room.name = ft_strdup(name);
	room.rooms = NULL;
	room.num_rooms = 0;
	room.x = x;
	room.y = y;
	room.d = -1;
	room.ant = NULL;
	l = &(env->rooms);
	if (*l)
		ft_lstadd(l, ft_lstnew(&room, sizeof(t_room)));
	else
		*l = ft_lstnew(&room, sizeof(t_room));
}
