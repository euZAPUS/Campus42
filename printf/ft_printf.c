/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_printf.c                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: alsanch3 <alsanch3@student.42malaga.com>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/08 19:54:28 by alsanch3         #+#    #+#              */
/*   Updated: 2026/10/08 21:16:25 by alsanch3        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "libft.h"

void	ft_putnbr_long(long int n)
{
	char	c;

	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr_long(n / 10);
	}
	c = (n % 10) + '0';
	write(1, &c, 1);
}

int	ft_numlen(long n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	else if (n < 0)
	{
		n = -n;
		count++;
	}
	while (n > 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

int	ft_print_char(int c)
{
	char	letra;

	letra = c;
	write(1, &letra, 1);
	return (1);
}

int	ft_print_str(char *s)
{
	if (s == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	ft_putstr_fd(s, 1);
	return (ft_strlen(s));
}

int	ft_print_nbr(long n)
{
	ft_putnbr_long(n);
	return (ft_numlen(n));
}

int	ft_conversion(char letra, va_list *args)
{
	if (letra == 'c')
		return (ft_print_char(va_arg(*args, int)));
	if (letra == 's')
		return (ft_print_str(va_arg(*args, char *)));
	if (letra == 'd')
		return (ft_print_nbr(va_arg(*args, int)));
	if (letra == 'i')
		return (ft_print_nbr(va_arg(*args, int)));
	if (letra == '%')
		return (ft_print_char('%'));
	if (letra == 'u')
		return ((ft_print_nbr(va_arg(*args, unsigned int))));
	return (0);
}

int	ft_printf(char const *format, ...)
{
	int		i;
	int		count;
	va_list	args;

	va_start(args, format);
	count = 0;
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] != '%')
		{
			write(1, &format[i], 1);
			i++;
			count++;
		}
		else if (format[i] == '%' && format[i + 1] != '\0')
		{
			count = count + ft_conversion(format[i + 1], &args);
			i += 2;
		}
		else if (format[i] == '%' && format[i + 1] == '\0')
			i++;
	}
	va_end(args);
	return (count);
}
