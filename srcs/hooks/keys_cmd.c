/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendonc <dmendonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 19:40:27 by dmendonc          #+#    #+#             */
/*   Updated: 2022/10/05 20:14:31 by dmendonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractal.h"

void	key_up(t_hooks *class)
{
	class->nbr.offset_y += 5 * class->times_zoomed;
	refreshing_image(class);
	if (class->wich_fractal == 1)
		fill_mandelbrot(class);
	else if (class->wich_fractal == 2)
		fill_julia(class);
}

void	key_down(t_hooks *class)
{
	class->nbr.offset_y -= 5 * class->times_zoomed;
	refreshing_image(class);
	if (class->wich_fractal == 1)
		fill_mandelbrot(class);
	else if (class->wich_fractal == 2)
		fill_julia(class);
}

void	key_left(t_hooks *class)
{
	class->nbr.offset_x -= 5 * class->times_zoomed;
	refreshing_image(class);
	if (class->wich_fractal == 1)
		fill_mandelbrot(class);
	else if (class->wich_fractal == 2)
		fill_julia(class);
}

void	key_right(t_hooks *class)
{
	class->nbr.offset_x += 5 * class->times_zoomed;
	refreshing_image(class);
	if (class->wich_fractal == 1)
		fill_mandelbrot(class);
	else if (class->wich_fractal == 2)
		fill_julia(class);
}
