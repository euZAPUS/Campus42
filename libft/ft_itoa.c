/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsanch3 <alsanch3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/24 14:18:05 by alsanch3          #+#    #+#             */
/*   Updated: 2026/09/25 15:11:39 by alsanch3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digits(long n)
{
	int	digits;

	digits = 0;
	if (n <= 0)
		digits = 1;
	while (n != 0)
	{
		n = n / 10;
		digits++;
	}
	return (digits);
}

char	*ft_itoa(int n)
{
	long int	number;
	char		*str;
	int			len;

	number = n;
	str = (char *) malloc(count_digits(number) + 1);
	if (str == NULL)
		return (NULL);
	len = count_digits(number);
	str[len] = '\0';
	if (number == 0)
		str[0] = '0';
	if (number < 0)
	{
		str[0] = '-';
		number = number * -1;
	}
	while (number > 0)
	{
		len--;
		str[len] = (number % 10) + '0';
		number = number / 10;
	}
	return (str);
}
