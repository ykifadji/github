/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykifadji <ykifadji@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 11:39:00 by ykifadji          #+#    #+#             */
/*   Updated: 2023/01/22 12:56:21 by ykifadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char const *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2, int x)
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
	if (x == 1)
		free((char *)s2);
	return (str);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

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
	while (src[++i])
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	i;

	i = 0;
	if (ft_strlen(s) < start)
		return (0);
	if (len <= ft_strlen(s))
		str = malloc(sizeof(char) * (len + 1));
	else
		str = malloc(sizeof(char) * (ft_strlen(s) - start));
	if (!str)
		return (0);
	while (s[start] && start < ft_strlen(s) && i < len)
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}
