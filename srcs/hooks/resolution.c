/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendonc <dmendonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 22:28:16 by dmendonc          #+#    #+#             */
/*   Updated: 2022/10/06 20:39:26 by dmendonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractal.h"

void	increase_resolution(t_hooks *class)
{
	class->max_it++;
	ft_printf("iterations: %d\n", class->max_it);
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
	else if (class->wich_fractal == 4)
	{
		refreshing_image(class);
		fill_hourglass(class);
	}
}

void	decrease_resolution(t_hooks *class)
{
	if (class->max_it > 1)
		class->max_it--;
	ft_printf("iterations: %d\n", class->max_it);
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
	else if (class->wich_fractal == 4)
	{
		refreshing_image(class);
		fill_hourglass(class);
	}
}
