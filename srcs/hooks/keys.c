/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendonc <dmendonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 18:52:14 by dmendonc          #+#    #+#             */
/*   Updated: 2022/10/03 19:31:07 by dmendonc         ###   ########.fr       */
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
	return (0);
}

int	cross(t_hooks *class)
{
	mlx_destroy_window(class->img.mlx, class->img.win);
	exit (0);
	return (0);
}

int	key_release(int key, t_hooks *class)
{
	if (key == class->kint.K_ESC)
	{
		mlx_destroy_window(class->img.mlx, class->img.win);
		exit (0);
	}
	else if (key == class->kint.K_W || key == class->kint.K_AR_U)
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
	if (class->keys.key_esc)
		exit(0);
	return (0);
}
