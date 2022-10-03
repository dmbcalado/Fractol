/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colouring.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendonc <dmendonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 03:40:21 by dmendonc          #+#    #+#             */
/*   Updated: 2022/05/16 05:17:38 by dmendonc         ###   ########.fr       */
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
		my_mlx_pixel_put(&class->img, class->nbr.x, class->nbr.y, 0);
	else
		my_mlx_pixel_put(&class->img, class->nbr.x, class->nbr.y, colour);
}

void	best_pallete(double flag, t_hooks *class)
{
	int	colour;

	if (flag <= class->max_it / 3)
		colour = flag * (255 * 3 / class->max_it);
	else if (flag <= class->max_it * 2 / 3)
		colour = flag * (16711680 / class->max_it);
	else
		colour = flag * (16753920 / class->max_it);
	if (flag == -1)
		my_mlx_pixel_put(&class->img, class->nbr.x, class->nbr.y, 0);
	else if (flag == 0)
		my_mlx_pixel_put(&class->img, class->nbr.x, class->nbr.y, 0);
	else
		my_mlx_pixel_put(&class->img, class->nbr.x, class->nbr.y, colour);
}
