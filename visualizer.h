/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvann <mvann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 13:59:38 by mvann             #+#    #+#             */
/*   Updated: 2018/06/29 16:51:32 by mvann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUALIZER_H
# define VISUALIZER_H

# include "lem_in.h"

# define BORDER_SIZE 50
# define INNER_SIZE 900
# define WIN_X BORDER_SIZE + INNER_SIZE + BORDER_SIZE
# define WIN_Y BORDER_SIZE + INNER_SIZE + BORDER_SIZE
# define ROOM_SIZE 30
# define LINE_COLOR 0xFF0000
# define ROOM_COLOR 0xFF00FF
# define START_COLOR 0x00FF00
# define END_COLOR 0x0000FF
# define ANT_COLOR 0xFFFFFF

# define KEY_ESC 53
# define KEY_N 45

typedef struct	s_venv
{
	void		*mlx;
	void		*win;
	int			shift;
	int			range;
}				t_venv;

typedef struct	s_vect
{
	int			x;
	int			y;
}				t_vect;

typedef struct	s_env_wrapper
{
	t_env		*env;
	t_venv		*venv;
}				t_env_wrapper;

void			draw_farm(t_env *env, t_venv *venv);

void			line_to1(t_venv *venv, t_vect old, t_vect new);
void			line_to2(t_venv *venv, t_vect old, t_vect new);
void			line_to(t_venv *venv, t_vect old, t_vect new);

void			calculate_scale(t_env *env, t_venv *venv);
int				norm_int(t_venv *venv, int n);

int				keydown_event(int keycode, t_env_wrapper *wrapper);

void			iterate_ants(t_env *env, t_venv *venv);

#endif
