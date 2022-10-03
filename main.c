/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendonc <dmendonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 22:47:33 by dmendonc          #+#    #+#             */
/*   Updated: 2022/05/16 05:02:15 by dmendonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	main_loop(t_hooks *class)
{
	key_move(class);
	mlx_put_image_to_window(class->img.mlx, class->img.win, class->img.img, \
	0, 0);
	return (0);
}

void	go_for_julia(char **argv, int argc, t_hooks *class)
{
	if (argc == 2)
	{
		class->nbr.j_c_x = 0;
		class->nbr.j_c_y = -0.78;
		fill_julia(class);
	}
	else if (argc == 4)
	{
		getting_c_for_julia(argv[2], argv[3], class);
		fill_julia(class);
	}
	else
		safety_two();
}

int	main(int argc, char **argv)
{
	t_hooks		class;

	if (argc > 1)
	{
		starting_class(&class);
		choosing_fractal(argv[1], &class);
		mlx_put_image_to_window(class.img.mlx, class.img.win, class.img.img, \
		0, 0);
		if (class.wich_fractal == 1)
			fill_mandelbrot(&class);
		else if (class.wich_fractal == 2)
			go_for_julia(argv, argc, &class);
		else if (class.wich_fractal == 3)
			manual();
		mlx_loop_hook(class.img.mlx, &main_loop, &class);
		mlx_hook(class.img.win, 2, 1L << 2, &key_press, &class.img);
		mlx_hook(class.img.win, 3, 1L << 1, &key_release, &class.img);
		mlx_hook(class.img.win, 17, 0, &cross, &class.img);
		mlx_hook(class.img.win, 4, 1L << 2, &mouse_press, &class.img);
		mlx_hook(class.img.win, 5, 1L << 6, &mouse_release, &class.img);
		mlx_loop(class.img.mlx);
	}
	else
		safety_one();
}
