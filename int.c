/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvann <mvann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 19:37:23 by mvann             #+#    #+#             */
/*   Updated: 2018/06/27 19:40:50 by mvann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		valid_int(char *s)
{
	int		i;
	long	int_max;
	long	long_form;

	if (ft_strlen(s) == 1 && !ft_isdigit(s[0]))
		return (0);
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

long	ft_atol(const char *str)
{
	unsigned long	sum;
	int				i;
	int				negative;
	unsigned long	long_max;

	long_max = 9223372036854775807;
	i = 0;
	sum = 0;
	negative = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
			|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '+' || str[i] == '-')
		negative = str[i++] == '-';
	while (str[i] >= '0' && str[i] <= '9')
	{
		sum *= 10;
		sum += str[i] - '0';
		if (!negative && sum > long_max)
			return (-1);
		else if (negative && sum > long_max + 1)
			return (0);
		i++;
	}
	return ((long)sum * (negative ? -1 : 1));
}
