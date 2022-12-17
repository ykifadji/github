/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykifadji <ykifadji@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 09:27:36 by ykifadji          #+#    #+#             */
/*   Updated: 2022/11/11 15:40:32 by ykifadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	d;
	size_t	s;
	size_t	i;

	if ((!dest || !src) && !n)
		return (0);
	i = 0;
	d = ft_strlen(dest);
	s = ft_strlen(src);
	if (n == 0 || d >= n)
		return (s + n);
	while (src[i] && i < (n - 1 - d))
	{
		dest[i + d] = src[i];
		i++;
	}
	dest[i + d] = '\0';
	return (d + s);
}
