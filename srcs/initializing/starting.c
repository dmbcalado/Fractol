/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   starting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendonc <dmendonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 02:20:43 by dmendonc          #+#    #+#             */
/*   Updated: 2022/10/06 18:56:45 by dmendonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractal.h"

t_w_data	starting_window(int lenght, int height)
{
	t_w_data	win;

	win.lenght = lenght;
	win.height = height;
	win.center_x = 4.0 * lenght;
	win.center_y = 4.0 * height;
	return (win);
}

t_mlx_data	starting_image(t_w_data win)
{
	t_mlx_data	img;

	img.mlx = mlx_init();
	img.win = mlx_new_window(img.mlx, win.lenght, win.height, "Mandelbrot");
	img.img = mlx_new_image(img.mlx, win.lenght, win.height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, \
	&img.line_length, &img.endian);
	return (img);
}

t_keys	starting_keys(void)
{
	t_keys	keys;

	keys.key_w = 0;
	keys.key_s = 0;
	keys.key_a = 0;
	keys.key_d = 0;
	keys.key_esc = 0;
	keys.key_scr_u = 0;
	keys.key_scr_d = 0;
	keys.click = 0;
	keys.lol_key = 0;
	keys.np_minus = 0;
	keys.np_plus = 0;
	keys.key_n = 0;
	return (keys);
}

t_complex	starting_numbers(void)
{
	t_complex	world;

	world.x = 0;
	world.y = 0;
	world.offset_x = 0;
	world.offset_y = 0;
	return (world);
}

t_zoom	starting_zoom(void)
{
	t_zoom	new;

	new.h_zoom = 1;
	new.v_zoom = 1;
	return (new);
}
