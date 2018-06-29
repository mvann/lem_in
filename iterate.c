/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvann <mvann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 16:00:56 by mvann             #+#    #+#             */
/*   Updated: 2018/06/29 16:37:56 by mvann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

void	draw_ant(t_venv *venv, t_room *room, char *ant)
{
	int x;
	int y;

	x = norm_int(venv, room->x);
	y = norm_int(venv, room->y);
	mlx_string_put(venv->mlx, venv->win, x - ROOM_SIZE / 2,
			y - ROOM_SIZE / 2, ANT_COLOR, ant);
}

void	process_move(t_env *env, t_venv *venv, char *str)
{
	char	**split;
	t_room	*room;

	split = ft_strsplit(str, '-');
	if (split_len(split) != 2)
		error("Bad ants!");
	room = get_room_at_name(env->rooms, split[1]);
	if (!room)
		error("Bad room!");
	draw_ant(venv, room, split[0]);
	free_split(split);
}

void	iterate_ants(t_env *env, t_venv *venv)
{
	char	*str;
	char	**moves;
	int		i;

	str = NULL;
	if (!get_next_line(0, &str))
		exit(1);
	moves = ft_strsplit(str, ' ');
	i = 0;
	while (moves[i])
	{
		process_move(env, venv, moves[i]);
		i++;
	}
	free_split(moves);
	free(str);
}
