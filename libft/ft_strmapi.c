/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykifadji <ykifadji@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:42:53 by ykifadji          #+#    #+#             */
/*   Updated: 2022/11/18 17:55:50 by ykifadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (!s)
		return (0);
	str = malloc(ft_strlen(s) + 1 * sizeof(char));
	if (!str)
		return (0);
	while (s[i])
	{
		str[j] = f(i, (char)s[i]);
		i++;
		j++;
	}
	str[j] = '\0';
	return (str);
}
