/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sources.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vascopinto <vascopinto@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 13:04:35 by vpinto-g          #+#    #+#             */
/*   Updated: 2025/05/19 17:43:10 by vascopinto       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return(write(1, &c, 1));
}
int	ft_printstr(const char *s)
{
	int	i;

		if (!s)
			s = "(null)";
	i = 0;
	while (s[i])
	{
		ft_putchar(s[i++]);
	}
	return (i);
}
int ft_putnbr(long n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		i += ft_putchar('-');
		n = -n;
		i += ft_putnbr(n);
	}
		else if (n > 9)
	{
		i += ft_putnbr (n / 10);
		i += ft_putnbr (n % 10);
	}
	else
		i += ft_putchar (n + 48);
	return (i);
}
int ft_putadress(t_ull adress)
{
	int	count;

	if (adress <= 0)
		count += write(1, "(nil)", 5);
	else
	{
		count += write(1, "0x", 2);
		count += ft_hexa(adress , 'x');
	}
		return (count);
}
int	ft_hexa(t_ull hexa, char c)
{
	int count;

	count = 0;
	if (hexa >= 16)
	{
		count += ft_hexa(hexa / 16, c);
		count += ft_hexa(hexa % 16, c);
	}
	else if (hexa <= 9)
	{
		count += ft_putchar(hexa + '0');
	}
	else if (hexa >= 10 || hexa <= 15)
	{
		if (c == 'x')
			count += ft_putchar(hexa - 10 + 'a');
		else if (c == 'X')
			count =+ ft_putchar(hexa - 10 + 'A');
	}
	return (count);
}