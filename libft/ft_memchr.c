/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykifadji <ykifadji@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 12:29:06 by ykifadji          #+#    #+#             */
/*   Updated: 2022/11/28 09:00:57 by ykifadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t size)
{
	size_t	i;
	char	*str;
	size_t	s_len;

	if (size == 0)
		return (0);
	i = 0;
	str = (char *)s;
	s_len = ft_strlen(s);
	if (c == '\0')
		return (str + s_len);
	while (i < size)
	{
		if (str[i] == (char)c)
			return ((char *)str + i);
		i++;
	}
	return (0);
}
