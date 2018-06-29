/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ant.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvann <mvann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 19:03:20 by mvann             #+#    #+#             */
/*   Updated: 2018/06/29 16:43:34 by mvann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room	*get_best_available_room(t_env *env, t_room *room)
{
	t_list *curr_room_list;
	t_room *curr_room;
	t_room *best_room;

	curr_room_list = room->rooms;
	best_room = NULL;
	while (curr_room_list)
	{
		curr_room = get_room_at_name(env->rooms,
			(char*)curr_room_list->content);
		if (!ft_strcmp(curr_room->name, env->end->name))
			return (curr_room);
		if ((!best_room || best_room->d > curr_room->d) && !curr_room->ant &&
			curr_room->d > 0)
			best_room = curr_room;
		curr_room_list = curr_room_list->next;
	}
	return (best_room);
}

void	move_ant(t_ant *ant, t_room *new_room, int print_space, int i)
{
	t_room *old_room;

	old_room = ant->room;
	old_room->ant = NULL;
	new_room->ant = ant;
	ant->room = new_room;
	if (print_space)
		ft_printf(" ");
	ft_printf("L%i-%s", i, new_room->name);
}

void	move_ants(t_env *env)
{
	int		i;
	t_room	*tmp_room;
	t_ant	*tmp_ant;
	t_room	*best_room;
	int		have_printed_an_ant;

	have_printed_an_ant = 0;
	i = 0;
	while (i < env->num_ants)
	{
		tmp_ant = get_ant_at(env, i);
		tmp_room = tmp_ant->room;
		if (ft_strcmp(tmp_room->name, env->end->name))
		{
			best_room = get_best_available_room(env, tmp_room);
			if (best_room)
			{
				move_ant(tmp_ant, best_room, have_printed_an_ant, i + 1);
				have_printed_an_ant = 1;
			}
		}
		i++;
	}
	ft_printf("\n");
}

t_ant	*get_ant_at(t_env *env, int i)
{
	t_list	*l;

	l = ft_lstat(i, env->ants);
	return ((t_ant*)l->content);
}

void	add_ants(t_env *env)
{
	t_list	**l;
	int		i;
	t_ant	ant;

	ant.room = env->start;
	ant.i = 0;
	l = &(env->ants);
	*l = ft_lstnew(&ant, sizeof(t_ant));
	i = 1;
	while (i < env->num_ants)
	{
		ant.i = i;
		ft_lstadd(l, ft_lstnew(&ant, sizeof(t_ant)));
		i++;
	}
}
