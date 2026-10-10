/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsanch3 <alsanch3@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 19:54:28 by alsanch3          #+#    #+#             */
/*   Updated: 2026/10/10 17:30:00 by alsanch3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_conversion(char letra, va_list *args)
{
	if (letra == 'c')
		return (ft_print_char(va_arg(*args, int)));
	if (letra == 's')
		return (ft_print_str(va_arg(*args, char *)));
	if (letra == 'd' || letra == 'i')
		return (ft_print_nbr(va_arg(*args, int)));
	if (letra == 'u')
		return (ft_print_nbr(va_arg(*args, unsigned int)));
	if (letra == '%')
		return (ft_print_char('%'));
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
			count++;
			i++;
		}
		else if (format[i + 1] != '\0')
		{
			count = count + ft_conversion(format[i + 1], &args);
			i += 2;
		}
		else
			i++;
	}
	va_end(args);
	return (count);
}
