/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvann <mvann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 19:22:31 by mvann             #+#    #+#             */
/*   Updated: 2018/06/26 17:13:44 by mvann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"


void	input_ants(t_env *env, char *str, int *stage)
{
	if (!is_comment(str))
	if (!valid_int(str))
		error();
}

void	input_room(t_env *env, char *str, int *stage)
{

}

void	input_link(t_env *env, char *str, int *stage)
{

}

void	input(t_env *env, int ac, char **av)
{
	char	*str;
	int		stage;

	stage = 0;
	str = NULL;
	while (get_next_line(0, &str))
	{
		if (stage == 0)
			input_ants(env, str, &stage);
		else if (stage == 1)
			input_room(env, str, &stage);
		else
			input_link(env, str);
		free(str);
	}
}
