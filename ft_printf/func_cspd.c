/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_cspd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendonc <dmendonc@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 13:44:52 by dmendonc          #+#    #+#             */
/*   Updated: 2022/02/25 13:21:12 by dmendonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	print_char(int c)
{
	write(1, &c, 1);
	return (1);
}

int	print_str(const char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}	
	while (str[i])
	{
		write (1, &str[i], 1);
		i++;
	}
	return (i);
}

//print_adress
int	print_adress(unsigned long int adress)
{
	int		i;
	char	*ptr;

	i = 0;
	if (!adress)
	{
		write(1, "0x0", 3);
		return (3);
	}
	write(1, "0x", 2);
	ptr = convert_adress(adress, "0123456789abcdef");
	if (!ptr)
		return (0);
	while (ptr[i])
	{
		write(1, &ptr[i], 1);
		i++;
	}
	if (ptr != NULL)
	{
		free(ptr);
		ptr = NULL;
	}
	return (i + 2);
}

int	print_nbr(int nbr)
{
	char	*str;
	int		i;

	i = 0;
	str = ft_itoa(nbr);
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	if (str != NULL)
	{
		free(str);
		str = NULL;
	}
	return (i);
}

/* int	main(void)
{
	
	char	*str;

	str = malloc(sizeof(char));
	//print_str("\nimprime a adress?\n");
	//printf("%d\n", -2147483666);
	print_adress((unsigned long long int)&str);
	print_str("\n");
	//print_nbr(27300914520);
} */