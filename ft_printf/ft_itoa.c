/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendonc <dmendonc@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 12:21:49 by dmendonc          #+#    #+#             */
/*   Updated: 2022/02/26 13:22:06 by dmendonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

char	*alloc_ptr(int n, int i, int *menos)
{
	char	*ptr;

	*menos = 1;
	if (n < 0 || n == 0 || n == -0)
	{
		*menos = -1;
		ptr = malloc((i + 2) * sizeof(char));
		if (!ptr)
			return (NULL);
		if (n == 0 || n == -0)
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

int	how_many_digits(int n)
{
	int	i;

	i = 0;
	while (n != 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*ptr;
	int		i;
	int		menos;
	int		resto;

	i = how_many_digits(n);
	ptr = alloc_ptr(n, i, &menos);
	if (!ptr)
		return (NULL);
	if (n == 0 || n == -0)
		return (ptr);
	while (n != 0)
	{
		resto = menos * (n % 10);
		*ptr = (resto + 48);
		n /= 10;
		ptr -= sizeof(char);
	}
	ptr += sizeof(char);
	if (menos == -1)
	{
		ptr -= sizeof(char);
		*ptr = '-';
	}
	return (ptr);
}

/* int	main(void)
{
	char *str;
	int	 i;

	i = 0;
	str = ft_itoa(243894384);
	while (str[i] != '\0')
	{
		write(1,&str[i], 1);
		i++;
	}
} */