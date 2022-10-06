/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safeties.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendonc <dmendonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 19:20:47 by dmendonc          #+#    #+#             */
/*   Updated: 2022/10/06 19:52:17 by dmendonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractal.h"

void	safety_one(void)
{
	ft_printf("\n\nPlease choose wich fractal you want by writing its name.");
	ft_printf("\nHere's the options:\n\n-> Mandelbrot set (type mandelbrot)");
	ft_printf("\n-> Julia set (type julia , or julia with the coordinates \
	for c");
	ft_printf("separated by a space)\n\n	 examples:\nmandelbrot\njulia\n");
	ft_printf("julia 0.567 1.234\n\nturning off.\n");
}

void	safety_two(void)
{
	ft_printf("\nWARNING!\n");
	ft_printf("\nyou forgot to input the coordinates of c.\n");
	ft_printf("examples:\njulia 0.567 1.234\n\n");
	exit(0);
}

void	manual(void)
{
	ft_printf("\n\n     You selected the manual.\n\nTo choose wich fractal");
	ft_printf(" you want to see type : ./fractol (type)\n");
	ft_printf("\n  Here's the options:\n\n-> Mandelbrot set \
	(type mandelbrot)");
	ft_printf("\n-> Julia set (type julia , or julia with the \
	coordinates for c");
	ft_printf("separated by a space)\n\n     Examples:\n\n./fractol \
	mandelbrot\n");
	ft_printf("./fractol julia\n");
	ft_printf("./fractol julia 0.567 1.234\n\nturning off.\n\n");
	exit (0);
}
