/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvann <mvann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 13:06:13 by mvann             #+#    #+#             */
/*   Updated: 2018/06/29 16:26:04 by mvann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

void	init_venv(t_venv *venv)
{
		if (!(venv->mlx = mlx_init()))
			error("Visualizer initialization failed.");
		venv->win = mlx_new_window(venv->mlx, WIN_X, WIN_Y, "lem-in");
		if (!(venv->win))
			error("Visualizer initialization failed.");
		venv->shift = 0;
		venv->range = 0;
}

void	vis_input(t_env *env)
{
	char	*str;
	int		stage;
	int		no_input;

	stage = 0;
	str = NULL;
	no_input = 1;
	while (get_next_line(0, &str) && !(stage == 2 && ft_strlen(str) == 0))
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
		free(str);
	}
	if (no_input)
		error("No input given.");
}

int		main(void)
{
	t_env			env;
	t_venv			venv;
	t_env_wrapper	wrapper;

	env.rooms = NULL;
	env.start = NULL;
	env.end = NULL;
	env.ants = NULL;
	env.links = NULL;
	env.num_ants = 0;
	env.start_next = 0;
	env.end_next = 0;
	vis_input(&env);
	init_venv(&venv);
	wrapper.env = &env;
	wrapper.venv = &venv;
	calculate_scale(&env, &venv);
	draw_farm(&env, &venv);
	mlx_hook(venv.win, 2, 0, keydown_event, &wrapper);
	mlx_loop(venv.mlx);
}
