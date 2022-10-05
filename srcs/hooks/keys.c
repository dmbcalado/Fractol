/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendonc <dmendonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 18:52:14 by dmendonc          #+#    #+#             */
/*   Updated: 2022/10/05 20:37:22 by dmendonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractal.h"

int	key_press(int key, t_hooks *class)
{
	if (key == class->kint.K_ESC)
		cross(class);
	else if (key == class->kint.K_W || key == class->kint.K_AR_U)
		class->keys.key_w = 1;
	else if (key == class->kint.K_A || key == class->kint.K_AR_L)
		class->keys.key_a = 1;
	else if (key == class->kint.K_S || key == class->kint.K_AR_D)
		class->keys.key_s = 1;
	else if (key == class->kint.K_D || key == class->kint.K_AR_R)
		class->keys.key_d = 1;
	else if (key == class->kint.K_NP_PLU || key == class->kint.K_AR_R)
		class->keys.np_plus = 1;
	else if (key == class->kint.K_NP_MIN || key == class->kint.K_AR_R)
		class->keys.np_minus = 1;
	else if (key == class->kint.K_N)
	{
		if (class->keys.key_n == 0)
		{
			class->keys.key_n++;
			refreshing_image(class);
			if (class->wich_fractal == 1)
				fill_mandelbrot(class);
			else if (class->wich_fractal == 2)
				fill_julia(class);
		}
		else
		{
			class->keys.key_n = 0;
			refreshing_image(class);
			if (class->wich_fractal == 1)
				fill_mandelbrot(class);
			else if (class->wich_fractal == 2)
				fill_julia(class);
		}
	}
	
	return (0);
}

int	cross(t_hooks *class)
{
	mlx_destroy_image(class->img.mlx, class->img.img);
	mlx_destroy_window(class->img.mlx, class->img.win);
	free(class->img.mlx);
	exit (0);
}

int	key_release(int key, t_hooks *class)
{
	if (key == class->kint.K_W || key == class->kint.K_AR_U)
		class->keys.key_w = 0;
	else if (key == class->kint.K_A || key == class->kint.K_AR_L)
		class->keys.key_a = 0;
	else if (key == class->kint.K_S || key == class->kint.K_AR_D)
		class->keys.key_s = 0;
	else if (key == class->kint.K_D || key == class->kint.K_AR_R)
		class->keys.key_d = 0;
	else if (key == class->kint.K_NP_PLU || key == class->kint.K_AR_R)
		class->keys.np_plus = 0;
	else if (key == class->kint.K_NP_MIN || key == class->kint.K_AR_R)
		class->keys.np_minus = 0;
	return (0);
}

int	key_move(t_hooks *class)
{
	if (class->keys.key_w)
		key_up(class);
	if (class->keys.key_s)
		key_down(class);
	if (class->keys.key_d)
		key_right(class);
	if (class->keys.key_a)
		key_left(class);
	if (class->keys.np_plus)
		increase_resolution(class);
	if (class->keys.np_minus)
		decrease_resolution(class);
	return (0);
}
