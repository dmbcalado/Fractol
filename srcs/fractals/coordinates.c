/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinates.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendonc <dmendonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 15:46:54 by dmendonc          #+#    #+#             */
/*   Updated: 2022/10/03 21:35:18 by dmendonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractal.h"

void	set_coordinates_mandelbrot(int x, int y, t_hooks *class)
{
	class->nbr.real = ((double)x - (double)class->win.lenght / 2.0 - 175.0 + \
	class->nbr.offset_x) / (350.0 + (double)class->zoom.h_zoom) + \
	class->nbr.real_mouse;
	class->nbr.imag = ((double)class->win.height / 2.0 - (double)y + \
	class->nbr.offset_y) / (350.0 + (double)class->zoom.v_zoom) + \
	class->nbr.img_mouse;
	class->nbr.c_x = class->nbr.real;
	class->nbr.c_y = class->nbr.imag;
	class->initial.real = ((double)x - (double)class->win.lenght / 2.0) / \
	(200.0 + (double)class->zoom.h_zoom);
	class->initial.imag = ((double)class->win.height / 2.0 - (double)y) / \
	(200.0 + (double)class->zoom.v_zoom);
}

void	set_coordinates_julia(int x, int y, t_hooks *class)
{
	class->nbr.real = ((double)x - (double)class->win.lenght / 2.0 + \
	class->nbr.offset_x) / (300.0 + (double)class->zoom.h_zoom);
	class->nbr.imag = ((double)class->win.height / 2.0 - (double)y + \
	class->nbr.offset_y) / (300.0 + (double)class->zoom.v_zoom);
	class->nbr.c_x = class->nbr.real;
	class->nbr.c_y = class->nbr.imag;
	class->initial.real = ((double)x - (double)class->win.lenght / 2.0) / \
	(200.0 + (double)class->zoom.h_zoom);
	class->initial.imag = ((double)class->win.height / 2.0 - (double)y) / \
	(200.0 + (double)class->zoom.v_zoom);
}

double	calculate_radius(double real, double imag)
{
	return (pow(real, 2.0) + pow(imag, 2.0));
}

void	calc_mouse_posit(t_hooks *class, int x, int y)
{
	class->nbr.real_mouse = ((double)x - (double)class->win.lenght / 2.0 - 175.0 + \
	class->nbr.offset_x) / (350.0 + (double)class->zoom.h_zoom);
	class->nbr.img_mouse = ((double)class->win.height / 2.0 - (double)y + \
	class->nbr.offset_y) / (350.0 + (double)class->zoom.v_zoom);
	printf("x: %f	y: %f\n", class->nbr.real_mouse, class->nbr.img_mouse);
}

void	new_mouse_posit(t_hooks *class, int x, int y)
{
	class->nbr.j_c_x = ((double)x - (double)class->win.lenght / 2.0 + \
	class->nbr.offset_x) / (300.0 + (double)class->zoom.h_zoom);
	class->nbr.j_c_y = ((double)class->win.height / 2.0 - (double)y + \
	class->nbr.offset_y) / (300.0 + (double)class->zoom.v_zoom);
}