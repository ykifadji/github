/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykifadji <ykifadji@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 14:29:50 by ykifadji          #+#    #+#             */
/*   Updated: 2022/11/11 15:43:10 by ykifadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*dstcpy;
	unsigned const char	*srcpy;

	if (!dest && !src)
		return (dest);
	dstcpy = dest;
	srcpy = src;
	while (n--)
		*dstcpy++ = *srcpy++;
	return (dest);
}
