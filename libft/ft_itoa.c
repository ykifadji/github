/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykifadji <ykifadji@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:29:07 by ykifadji          #+#    #+#             */
/*   Updated: 2022/11/27 13:09:09 by ykifadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(int n)
{
	long	i;
	int		nbr;

	i = 1;
	nbr = 0;
	if (n < 0)
	{
		nbr++;
		n *= -1;
	}
	if (n == 0)
		nbr = 1;
	while (n && n / i)
	{
		i *= 10;
		nbr++;
	}
	return (nbr);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		counter;
	long	nbr;

	nbr = (long)n;
	counter = ft_count(n);
	if (n < 0)
		nbr *= -1;
	str = malloc((counter + 1) * sizeof(char));
	if (!str)
		return (0);
	str[counter] = 0;
	while (counter-- > 0)
	{
		str[counter] = nbr % 10 + '0';
		nbr /= 10;
		if (n < 0 && counter == 0)
			str[counter] = '-';
	}
	return (str);
}
