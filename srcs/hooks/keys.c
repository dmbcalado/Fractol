/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendonc <dmendonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 18:52:14 by dmendonc          #+#    #+#             */
/*   Updated: 2022/10/06 20:28:03 by dmendonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractal.h"

int	key_press(int key, t_hooks *class)
{
	if (key == class->kint.k_esc)
		cross(class);
	else if (key == class->kint.k_w || key == class->kint.k_ar_u)
		class->keys.key_w = 1;
	else if (key == class->kint.k_a || key == class->kint.k_ar_l)
		class->keys.key_a = 1;
	else if (key == class->kint.k_s || key == class->kint.k_ar_d)
		class->keys.key_s = 1;
	else if (key == class->kint.k_d || key == class->kint.k_ar_r)
		class->keys.key_d = 1;
	else if (key == class->kint.k_np_plu || key == class->kint.k_ar_r)
		class->keys.np_plus = 1;
	else if (key == class->kint.k_np_min || key == class->kint.k_ar_r)
		class->keys.np_minus = 1;
	else if (key == class->kint.k_n)
		n_key_press(class);
	return (0);
}

int	key_release(int key, t_hooks *class)
{
	if (key == class->kint.k_w || key == class->kint.k_ar_u)
		class->keys.key_w = 0;
	else if (key == class->kint.k_a || key == class->kint.k_ar_l)
		class->keys.key_a = 0;
	else if (key == class->kint.k_s || key == class->kint.k_ar_d)
		class->keys.key_s = 0;
	else if (key == class->kint.k_d || key == class->kint.k_ar_r)
		class->keys.key_d = 0;
	else if (key == class->kint.k_np_plu || key == class->kint.k_ar_r)
		class->keys.np_plus = 0;
	else if (key == class->kint.k_np_min || key == class->kint.k_ar_r)
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

int	cross(t_hooks *class)
{
	mlx_destroy_image(class->img.mlx, class->img.img);
	mlx_destroy_window(class->img.mlx, class->img.win);
	mlx_destroy_display(class->img.mlx);
	free(class->img.mlx);
	exit (0);
}

void	n_key_press(t_hooks *class)
{
	if (class->keys.key_n == 0)
	{
		class->keys.key_n++;
		refreshing_image(class);
		if (class->wich_fractal == 1)
			fill_mandelbrot(class);
		else if (class->wich_fractal == 2)
			fill_julia(class);
		else if (class->wich_fractal == 4)
			fill_hourglass(class);
	}
	else
	{
		class->keys.key_n = 0;
		refreshing_image(class);
		if (class->wich_fractal == 1)
			fill_mandelbrot(class);
		else if (class->wich_fractal == 2)
			fill_julia(class);
		else if (class->wich_fractal == 4)
			fill_hourglass(class);
	}
}
