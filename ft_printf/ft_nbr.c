/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykifadji <ykifadji@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 10:46:56 by ykifadji          #+#    #+#             */
/*   Updated: 2022/12/06 11:07:10 by ykifadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_count(long u)
{
	size_t	i;
	size_t	len;

	i = 1;
	len = 0;
	if (u < 0)
	{
		u *= -1;
		len++;
	}
	if (u == 0)
		len = 1;
	while (u && u / i)
	{
		i *= 10;
		len++;
	}
	return (len);
}

size_t	ft_count_base(size_t n)
{
	size_t	len;

	len = 0;
	while (n > 15)
	{
		n /= 16;
		len++;
	}
	if (n < 16)
		len++;
	return (len);
}

int	ft_print_putnbr(int n)
{
	size_t	len;

	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	len = ft_count(n);
	if (n < 0)
	{
		n = n * -1;
		ft_print_putchar('-');
	}
	if (n > 9)
	{
		ft_print_putnbr(n / 10);
	}
	ft_print_putchar(n % 10 + '0');
	return (len);
}

size_t	ft_print_unsgn(unsigned int u)
{
	size_t	len;

	len = ft_count(u);
	if (u > 9)
	{
		ft_print_unsgn(u / 10);
	}
	ft_print_putchar(u % 10 + '0');
	return (len);
}

size_t	ft_putnbr_base(unsigned long long n, char *base)
{
	size_t	len;

	len = ft_count_base(n);
	if (n > 15)
	{
		ft_putnbr_base(n / 16, base);
	}
	ft_print_putchar(base[n % 16]);
	return (len);
}
