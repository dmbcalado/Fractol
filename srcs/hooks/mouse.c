/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendonc <dmendonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 19:07:29 by dmendonc          #+#    #+#             */
/*   Updated: 2022/10/06 19:02:07 by dmendonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractal.h"

int	mouse_press(int key, int x, int y, t_hooks *class)
{
	(void)x;
	(void)y;
	if (class->wich_fractal == 1)
		mouse_press_mandelbrot(key, class);
	if (class->wich_fractal == 2)
		mouse_press_julia(key, class);
	return (0);
}

int	mouse_press_mandelbrot(int key, t_hooks *class)
{
	int	x;
	int	y;

	if (key == class->kint.m_scr_d)
		zoom_mandelbrot(class);
	else if (key == class->kint.m_scr_u)
		unzoom_mandelbrot(class);
	else if (key == class->kint.m_click)
	{
		mlx_mouse_get_pos(class->img.mlx, class->img.win, &x, &y);
		calc_mouse_posit(class, x, y);
	}
	return (0);
}

int	mouse_press_julia(int key, t_hooks *class)
{
	int	x;
	int	y;

	if (key == class->kint.m_scr_d)
		zoom_julia(class);
	else if (key == class->kint.m_scr_u)
		unzoom_julia(class);
	else if (key == class->kint.m_click)
	{
		mlx_mouse_get_pos(class->img.mlx, class->img.win, &x, &y);
		new_mouse_posit(class, x, y);
		refreshing_image(class);
		fill_julia(class);
	}
	return (0);
}

int	mouse_release(int key, t_hooks *class)
{
	if (key == class->kint.m_scr_u)
		class->keys.key_scr_u = 0;
	else if (key == class->kint.m_scr_d)
		class->keys.key_scr_d = 0;
	return (0);
}
