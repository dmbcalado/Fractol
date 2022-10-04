/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colouring.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendonc <dmendonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 03:40:21 by dmendonc          #+#    #+#             */
/*   Updated: 2022/10/03 17:07:33 by dmendonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractal.h"

void	colour_pixel(double flag, t_hooks *class)
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

void	best_pallete(double flag, t_hooks *class)
{
	int	colour;

	colour = 16777215 - 65280.0 * (flag / 50.0);
	if (flag == -2)
		my_mlx_pixel_put(&class->img, class->nbr.x, class->nbr.y, 0);
	if (flag == -1)
		my_mlx_pixel_put(&class->img, class->nbr.x, class->nbr.y, 16777215);
	else if (flag == 0)
		my_mlx_pixel_put(&class->img, class->nbr.x, class->nbr.y, 16777215);
	else
		my_mlx_pixel_put(&class->img, class->nbr.x, class->nbr.y, colour);
}