/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendonc <dmendonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 16:34:02 by dmendonc          #+#    #+#             */
/*   Updated: 2022/05/16 04:58:16 by dmendonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractal.h"

int	compare(const char *s1, const char *s2)
{
	int	i;

	i = -1;
	while (s1[++i])
	{
		if (s1[i] != s2[i] && s1[i] != s2[i] - 32)
			return (i);
	}
	i = -1;
	while (s2[++i])
	{
		if (s1[i] != s2[i] && s2[i] != s1[i] - 32)
			return (i);
	}
	return (-2);
}

double	char_to_double(const char *str)
{
	int		i;
	double	comma;
	int		menos;
	double	number;

	i = 0;
	menos = 1;
	number = 0;
	comma = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-')
		menos = -1;
	while (str[++i] >= 48 && str[i] <= 57)
		number = number * 10 + (double)menos * (str[i] - 48);
	if (str[i] == '.')
	{
		while (str[++i] >= 48 && str[i] <= 57)
		{
			number = number + (double)menos * pow(0.1, comma) * \
			(double)(str[i] - 48);
			comma++;
		}
	}
	return (number);
}

void	getting_c_for_julia(char *c_x, char *c_y, t_hooks *class)
{
	class->nbr.j_c_x = char_to_double(c_x);
	class->nbr.j_c_x = char_to_double(c_y);
}
