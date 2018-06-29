/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvann <mvann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 14:34:39 by mvann             #+#    #+#             */
/*   Updated: 2018/06/29 15:55:40 by mvann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

void	init_min_max(t_room room, int *min, int *max)
{
	*min = room.x > room.y ? room.y : room.x;
	*max = room.x < room.y ? room.x : room.y;
}

void	calculate_scale(t_env *env, t_venv *venv)
{
	int		min;
	int		max;
	t_list	*room_list;
	t_room	curr_room;

	room_list = env->rooms;
	init_min_max(*((t_room*)room_list->content), &min, &max);
	room_list = room_list->next;
	while (room_list)
	{
		curr_room = *((t_room*)room_list->content);
		if (curr_room.x < min || curr_room.y < min)
			min = curr_room.x > curr_room.y ? curr_room.y : curr_room.x;
		if (curr_room.x > max || curr_room.y > max)
			max = curr_room.x < curr_room.y ? curr_room.y : curr_room.x;
		room_list = room_list->next;
	}
	venv->shift = min * -1;
	venv->range = max - min;
}

int		norm_int(t_venv *venv, int n)
{
	int top;

	top = (n + venv->shift) * INNER_SIZE;
	return ((top / venv->range) + BORDER_SIZE);
}
