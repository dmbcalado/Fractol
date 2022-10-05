/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendonc <dmendonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 14:44:18 by dmendonc          #+#    #+#             */
/*   Updated: 2022/10/05 20:40:22 by dmendonc         ###   ########.fr       */
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
	mlx_destroy_image(class->img.mlx, class->img.img);
	class->img.img = mlx_new_image(class->img.mlx, class->win.lenght, \
	class->win.height);
	class->img.addr = mlx_get_data_addr(class->img.img, \
	&class->img.bits_per_pixel, &class->img.line_length, &class->img.endian);
}
