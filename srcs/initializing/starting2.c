/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   starting2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendonc <dmendonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 16:40:35 by dmendonc          #+#    #+#             */
/*   Updated: 2022/10/06 20:31:56 by dmendonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractal.h"

void	starting_class(t_hooks *class)
{
	class->keys = starting_keys();
	class->zoom = starting_zoom();
	class->win = starting_window(1100, 1100);
	class->img = starting_image(class->win);
	class->nbr = starting_numbers();
	class->initial = starting_numbers();
	class->kint = starting_kint();
	class->times_zoomed = 1;
	class->max_it = 25;
	class->it = 0;
}

void	choosing_fractal(char *str, t_hooks *class)
{
	if (compare(str, "mandelbrot") == -2)
		class->wich_fractal = 1;
	else if (compare(str, "julia") == -2)
		class->wich_fractal = 2;
	else if (compare(str, "manual") == -2)
		class->wich_fractal = 3;
	else if (compare(str, "hourglass") == -2)
		class->wich_fractal = 4;
	else
	{
		ft_printf("not a legal input. turning off.\n");
		exit(0);
	}
}

t_kint	starting_kint(void)
{
	t_kint	new;

	new.k_a = 97;
	new.k_w = 119;
	new.k_s = 115;
	new.k_d = 100;
	new.k_esc = 65307;
	new.k_ar_l = 65361;
	new.k_ar_u = 65362;
	new.k_ar_r = 65363;
	new.k_ar_d = 65364;
	new.k_np_min = 65453;
	new.k_np_plu = 65451;
	new.m_scr_u = 4;
	new.m_scr_d = 5;
	new.m_click = 1;
	new.k_n = 110;
	return (new);
}
