/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_adress.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendonc <dmendonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 20:57:18 by dmendonc          #+#    #+#             */
/*   Updated: 2022/10/06 19:48:20 by dmendonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*alloc_pointr(unsigned long int nbr, int i)
{
	char	*ptr;

	if (nbr == 0)
	{
		ptr = malloc((i + 2) * sizeof(char));
		if (!ptr)
			return (NULL);
		if (nbr == 0)
			*ptr = 48;
		ptr += (i + 1) * sizeof(char);
		*ptr = '\0';
	}
	else
	{
		ptr = malloc((i + 1) * sizeof(char));
		if (!ptr)
			return (NULL);
		ptr += i * sizeof(char);
		*ptr = '\0';
	}
	ptr -= sizeof(char);
	return (ptr);
}

static int	nbr_of_digs(unsigned long int number)
{
	int	times;

	times = 0;
	while (number > 0)
	{
		number /= 16;
		times++;
	}
	return (times);
}

char	*convert_adress(unsigned long int nbr, char *base)
{
	int					i;
	int					resto;
	char				*array;

	i = nbr_of_digs(nbr);
	array = alloc_pointr(nbr, i);
	if (!array)
		return (NULL);
	while (nbr > 0)
	{
		resto = nbr % 16;
		nbr = nbr / 16;
		*array = base[resto];
		if (nbr > 0)
			array -= sizeof(char);
	}
	return (array);
}
