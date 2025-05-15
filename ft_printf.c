/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpinto-g <vpinto-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 12:59:41 by vpinto-g          #+#    #+#             */
/*   Updated: 2025/05/15 18:09:31 by vpinto-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_format_convert (va_list args, const char format)
{
	unsigned int	count;
	
	count = 0;
	if (format == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (format == 's')
		count += ft_printstr(va_arg(args, char *));
	else if (format == 'd')
		count += ft_putnbr(va_arg(args, int));
	else if (format == 'p')
		count += ft_putadress(va_arg(args, t_ull));
	else if (format == '%')
		count += ft_putchar('%');
	return (count);
}


int	ft_printf(const char *str, ...)
{
	va_list			args;
	unsigned int	i;
	unsigned int	count;

	i = 0;
	count = 0;
	if(!str)
		return (-1);
	va_start (args, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%' && str[i + 1] != '\0')
		{
			count += ft_format_convert (args, str[i + 1]);
			i += 2;
		}
		else
		{
			count += ft_putchar(str[i]);
			i++;
		}
	}
	va_end (args);
	return (count);
}

int main(void)
{
	printf ("%d\n",printf("%s eu sou o %d\n", NULL, 2));
	printf("%d\n", ft_printf("%s eu sou o %d\n", NULL, 2));
}