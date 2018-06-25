/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvann <mvann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 15:56:32 by mvann             #+#    #+#             */
/*   Updated: 2018/06/23 17:57:14 by mvann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"
# include "libft/ft_printf/ft_printf.h"

# define SA 1
# define SB 2
# define SS 3
# define PA 4
# define PB 5
# define RA 6
# define RB 7
# define RR 8
# define RRA 9
# define RRB 10
# define RRR 11

# define COMMANDS_LEN 100000

typedef struct	s_env
{
	t_list		*p_a;
	t_list		*p_b;
	int			len_a;
	int			len_b;
	int			*command_queue;
	int			command_i;
}				t_env;

int				swap(t_list **p_head_adr);
int				swap_two(t_list **a, t_list **b);

int				rotate_two(t_list **a, t_list **b);
int				rotate(t_list **head);
int				derotate_two(t_list **a, t_list **b);
int				derotate(t_list **head);

int				rotate_a(t_env *env);
void			rotate_b(t_env *env);
int				rotate_both(t_env *env);
int				derotate_a(t_env *env);

int				push(t_list **l1, t_list **l2);
t_list			*pop(t_list **l);

void			push_a(t_env *env);
void			push_b(t_env *env);

int				is_valid(char *s);
void			error();
int				section_sorted(t_list *l, int n);
int				sorted(t_list *l);
long			ft_atol(const char *str);

t_list			*parse_list(int ac, char **av);

void			print_int_list(t_list *l);
int				int_in_lst_at(t_list *lst, int i);
int				get_median(t_list *lst, int n);
int				get_mid(int n1, int n2, int n3);
void			add_command(t_env *env, int command);

void			small_algorithm(t_env *env, int n);

#endif
