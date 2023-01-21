/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykifadji <ykifadji@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 15:46:00 by ykifadji          #+#    #+#             */
/*   Updated: 2023/01/18 08:26:21 by ykifadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	j;

	j = -1;
	if ((!s1 || !s2) || (!s1 && !s2))
		return (0);
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (0);
	str = ft_strcpy(str, (char *)s1);
	while (s2[++j])
		str[ft_strlen(s1) + j] = (char)s2[j];
	str[ft_strlen(s1) + j] = '\0';
	free((char *)s1);
	return (str);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	if (!s)
		return (0);
	if (!c || c == 1024)
		return ((char *)s + ft_strlen(s));
	i = 0;
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			return ((char *)s + i);
		i++;
	}
	return (0);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = -1;
	if (!src)
		return (0);
	while (src[++i])
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}

int	ft_size(char *s, unsigned int start, size_t len)
{
	int	size;

	size = ft_strlen(s) - start;
	while ((size_t)size > len)
		size--;
	return (size);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	i;
	unsigned int	j;

	if (!s)
		return (0);
	if (*s == 0 || ft_strlen(s) <= start)
		return (0);
	str = malloc((ft_size(s, start, len) + 1) * sizeof(char));
	if (!str)
		return (0);
	i = 0;
	while (s[i])
	{
		if (start == i)
		{
			j = 0;
			while (len-- && s[i])
				str[j++] = s[i++];
			str[j] = 0;
			return (str);
		}
		i++;
	}
	return (0);
}
