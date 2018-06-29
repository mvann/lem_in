/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvann <mvann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 15:56:48 by mvann             #+#    #+#             */
/*   Updated: 2018/06/29 16:33:10 by mvann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

int		keydown_event(int keycode, t_env_wrapper *wrapper)
{
	if (keycode == KEY_ESC)
		exit(EXIT_SUCCESS);
	else if (keycode == KEY_N)
	{
		draw_farm(wrapper->env, wrapper->venv);
		iterate_ants(wrapper->env, wrapper->venv);
	}
	return (0);
}
