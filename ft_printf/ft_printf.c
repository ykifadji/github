/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykifadji <ykifadji@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 15:20:37 by ykifadji          #+#    #+#             */
/*   Updated: 2022/12/06 11:00:39 by ykifadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_srchconv(const char *s, va_list args)
{
	size_t	len;

	len = 0;
	if (*s == 'c')
		len = ft_print_putchar(va_arg(args, int));
	else if (*s == 's')
		len = ft_print_putstr(va_arg(args, char *));
	else if (*s == 'p')
	{
		len = write(1, "0x", 2);
		len += ft_putnbr_base(va_arg(args, unsigned long), "0123456789abcdef");
	}
	else if (*s == 'd' || *s == 'i')
		len = ft_print_putnbr(va_arg(args, int));
	else if (*s == 'u')
		len = ft_print_unsgn(va_arg(args, unsigned int));
	else if (*s == 'x')
		len = ft_putnbr_base(va_arg(args, unsigned int), "0123456789abcdef");
	else if (*s == 'X')
		len = ft_putnbr_base(va_arg(args, unsigned int), "0123456789ABCDEF");
	else if (*s == '%')
		len = write(1, "%", 1);
	return (len);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	size_t	len;

	va_start(args, s);
	len = 0;
	while (*s)
	{
		if (*s == '%')
			len += ft_srchconv(++s, args);
		else
			len += write(1, s, 1);
		s++;
	}
	va_end(args);
	return (len);
}
