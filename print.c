/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvann <mvann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 22:13:41 by mvann             #+#    #+#             */
/*   Updated: 2018/06/28 18:55:09 by mvann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

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
	ft_printf("nants: %i\n", env->num_ants);
	ft_printf("snext: %i\n", env->start_next);
	ft_printf("enext: %i\n", env->end_next);
	ft_printf("\n");
}
