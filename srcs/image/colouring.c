/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colouring.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendonc <dmendonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 03:40:21 by dmendonc          #+#    #+#             */
/*   Updated: 2022/10/05 19:26:11 by dmendonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractal.h"

void	colour_pixel(int flag, t_hooks *class)
{
	int	colour;

	colour = flag * (16777215 / class->max_it);
	if (flag == -1)
		my_mlx_pixel_put(&class->img, class->nbr.x, class->nbr.y, 32896);
	else if (flag == 0)
		my_mlx_pixel_put(&class->img, class->nbr.x, class->nbr.y,  16777215);
	else
		my_mlx_pixel_put(&class->img, class->nbr.x, class->nbr.y, colour);
}

void	day_pallete(int flag, t_hooks *class)
{
	int	colour;

	colour = 16777215 - 65280.0 * (flag / 50.0);
	if (flag == -2)
		my_mlx_pixel_put(&class->img, class->nbr.x, class->nbr.y, 0);
	else if (flag == -1)
		my_mlx_pixel_put(&class->img, class->nbr.x, class->nbr.y, 16777215);
	else if (flag == 0)
		my_mlx_pixel_put(&class->img, class->nbr.x, class->nbr.y, 16777215);
	else
		my_mlx_pixel_put(&class->img, class->nbr.x, class->nbr.y, colour);
}

void	night_pallete(int flag, t_hooks *class)
{
	int	colour;

	colour = 128 + 300 * flag;
	if (flag > class->max_it / 3)
		colour = 32640 + 300 * flag;
	if (flag == -2)
		my_mlx_pixel_put(&class->img, class->nbr.x, class->nbr.y,  0x00FFFFFF);
	else if (flag == -1)
		my_mlx_pixel_put(&class->img, class->nbr.x, class->nbr.y, 0);
	else if (flag == 0)
		my_mlx_pixel_put(&class->img, class->nbr.x, class->nbr.y, 0);
	else
		my_mlx_pixel_put(&class->img, class->nbr.x, class->nbr.y, colour);
}

void	palletes(int flag, t_hooks *class)
{
	if(class->keys.key_n == 0)
		day_pallete(flag, class);
	else
		night_pallete(flag, class);
}
