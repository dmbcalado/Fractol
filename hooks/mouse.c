/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendonc <dmendonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 19:07:29 by dmendonc          #+#    #+#             */
/*   Updated: 2022/05/15 22:37:22 by dmendonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractal.h"

int	mouse_press(int key, int x, int y, t_hooks *class)
{
	(void) x;
	(void) y;
	if (class->wich_fractal == 1)
		mouse_press_mandelbrot(key, class);
	if (class->wich_fractal == 2)
		mouse_press_julia(key, class);
	return (0);
}

int	mouse_press_mandelbrot(int key, t_hooks *class)
{
	if (key == M_SCR_D)
	{
		zoom_mandelbrot(class);
		printf("zoom in\n");
	}
	else if (key == M_SCR_U)
	{
		unzoom_mandelbrot(class);
		printf("zoom out\n");
	}
	return (0);
}

int	mouse_press_julia(int key, t_hooks *class)
{
	if (key == M_SCR_D)
	{
		zoom_julia(class);
		printf("zoom in\n");
	}
	else if (key == M_SCR_U)
	{
		unzoom_julia(class);
		printf("zoom out\n");
	}
	return (0);
}

int	mouse_release(int key, t_hooks *class)
{
	if (key == M_SCR_U)
		class->keys.key_scr_u = 0;
	else if (key == M_SCR_D)
		class->keys.key_scr_d = 0;
	return (0);
}

/* int	mouse_move(t_hooks *class)
{
	if (class->key_w)
		key_up(class);
	if (class->key_s)
		key_down(class);
	if (class->key_d)
		key_right(class);
	if (class->key_a)
		key_left(class);
	if (class->key_esc)
		exit(0);
	return (0);
} */