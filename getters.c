/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvann <mvann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 19:48:14 by mvann             #+#    #+#             */
/*   Updated: 2018/06/23 21:11:58 by mvann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	get_ants(t_env *env, char *str, int *stage)
{
	if (!is_comment(str))
	if (!valid_int(str))
		error();
}

void	get_room(t_env *env, char *str, int *stage)
{

}

void	get_link(t_env *env, char *str, int *stage)
{

}
