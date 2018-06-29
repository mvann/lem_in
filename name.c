/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   name.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvann <mvann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 22:40:11 by mvann             #+#    #+#             */
/*   Updated: 2018/06/28 18:48:45 by mvann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char	*get_name_at(t_room *room, int i)
{
	t_list	*l;

	l = ft_lstat(i, room->rooms);
	return ((char *)l->content);
}

void	add_name(t_room *room, char *name)
{
	t_list **list;

	(room->num_rooms)++;
	list = &(room->rooms);
	if (*list)
		ft_lstadd(list, ft_lstnew(name, ft_strlen(name) + 1));
	else
		*list = ft_lstnew(name, ft_strlen(name) + 1);
}
