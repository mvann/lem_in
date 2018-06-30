/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvann <mvann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 19:22:31 by mvann             #+#    #+#             */
/*   Updated: 2018/06/29 18:09:25 by mvann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	add_str(t_env *env, char *str)
{
	if (!env->strs)
		env->strs = ft_lstnew(str, ft_strlen(str) + 1);
	else
		ft_lstadd(&(env->strs), ft_lstnew(str, ft_strlen(str) + 1));
}

int		input_ants(t_env *env, char *str, int *stage)
{
	if (is_comment(str))
		return (1);
	if (ft_strlen(str) == 0 || !valid_int(str))
		error("Invalid ants input.");
	env->num_ants = ft_atoi(str);
	if (env->num_ants < 1)
		error("Too few ants.");
	else if (env->num_ants > MAX_ANTS)
		error("Number of ants is greater than MAX_ANTS.");
	(*stage)++;
	return (1);
}

int		input_room(t_env *env, char *str, int *stage)
{
	char **split;

	if (is_comment(str))
	{
		if (!ft_strcmp(str, "##start"))
			env->start_next = 1;
		else if (!ft_strcmp(str, "##end"))
			env->end_next = 1;
		return (1);
	}
	split = ft_strsplit(str, ' ');
	if (split_len(split) != 3)
	{
		if (split_len(split) == 0)
			error("No blank lines.");
		if (!(env->start) || !(env->end))
			error("No start or end defined.");
		free_split(split);
		(*stage)++;
	}
	else
		process_split(env, split);
	return (1);
}

int		input_link(t_env *env, char *str)
{
	t_room	*tmp_room;
	char	**split;

	if (is_comment(str))
		return (1);
	split = ft_strsplit(str, '-');
	if (split_len(split) != 2)
		error("Incorrect link input.");
	if (!ft_strcmp(split[0], split[1]))
		error("A room must link to a different room");
	tmp_room = get_room_at_name(env->rooms, split[0]);
	if (!tmp_room)
		error("A room in a link does not exist.");
	add_name(tmp_room, split[1]);
	tmp_room = get_room_at_name(env->rooms, split[1]);
	if (!tmp_room)
		error("A room in a link does not exist.");
	add_name(tmp_room, split[0]);
	free_split(split);
	return (1);
}

void	input(t_env *env)
{
	char	*str;
	int		stage;
	int		no_input;

	stage = 0;
	str = NULL;
	no_input = 1;
	while (get_next_line(0, &str))
	{
		if (!str)
			error("Bad input.");
		no_input = 0;
		if (stage == 0)
			input_ants(env, str, &stage);
		else if (stage == 1)
			input_room(env, str, &stage);
		if (stage == 2)
			input_link(env, str);
		add_str(env, str);
		free(str);
	}
	if (no_input)
		error("No input given.");
}
