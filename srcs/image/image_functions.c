/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendonc <dmendonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 14:44:18 by dmendonc          #+#    #+#             */
/*   Updated: 2022/05/15 20:03:27 by dmendonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractal.h"

void	my_mlx_pixel_put(t_mlx_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	refreshing_image(t_hooks *class)
{
	class->img.img = mlx_new_image(class->img.mlx, class->win.lenght, \
	class->win.height);
	class->img.addr = mlx_get_data_addr(class->img.img, \
	&class->img.bits_per_pixel, &class->img.line_length, &class->img.endian);
}

void	kill_image(t_mlx_data img)
{
	mlx_hook(img.win, 17, 0, close, &img);
}
