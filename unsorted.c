/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsorted.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvann <mvann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 18:19:00 by mvann             #+#    #+#             */
/*   Updated: 2018/06/26 20:24:49 by mvann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	move_ants()
{
	int i;
	t_room	*tmp_room;
	t_ant	*tmp_ant;

	i = 0;
	while (i < env->num_ants)
	{
		tmp_ant = get_ant_at(env, i);
		tmp_room = ant->room;
		
		i++;
	}
}

void	calculate_distances(t_env *env, t_room *room, int d)
{
	char	*curr_room;

	if (!ft_strcmp(room->name, env->start->name))
		room->d = room->d > d || room->d < 0 ? d : room->d;
	else if(room->d < 0 || room->d > d)
	{
		node->d = d;
		i = 0;
		while (i < room->num_rooms)
		{
			curr_room = get_name_at(room, i);
			calculate_distances(env,
				get_room_at_name(env->rooms, curr_room), d + 1);
		}
	}
}

t_ant	*get_ant_at(t_env *env, int i)
{
	t_list	*l;

	l = ft_lstat(env->ants, i);
	return ((t_ant*)&(l->content));
}

char	*get_name_at(t_room *room, 0)
{
	t_list	*l;

	l = ft_lstat(room->rooms, i);
	return ((char *)&(l->content));
}

void	add_name(t_room *room, char *name)
{
	t_list *list;

	(room->num_rooms)++;
	list = &(room->rooms);
	if (*list)
		lst_add(list, ft_lstnew(name, ft_strlen(name) + 1));
	else
		*list = ft_lstnew(name, ft_strlen(name) + 1));
}

t_room	*get_room_at_name(*list, *name)
{
	while(list)
	{
		if (!ft_strcmp(list->content->name, name))
			return ((t_room*)&(list->content));
		list = list->next;
	}
	return (NULL);
}

void	add_room(t_env *env, char *name, int x, int y)
{
	t_list **l;
	t_room room;

	room.name = ft_strcpy(name);
	room.rooms = NULL;
	room.num_rooms = 0;
	room.x = x;
	room.y = y;
	room.d = -1;
	l = &(env->rooms);
	if (*l)
		ft_lstadd(l, ft_lstnew(&room, sizeof t_room));
	else
		*l = ft_lstnew(&room, sizeof t_room);
}

void	add_ants(t_env *env)
{
	t_list	**l;
	int		i;
	t_ant	ant;

	ant.room = env->start;
	ant.i = 0;
	l = &(env->ants);
	*l = ft_lstnew(ant, sizeof (t_ant));
	i = 1;
	while (i < env->num_ants)
	{
		ant.i = i;
		ft_lstadd(l, ft_lstnew(ant, sizeof (t_ant)));
		i++;
	}
}
