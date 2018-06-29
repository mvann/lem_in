/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvann <mvann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 14:13:50 by mvann             #+#    #+#             */
/*   Updated: 2018/06/29 15:12:51 by mvann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

void	line_to1(t_venv *venv, t_vect old, t_vect new)
{
	int dx;
	int dy;
	int delta;
	int x;
	int y;

	dx = (int)new.x - (int)old.x;
	dy = (int)new.y - (int)old.y;
	delta = abs(dx) > abs(dy) ? 2 * abs(dy) - abs(dx) : 2 * abs(dx) - abs(dy);
	y = (int)old.y;
	x = (int)old.x;
	while (x != (int)new.x)
	{
		mlx_pixel_put(venv->mlx, venv->win, x, y, LINE_COLOR);
		if (delta > 0)
		{
			y += dy > 0 ? 1 : -1;
			delta += (-1) * 2 * (abs(dx) > abs(dy) ? abs(dx) : abs(dy));
		}
		delta += 2 * (abs(dx) > abs(dy) ? abs(dy) : abs(dx));
		x += dx > 0 ? 1 : -1;
	}
}

void	line_to2(t_venv *venv, t_vect old, t_vect new)
{
	int dx;
	int dy;
	int delta;
	int x;
	int y;

	dx = (int)new.x - (int)old.x;
	dy = (int)new.y - (int)old.y;
	delta = abs(dx) > abs(dy) ? 2 * abs(dy) - abs(dx) : 2 * abs(dx) - abs(dy);
	y = (int)old.y;
	x = (int)old.x;
	while (y != (int)new.y)
	{
		mlx_pixel_put(venv->mlx, venv->win, x, y, LINE_COLOR);
		if (delta > 0)
		{
			x += dx > 0 ? 1 : -1;
			delta += (-1) * 2 * abs(dy);
		}
		delta += 2 * (abs(dx) > abs(dy) ? abs(dy) : abs(dx));
		y += dy > 0 ? 1 : -1;
	}
}

void	line_to(t_venv *venv, t_vect old, t_vect new)
{
	int dx;
	int dy;

	dx = (int)new.x - (int)old.x;
	dy = (int)new.y - (int)old.y;
	if (abs(dx) > abs(dy))
		line_to1(venv, old, new);
	else
		line_to2(venv, old, new);
}
