/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_iuxX.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendonc <dmendonc@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 12:34:57 by dmendonc          #+#    #+#             */
/*   Updated: 2022/02/26 13:21:53 by dmendonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	print_int(int nbr)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = ft_itoa(nbr);
	if (!ptr)
		return (i);
	while (ptr[i] != '\0')
	{
		write(1, &ptr[i], 1);
		i++;
	}
	free(ptr);
	ptr = NULL;
	return (i);
}

int	print_unsnbr(unsigned int nbr)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = ft_utoa(nbr);
	if (!ptr)
		return (i);
	while (ptr[i])
	{
		write(1, &ptr[i], 1);
		i++;
	}
	free(ptr);
	ptr = NULL;
	return (i);
}

int	print_hexlow(long long int nbr)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = convert_to_hex(nbr, "0123456789abcdef");
	if (!ptr)
		return (i);
	while (ptr[i] != '\0')
	{
		write(1, &ptr[i], 1);
		i++;
	}
	if (ptr != NULL)
	{
		free(ptr);
		ptr = NULL;
	}
	return (i);
}

int	print_hexupp(long long int nbr)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = convert_to_hex(nbr, "0123456789ABCDEF");
	if (!ptr)
		return (i);
	while (ptr[i] != '\0')
	{
		write(1, &ptr[i], 1);
		i++;
	}
	free(ptr);
	ptr = NULL;
	return (i);
}

/* int	main(void)
{
	long long int		nbr;
	unsigned long int	nbr2;

	nbr = -21474836;
	nbr2 = 2147483653234;
	print_int(nbr);
	printf("\n");
	print_unsnbr(nbr2);
	printf("\n");
	print_hexlow(nbr);
	printf("\n");
	nbr = -2147483648;
	print_hexupp(nbr2);
	printf("\n");
	nbr = 214748364812122;
	print_hexlow(nbr2);
} */