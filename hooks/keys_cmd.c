/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendonc <dmendonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 19:40:27 by dmendonc          #+#    #+#             */
/*   Updated: 2022/05/15 22:11:05 by dmendonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractal.h"

void	key_up(t_hooks *class)
{
	class->nbr.offset_y += 5 * class->times_zoomed;
	printf("\nnow the offset is : (%f, %f)\n", class->nbr.offset_x, \
	class->nbr.offset_y);
	mlx_destroy_image(class->img.mlx, class->img.img);
	refreshing_image(class);
	if (class->wich_fractal == 1)
		fill_mandelbrot(class);
	else if (class->wich_fractal == 2)
		fill_julia(class);
}

void	key_down(t_hooks *class)
{
	class->nbr.offset_y -= 5 * class->times_zoomed;
	printf("\nnow the offset is : (%f, %f)\n", class->nbr.offset_x, \
	class->nbr.offset_y);
	mlx_destroy_image(class->img.mlx, class->img.img);
	refreshing_image(class);
	if (class->wich_fractal == 1)
		fill_mandelbrot(class);
	else if (class->wich_fractal == 2)
		fill_julia(class);
}

void	key_left(t_hooks *class)
{
	class->nbr.offset_x -= 5 * class->times_zoomed;
	printf("\nnow the offset is : (%f, %f)\n", class->nbr.offset_x, \
	class->nbr.offset_y);
	mlx_destroy_image(class->img.mlx, class->img.img);
	refreshing_image(class);
	if (class->wich_fractal == 1)
		fill_mandelbrot(class);
	else if (class->wich_fractal == 2)
		fill_julia(class);
}

void	key_right(t_hooks *class)
{
	class->nbr.offset_x += 5 * class->times_zoomed;
	printf("\nnow the offset is : (%f, %f)\n", class->nbr.offset_x, \
	class->nbr.offset_y);
	mlx_destroy_image(class->img.mlx, class->img.img);
	refreshing_image(class);
	if (class->wich_fractal == 1)
		fill_mandelbrot(class);
	else if (class->wich_fractal == 2)
		fill_julia(class);
}
