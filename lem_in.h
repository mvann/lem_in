/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvann <mvann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 19:22:50 by mvann             #+#    #+#             */
/*   Updated: 2018/06/26 19:18:32 by mvann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft/libft.h"
# include "libft/ft_printf/ft_printf.h"


typedef struct	s_room
{
	char		*name;
	t_list		*rooms;
	int			num_rooms;
	int			x;
	int			y;
	int			d;
	t_ant		t_ant;
}				t_room;

typedef struct	s_env
{
	t_list		*rooms;
	t_room		*start;
	t_room		*end;
	t_list		*ants;
	int			num_ants;
}				t_env;

typedef struct	s_ant
{
	t_room		*room;
	int			i;
}				t_ant;

#endif
