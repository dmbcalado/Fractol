/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendonc <dmendonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 14:14:41 by dmendonc          #+#    #+#             */
/*   Updated: 2022/03/01 21:49:09 by dmendonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*alloc_pointer(unsigned long int n, int i)
{
	char	*ptr;

	if (n == 0)
	{
		ptr = malloc(2 * sizeof(char));
		*ptr = '0';
		ptr += sizeof(char);
		*ptr = '\0';
		ptr -= sizeof(char);
		return (ptr);
	}
	else
	{
		ptr = malloc((i + 1) * sizeof(char));
		if (!ptr)
			return (NULL);
		ptr += i * sizeof(char);
		*ptr = '\0';
		ptr -= sizeof(char);
		return (ptr);
	}
}

int	how_many_digs(unsigned long int n)
{
	int	i;

	i = 0;
	while (n > 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char	*ft_utoa(unsigned long int n)
{
	char	*ptr;
	int		i;
	int		resto;

	i = how_many_digs(n);
	ptr = alloc_pointer(n, i);
	if (!ptr)
		return (NULL);
	if (n == 0)
		return (ptr);
	while (n != 0)
	{
		resto = n % 10;
		*ptr = (resto + 48);
		n /= 10;
		ptr -= sizeof(char);
	}
	ptr += sizeof(char);
	return (ptr);
}

/* int	main(void)
{
	char *str;
	int	 i;

	i = 0;
	str = ft_llitoa(-243894384739);
	while (str[i] != '\0')
	{
		write(1,&str[i], 1);
		i++;
	}
}
 */