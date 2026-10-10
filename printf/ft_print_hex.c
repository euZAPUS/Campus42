/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsanch3 <alsanch3@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 19:54:28 by alsanch3          #+#    #+#             */
/*   Updated: 2026/10/10 17:30:00 by alsanch3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthex(unsigned long n, char *base)
{
	char	c;

	if (n >= 16)
		ft_puthex(n / 16, base);
	c = base[n % 16];
	write(1, &c, 1);
}

int	ft_hexlen(unsigned long n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 16;
		count++;
	}
	return (count);
}

int	ft_print_hex(unsigned long n, char *base)
{
	ft_puthex(n, base);
	return (ft_hexlen(n));
}

int	ft_print_ptr(void *ptr)
{
	long int	counter;

	counter = 0;
	if (ptr == NULL)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	counter = ft_print_hex((unsigned long) ptr, "0123456789abcdef");
	return (2 + counter);
}
