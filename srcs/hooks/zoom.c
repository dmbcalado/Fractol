/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendonc <dmendonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 18:39:27 by dmendonc          #+#    #+#             */
/*   Updated: 2022/10/03 21:27:56 by dmendonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractal.h"

void	zoom_mandelbrot(t_hooks *c)
{
	printf("zoom in\n");
	c->zoom.h_zoom += 100.0;
	c->zoom.v_zoom += 100.0;
	c->times_zoomed++;
	fill_mandelbrot(c);
}

void	unzoom_mandelbrot(t_hooks *c)
{
	printf("zoom out\n");
	if (c->zoom.h_zoom >= 100.0)
		c->zoom.h_zoom -= 100.0;
	if (c->zoom.v_zoom >= 100.0)
		c->zoom.v_zoom -= 100.0;
	c->times_zoomed--;
	fill_mandelbrot(c);
}

void	zoom_julia(t_hooks *c)
{
	printf("zoom in\n");
	c->zoom.h_zoom += 100.0;
	c->zoom.v_zoom += 100.0;
	c->times_zoomed++;
	fill_julia(c);
}

void	unzoom_julia(t_hooks *c)
{
	printf("zoom out\n");
	c->zoom.h_zoom -= 100.0;
	c->zoom.v_zoom -= 100.0;
	c->times_zoomed--;
	fill_julia(c);
}
