/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvann <mvann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 20:25:59 by mvann             #+#    #+#             */
/*   Updated: 2018/06/29 16:48:46 by mvann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	process_split(t_env *env, char **split)
{
	char *name;
	char *x_s;
	char *y_s;

	name = split[0];
	x_s = split[1];
	y_s = split[2];
	if (!valid_int(x_s) || !valid_int(y_s) || name[0] == 'L' || name[0] == '#'
		|| ft_strchr(name, '-') || get_room_at_name(env->rooms, name))
		error("Invalid room name or room already exists.");
	add_room(env, name, ft_atoi(x_s), ft_atoi(y_s));
	if ((env->start_next && env->start) || (env->end_next && env->end) ||
		(env->start_next && env->end_next))
		error("Start and end must be specified separately and only once.");
	if (env->start_next)
	{
		env->start = get_room_at_name(env->rooms, name);
		env->start_next = 0;
	}
	else if (env->end_next)
	{
		env->end = get_room_at_name(env->rooms, name);
		env->end_next = 0;
	}
	free_split(split);
}

void	free_split(char **split)
{
	int i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

int		split_len(char **split)
{
	int i;

	i = 0;
	while (split[i])
		i++;
	return (i);
}
