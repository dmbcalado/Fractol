/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendonc <dmendonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 03:36:01 by dmendonc          #+#    #+#             */
/*   Updated: 2022/10/03 16:55:16 by dmendonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractal.h"

int	recursive_mandelbrot(double real, double imag, t_hooks *class)
{
	class->initial.real = real;
	class->initial.imag = imag;
	real = pow(real, 2.0) - pow(imag, 2.0) + class->nbr.c_x;
	imag = 2.0 * class->initial.real * imag + class->nbr.c_y;
	if (calculate_radius(real, imag) >= 4.0)
		return (class->it);
	class->it++;
	if (class->it == class->max_it)
		return (-2);
	return (recursive_mandelbrot(real, imag, class));
}

void	fill_mandelbrot(t_hooks *class)
{
	int		flag;

	while (++class->nbr.y < class->win.height)
	{
		while (++class->nbr.x < class->win.lenght)
		{
			set_coordinates_mandelbrot(class->nbr.x, class->nbr.y, class);
			if (calculate_radius(class->nbr.real, class->nbr.imag) <= 4.0)
			{
				class->it = 0;
				flag = recursive_mandelbrot(class->nbr.real, class->nbr.imag, \
				class);
				best_pallete(flag, class);
			}
			else
				best_pallete(-1, class);
		}
		class->nbr.x = -1;
	}
	class->nbr.y = -1;
}
