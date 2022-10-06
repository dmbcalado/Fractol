/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_to_hex.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendonc <dmendonc@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 12:21:49 by dmendonc          #+#    #+#             */
/*   Updated: 2022/02/26 13:21:53 by dmendonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static char	*alloc_pointr(long long int nbr, int i)
{
	char	*ptr;

	if (nbr < 0 || nbr == 0)
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

static int	nbr_of_digs(unsigned int number)
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

char	*convert_to_hex(unsigned int nbr, char *base)
{
	int							i;
	int							resto;
	char						*array;
	unsigned long long int		number;

	number = nbr;
	i = nbr_of_digs(number);
	array = alloc_pointr(nbr, i);
	if (!array)
		return (NULL);
	while (number > 0)
	{
		resto = number % 16;
		number = number / 16;
		*array = base[resto];
		if (number > 0)
			array -= sizeof(char);
	}
	return (array);
}

/* int	main(void)
{
	long long int	nbr;
	char			*result;

	nbr = -21474836;
	result = convert_to_hex(nbr, "0123456789ABCDEF");
	printf("in hexadecimal we got:%s\n", result);
	nbr = -2147483648;
	result = convert_to_hex(nbr, "0123456789abcdef");
	printf("in hexadecimal we got:%s\n", result);
	nbr = 2147483648121445222;
	result = convert_to_hex(nbr, "0123456789abcdef");
	printf("in hexadecimal we got:%s\n", result);
} */