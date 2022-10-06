/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendonc <dmendonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 20:34:36 by dmendonc          #+#    #+#             */
/*   Updated: 2022/10/06 20:41:20 by dmendonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fractal.h"

void	zoom_hourglass(t_hooks *c)
{
	ft_printf("zoom in\n");
	c->zoom.h_zoom += 100.0;
	c->zoom.v_zoom += 100.0;
	c->times_zoomed++;
	refreshing_image(c);
	fill_hourglass(c);
}

void	unzoom_hourglass(t_hooks *c)
{
	ft_printf("zoom out\n");
	c->zoom.h_zoom -= 100.0;
	c->zoom.v_zoom -= 100.0;
	c->times_zoomed--;
	refreshing_image(c);
	fill_hourglass(c);
}
