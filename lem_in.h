/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvann <mvann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 19:22:50 by mvann             #+#    #+#             */
/*   Updated: 2018/06/28 19:05:21 by mvann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft/libft.h"
# include "libft/ft_printf/ft_printf.h"

# define DEBUG 1

typedef struct	s_room	t_room;
typedef struct	s_env	t_env;
typedef struct	s_ant	t_ant;

struct	s_room
{
	char		*name;
	t_list		*rooms;
	int			num_rooms;
	int			x;
	int			y;
	int			d;
	t_ant		*ant;
};

struct	s_env
{
	t_list		*rooms;
	t_room		*start;
	t_room		*end;
	t_list		*ants;
	int			num_ants;
	int			start_next;
	int			end_next;
};

struct	s_ant
{
	t_room		*room;
	int			i;
};


// input.c
int				input_ants(t_env *env, char *str, int *stage);
int				input_room(t_env *env, char *str, int *stage);
int				input_link(t_env *env, char *str);
void			input(t_env *env);

// split.c
void			process_split(t_env *env, char **split);
void			free_split(char **split);
int				split_len(char **split);

// int.c
int				valid_int(char *s);
long			ft_atol(const char *str);

// error.c
void			error(char *s);

// boolean.c
int				is_comment(char *s);

// room.c
t_room			*get_room_at_name(t_list *list, char *name);
void			add_room(t_env *env, char *name, int x, int y);

// print.c
void			print_env(t_env *env);
void			print_rooms(t_env *env);
void			print_room(t_room *room);

// name.c
char			*get_name_at(t_room *room, int i);
void			add_name(t_room *room, char *name);

// distance.c
void			calculate_distances(t_env *env, t_room *room, int d);

// ant.c
void			move_ants(t_env *env);
t_ant			*get_ant_at(t_env *env, int i);
void			add_ants(t_env *env);




#endif
