/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvann <mvann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 19:22:31 by mvann             #+#    #+#             */
/*   Updated: 2018/06/23 20:06:29 by mvann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	input(t_env *env, int ac, char **av)
{
	char	*str;
	int		stage;

	stage = 0;
	str = NULL;
	while (get_next_line(0, &str))
	{
		if (stage == 0)
			get_ants(env, str, &stage);
		else if (stage == 1)
			get_room(env, str, &stage);
		else
			get_link(env, str);
		free(str);
	}
}
