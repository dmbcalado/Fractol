/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hourglass.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendonc <dmendonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 19:56:39 by dmendonc          #+#    #+#             */
/*   Updated: 2022/10/06 20:23:20 by dmendonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractal.h"

int	hourglass(double real, double imag, t_hooks *class)
{
	class->initial.real = real;
	class->initial.imag = imag;
	real = pow(real, 2) - pow(imag, 2) - 1;
	imag = 3.0 * class->initial.real * imag;
	if (calculate_radius(real, imag) >= 4.0)
		return (class->it);
	class->it++;
	if (class->it == class->max_it)
		return (-2);
	return (hourglass(real, imag, class));
}

void	fill_hourglass(t_hooks *class)
{
	int		flag;

	while (++class->nbr.y < class->win.height)
	{
		while (++class->nbr.x < class->win.lenght)
		{
			set_coordinates_julia(class->nbr.x, class->nbr.y, class);
			if (calculate_radius(class->nbr.real, class->nbr.imag) <= 4.0)
			{
				class->it = 0;
				flag = hourglass(class->nbr.real, class->nbr.imag, class);
				palletes(flag, class);
			}
			else
				palletes(-1, class);
		}
		class->nbr.x = -1;
	}
	class->nbr.y = -1;
}
