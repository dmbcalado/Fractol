/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendonc <dmendonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 18:39:27 by dmendonc          #+#    #+#             */
/*   Updated: 2022/05/15 22:20:15 by dmendonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractal.h"

void	zoom_mandelbrot(t_hooks *c)
{
	c->zoom.h_zoom += 100.0;
	c->zoom.v_zoom += 100.0;
	mlx_destroy_image(c->img.mlx, c->img.img);
	refreshing_image(c);
	fill_mandelbrot(c);
}

void	unzoom_mandelbrot(t_hooks *c)
{
	c->zoom.h_zoom -= 100.0;
	c->zoom.v_zoom += 100.0;
	mlx_destroy_image(c->img.mlx, c->img.img);
	refreshing_image(c);
	fill_mandelbrot(c);
}

void	zoom_julia(t_hooks *c)
{
	c->zoom.h_zoom += 100.0;
	c->zoom.v_zoom += 100.0;
	mlx_destroy_image(c->img.mlx, c->img.img);
	refreshing_image(c);
	fill_julia(c);
}

void	unzoom_julia(t_hooks *c)
{
	c->zoom.h_zoom -= 100.0;
	c->zoom.v_zoom -= 100.0;
	mlx_destroy_image(c->img.mlx, c->img.img);
	refreshing_image(c);
	fill_julia(c);
}
