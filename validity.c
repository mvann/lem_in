/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validity.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvann <mvann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 19:47:20 by mvann             #+#    #+#             */
/*   Updated: 2018/06/23 19:51:21 by mvann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		valid_int(char *s)
{
	int		i;
	long	int_max;
	long	long_form;

	int_max = 2147483647;
	long_form = ft_atol(s);
	i = 0;
	while (i < (int)ft_strlen(s))
	{
		if (!ft_isdigit(s[i]))
			if (i > 0 || (s[i] != '+' && s[i] != '-'))
				return (0);
		i++;
	}
	if (ft_strlen(s) > 11 ||
	long_form > int_max || long_form < (int_max + 1) * -1)
		return (0);
	return (1);
}

int		valid_room(
