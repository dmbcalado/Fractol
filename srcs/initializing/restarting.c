/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   restarting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendonc <dmendonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 16:40:35 by dmendonc          #+#    #+#             */
/*   Updated: 2022/10/04 00:41:56 by dmendonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractal.h"

void	starting_class(t_hooks *class)
{
	class->keys = starting_keys();
	class->zoom = starting_zoom();
	class->win = starting_window(1100, 1100);
	class->img = starting_image(class->win);
	class->nbr = starting_numbers();
	class->initial = starting_numbers();
	class->kint = starting_kint();
	class->times_zoomed = 1;
	class->max_it = 25;
	class->it = 0;
}

t_mlx_data	starting_new_image(t_w_data win)
{
	t_mlx_data	img;

	img.mlx = NULL;
	img.img = mlx_new_image(img.mlx, win.lenght, win.height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, \
	&img.line_length, &img.endian);
	return (img);
}

void	choosing_fractal(char *str, t_hooks *class)
{
	if (compare(str, "mandelbrot") == -2)
		class->wich_fractal = 1;
	else if (compare(str, "julia") == -2)
		class->wich_fractal = 2;
	else if (compare(str, "manual") == -2)
		class->wich_fractal = 3;
	else
	{
		printf("not a legal input. turning off.\n");
		exit(0);
	}
}
