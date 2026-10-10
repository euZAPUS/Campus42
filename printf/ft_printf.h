/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsanch3 <alsanch3@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 19:54:28 by alsanch3          #+#    #+#             */
/*   Updated: 2026/10/10 17:30:00 by alsanch3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(char const *format, ...);
int		ft_conversion(char letra, va_list *args);

int		ft_print_char(int c);
int		ft_print_str(char *s);
size_t	ft_strlen(const char *s);

int		ft_print_nbr(long n);
void	ft_putnbr_long(long n);
int		ft_numlen(long n);

void	ft_puthex(unsigned long n, char *base);
int		ft_hexlen(unsigned long n);
int		ft_print_hex(unsigned long n, char *base);
int		ft_print_ptr(void *ptr);

#endif
