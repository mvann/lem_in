/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvann <mvann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 22:13:41 by mvann             #+#    #+#             */
/*   Updated: 2018/06/28 21:11:55 by mvann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	print_farm(t_env *env)
{
	t_list	*tmp_list;
	t_room	*tmp_room;

	ft_printf("%i\n", env->num_ants);
	tmp_list = env->rooms;
	while (tmp_list)
	{
		tmp_room = (t_room*)tmp_list->content;
		if (!ft_strcmp(tmp_room->name, env->start->name))
			ft_printf("##start\n");
		else if (!ft_strcmp(tmp_room->name, env->end->name))
			ft_printf("##end\n");
		ft_printf("%s %i %i\n", tmp_room->name, tmp_room->x, tmp_room->y);
		tmp_list = tmp_list->next;
	}
	tmp_list = env->links;
	while (tmp_list)
	{
		ft_printf("%s\n", (char*)tmp_list->content);
		tmp_list = tmp_list->next;
	}
	ft_printf("\n");
}

void	print_room(t_room *room)
{
	ft_printf("address: %p\n", room);
	ft_printf("name   : %s\n", room->name);
	ft_printf("rooms  : %p\n", room->rooms);
	ft_printf("n rooms: %i\n", room->num_rooms);
	ft_printf("x      : %i\n", room->x);
	ft_printf("y      : %i\n", room->y);
	ft_printf("d      : %i\n", room->d);
	ft_printf("ant    : %p\n", room->ant);
	ft_printf("\n");
}

void	print_rooms(t_env *env)
{
	t_list	*rooms;

	rooms = env->rooms;
	while (rooms)
	{
		print_room((t_room *)rooms->content);
		rooms = rooms->next;
	}
}

void	print_env(t_env *env)
{
	ft_printf("Rooms: %p\n", env->rooms);
	ft_printf("Start: %p %s\n", env->start, env->start->name);
	ft_printf("End  : %p %s\n", env->end, env->end->name);
	ft_printf("Ants : %p\n", env->ants);
	ft_printf("Links: %p\n", env->links);
	ft_printf("nants: %i\n", env->num_ants);
	ft_printf("snext: %i\n", env->start_next);
	ft_printf("enext: %i\n", env->end_next);
	ft_printf("\n");
}
