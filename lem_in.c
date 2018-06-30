/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvann <mvann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 19:29:05 by mvann             #+#    #+#             */
/*   Updated: 2018/06/29 18:16:40 by mvann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		all_ants_at_end(t_env *env)
{
	int		i;
	t_ant	*tmp_ant;

	i = 0;
	while (i < env->num_ants)
	{
		tmp_ant = get_ant_at(env, i);
		if (ft_strcmp(tmp_ant->room->name, env->end->name))
			return (0);
		i++;
	}
	return (1);
}

void	check_start_distance(int d)
{
	if (d < 0)
		error("No path to end.");
}

int		main(void)
{
	t_env	env;

	env.rooms = NULL;
	env.start = NULL;
	env.end = NULL;
	env.strs = NULL;
	env.ants = NULL;
	env.num_ants = 0;
	env.start_next = 0;
	env.end_next = 0;
	input(&env);
	calculate_distances(&env, env.end, 0);
	check_start_distance(env.start->d);
	print_farm(env.strs);
	ft_printf("\n");
	add_ants(&env);
	while (!all_ants_at_end(&env))
		move_ants(&env);
	return (1);
}
