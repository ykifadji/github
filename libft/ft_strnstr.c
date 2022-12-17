/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykifadji <ykifadji@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 12:08:29 by ykifadji          #+#    #+#             */
/*   Updated: 2022/11/14 16:16:04 by ykifadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	n;

	if (!*s2)
		return ((char *)s1);
	n = 0;
	while (n < len && s1[n])
	{
		if (!(ft_strncmp((char *)&s1[n], s2, ft_strlen(s2))))
		{	
			if (n + ft_strlen(s2) > len)
				return (0);
			return ((char *)&s1[n]);
		}
		n++;
	}
	return (0);
}
