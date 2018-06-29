/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvann <mvann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 18:31:54 by mvann             #+#    #+#             */
/*   Updated: 2018/06/29 16:43:50 by mvann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	calculate_distances(t_env *env, t_room *room, int d)
{
	t_room	*curr_room;
	int		i;

	if (!ft_strcmp(room->name, env->start->name))
		room->d = room->d > d || room->d < 0 ? d : room->d;
	else if (room->d < 0 || room->d > d)
	{
		room->d = d;
		i = 0;
		while (i < room->num_rooms)
		{
			curr_room = get_room_at_name(env->rooms, get_name_at(room, i));
			calculate_distances(env, curr_room, d + 1);
			i++;
		}
	}
}
