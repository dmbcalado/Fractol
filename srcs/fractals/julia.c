/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendonc <dmendonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 03:36:01 by dmendonc          #+#    #+#             */
/*   Updated: 2022/10/06 20:42:25 by dmendonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractal.h"

int	recursive_julia(double real, double imag, t_hooks *class)
{
	class->initial.real = real;
	class->initial.imag = imag;
	real = pow(real, 2.0) - pow(imag, 2.0) + class->nbr.j_c_x;
	imag = 2.0 * class->initial.real * imag + class->nbr.j_c_y;
	if (calculate_radius(real, imag) >= 4.0)
		return (class->it);
	class->it++;
	if (class->it == class->max_it)
		return (-2);
	return (recursive_julia(real, imag, class));
}

void	fill_julia(t_hooks *class)
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
				flag = recursive_julia(class->nbr.real, class->nbr.imag, class);
				palletes(flag, class);
			}
			else
				palletes(-1, class);
		}
		class->nbr.x = -1;
	}
	class->nbr.y = -1;
}
