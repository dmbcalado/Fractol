/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendonc <dmendonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 22:28:16 by dmendonc          #+#    #+#             */
/*   Updated: 2022/10/05 20:34:34 by dmendonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractal.h"

void	increase_resolution(t_hooks *class)
{
	class->max_it++;
	printf("iterations: %d\n", class->max_it);
	if (class->wich_fractal == 1)
	{
		refreshing_image(class);
		fill_mandelbrot(class);
	}
	else if (class->wich_fractal == 2)
	{
		refreshing_image(class);
		fill_julia(class);
	}
}

void	decrease_resolution(t_hooks *class)
{
	if (class->max_it > 1)
		class->max_it--;
	printf("iterations: %d\n", class->max_it);
	if (class->wich_fractal == 1)
	{
		refreshing_image(class);
		fill_mandelbrot(class);
	}
	else if (class->wich_fractal == 2)
	{
		refreshing_image(class);
		fill_julia(class);
	}
}
