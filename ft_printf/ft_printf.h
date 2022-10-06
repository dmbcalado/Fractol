/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendonc <dmendonc@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 12:21:49 by dmendonc          #+#    #+#             */
/*   Updated: 2022/02/25 13:21:53 by dmendonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h> 
# include <strings.h>
# include <stdlib.h>
# include <stdarg.h> // lib for variable arguments

int		ft_printf(const char *str, ...);
char	*ft_itoa(int n);
char	*ft_utoa(unsigned long int n);
char	*convert_to_hex(unsigned int nbr, char *base);
char	*convert_adress(unsigned long int nbr, char *base);
int		print_char(int c);
int		print_str(const char *str);
int		print_adress(unsigned long int adress);
int		print_nbr(int nbr);
int		print_int(int nbr);
int		print_unsnbr(unsigned int nbr);
int		print_hexlow(long long int nbr);
int		print_hexupp(long long int nbr);
#endif