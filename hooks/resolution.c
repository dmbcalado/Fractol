/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendonc <dmendonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 22:28:16 by dmendonc          #+#    #+#             */
/*   Updated: 2022/05/15 22:38:05 by dmendonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractal.h"

void	increase_resolution(t_hooks *class)
{
	class->max_it++;
	printf("iterations: %d\n", class->max_it);
	mlx_destroy_image(class->img.mlx, class->img.img);
	refreshing_image(class);
	if (class->wich_fractal == 1)
		fill_mandelbrot(class);
	else if (class->wich_fractal == 2)
		fill_julia(class);
}

void	decrease_resolution(t_hooks *class)
{
	class->max_it--;
	printf("iterations: %d\n", class->max_it);
	mlx_destroy_image(class->img.mlx, class->img.img);
	refreshing_image(class);
	if (class->wich_fractal == 1)
		fill_mandelbrot(class);
	else if (class->wich_fractal == 2)
		fill_julia(class);
}
