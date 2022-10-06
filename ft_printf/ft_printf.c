/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendonc <dmendonc@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 21:33:30 by dmendonc          #+#    #+#             */
/*   Updated: 2022/02/26 21:33:36 by dmendonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	check_legal(const char *str, char c)
{
	while (*str)
	{
		if (*(char *)str == c)
		{
			return (10);
		}
		str++;
	}
	return (-10);
}

static int	wich_func(char wich, va_list args)
{
	int	counter;

	counter = 0;
	if (wich == 'c')
		counter = print_char(va_arg(args, int));
	else if (wich == 's')
		counter = print_str(va_arg(args, const char *));
	else if (wich == 'p')
		counter = print_adress(va_arg(args, unsigned long long int));
	else if (wich == 'd')
		counter = print_nbr(va_arg(args, long long int));
	else if (wich == 'i')
		counter = print_int(va_arg(args, int));
	else if (wich == 'u')
		counter = print_unsnbr(va_arg(args, unsigned long long int));
	else if (wich == 'x')
		counter = print_hexlow(va_arg(args, long long int));
	else if (wich == 'X')
		counter = print_hexupp(va_arg(args, long long int));
	else
	{
		write(1, "%", 1);
		counter++;
	}
	return (counter);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		counter;

	counter = 0;
	i = 0;
	if (!str || !*str)
		return (0);
	va_start (args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (check_legal("cspdiuxX%", str[++i]) > 0)
				counter += wich_func(str[i], args);
		}
		else
		{
			write(1, &str[i], 1);
			counter++;
		}
		i++;
	}
	va_end(args);
	return (counter);
}

/* int	main(void)
{
	int						counter;
	int		nbr;

	counter = ft_printf("%i - %s - %p %d - %c - %lu - %x %X %%", \
	20, "", (void *)-1, '\0', -20, -1, -1, 200000000);
	printf("\n\n%d\n\n", counter);
	nbr = printf("%i - %s - %p %d - %c - %u - %x %X %%", 20, "", \
	(void *)-1, '\0', -20, -1, -1, 200000000);
	printf("\n%d\n\n", nbr);
	
	//counter = printf("..%lu..\n", nbr);
	//printf("%d\n", counter);
} */