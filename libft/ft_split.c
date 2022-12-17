/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykifadji <ykifadji@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 09:03:58 by ykifadji          #+#    #+#             */
/*   Updated: 2022/11/23 10:34:41 by ykifadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_word(char const *s, char c)
{
	int	i;
	int	n;

	n = 0;
	i = 0;
	while (s[i] && c == s[i])
		i++;
	while (s[i])
	{
		n++;
		while (s[i] && c != s[i])
			i++;
		while (s[i] && c == s[i])
			i++;
	}
	return (n);
}

static int	count(char const *s, char c)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (s[i] && c == s[i])
		i++;
	while (s[i] && c != s[i])
	{
		n++;
		i++;
	}
	return (n);
}

static int	count_c(char const *s, char c)
{
	int	i;

	i = 0;
	while (c == s[i])
		i++;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		i;
	int		j;
	int		k;

	if (!s)
		return (0);
	str = malloc((count_word(s, c) + 1) * sizeof(char *));
	if (!str)
		return (0);
	i = 0;
	j = 0;
	while (s[i])
	{
		i += count_c(s + i, c);
		if (!s[i])
			break ;
		str[j] = malloc((count(s + i, c) + 1) * sizeof(char));
		k = 0;
		while (s[i] && c != s[i])
			str[j][k++] = s[i++];
		str[j++][k] = '\0';
	}
	str[j] = 0;
	return (str);
}
