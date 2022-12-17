/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykifadji <ykifadji@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 15:28:35 by ykifadji          #+#    #+#             */
/*   Updated: 2022/12/17 08:46:38 by ykifadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	int			i;
	int			ret;
	char		*str;

	i = 0;
	ret = read(fd, buf, BUFFER_SIZE);
	while(buf[i] != '\n')
	{
		printf("%c\n", buf[i]);
		i++;
	}
	printf("%d\n", i);
	str = malloc(sizeof(char) * (i + 1));
	i = 0;
	while (buf[i] != '\n')
	{
		read(fd, buf, BUFFER_SIZE);
		str[i] = buf[i];
		i++;
	}
	buf[ret] = '\0';
	str[i] ='\0';
	return (str);
}
