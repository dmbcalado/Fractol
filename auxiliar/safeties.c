/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safeties.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendonc <dmendonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 19:20:47 by dmendonc          #+#    #+#             */
/*   Updated: 2022/05/16 16:19:12 by dmendonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractal.h"

void	safety_one(void)
{
	printf("\n\nPlease choose wich fractal you want by writing its name.");
	printf("\nHere's the options:\n\n-> Mandelbrot set (type mandelbrot)");
	printf("\n-> Julia set (type julia , or julia with the coordinates for c");
	printf("separated by a space)\n\n		 examples:\nmandelbrot\njulia\n");
	printf("julia 0.567 1.234\n\nturning off.\n");
}

void	safety_two(void)
{
	printf("\nWARNING!\n");
	printf("\nyou forgot to input the coordinates of c.\n");
	printf("examples:\njulia 0.567 1.234\n\n");
	exit(0);
}

void	manual(void)
{
	printf("\n\n     You selected the manual.\n\nTo choose wich fractal");
	printf(" you want to see type : ./fractol (type)\n");
	printf("\n     Here's the options:\n\n-> Mandelbrot set (type mandelbrot)");
	printf("\n-> Julia set (type julia , or julia with the coordinates for c");
	printf("separated by a space)\n\n     Examples:\n\n./fractol mandelbrot\n");
	printf("./fractol julia\n");
	printf("./fractol julia 0.567 1.234\n\nturning off.\n\n");
	exit (0);
}
