/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vascopinto <vascopinto@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 15:54:28 by vpinto-g          #+#    #+#             */
/*   Updated: 2025/05/19 17:47:01 by vascopinto       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stddef.h>
# include <limits.h>
# include <stdarg.h>
# include <stdlib.h>

typedef unsigned long long	t_ull;
typedef long long			t_ll;

int ft_putchar(char c);
int ft_printstr(const char *s);
int ft_putnbr(long n);
int ft_putadress(t_ull adress);
int	ft_hexa(t_ull hexa, char c);

#endif