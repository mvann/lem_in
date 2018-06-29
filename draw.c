/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvann <mvann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 13:51:57 by mvann             #+#    #+#             */
/*   Updated: 2018/06/29 16:35:11 by mvann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

void	draw_room(t_venv *venv, t_room *room, int color)
{
	int i;
	int j;
	int x;
	int y;

	i = 0;
	while (i < ROOM_SIZE)
	{
		j = 0;
		while (j < ROOM_SIZE)
		{
			x = norm_int(venv, room->x) + j - ROOM_SIZE / 2;
			y = norm_int(venv, room->y) + i - ROOM_SIZE / 2;
			mlx_pixel_put(venv->mlx, venv->win, x, y, color);
			j++;
		}
		i++;
	}
}

void	draw_rooms(t_env *env, t_venv *venv)
{
	t_list	*room_list;

	room_list = env->rooms;
	while (room_list)
	{
		draw_room(venv, (t_room*)room_list->content, ROOM_COLOR);
		room_list = room_list->next;
	}
}

void	draw_spokes(t_env *env, t_venv *venv, t_room *room)
{
	t_list	*name_list;
	char	*curr_name;
	t_room	*curr_room;
	t_vect	first;
	t_vect	second;

	first.x = norm_int(venv, room->x);
	first.y = norm_int(venv, room->y);
	name_list = room->rooms;
	while (name_list)
	{
		curr_name = (char*)name_list->content;
		curr_room = get_room_at_name(env->rooms, curr_name);
		second.x = norm_int(venv, curr_room->x);
		second.y = norm_int(venv, curr_room->y);
		line_to(venv, first, second);
		name_list = name_list->next;
	}
}

void	draw_lines(t_env *env, t_venv *venv)
{
	t_list	*room_list;
	t_room	*curr_room;

	room_list = env->rooms;
	while (room_list)
	{
		curr_room = (t_room*)room_list->content;
		draw_spokes(env, venv, curr_room);
		room_list = room_list->next;
	}
}

void	draw_farm(t_env *env, t_venv *venv)
{
	mlx_clear_window(venv->mlx, venv->win);
	draw_lines(env, venv);
	draw_rooms(env, venv);
	draw_room(venv, env->start, START_COLOR);
	draw_room(venv, env->end, END_COLOR);
}
