/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykifadji <ykifadji@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 15:28:35 by ykifadji          #+#    #+#             */
/*   Updated: 2023/01/20 15:58:06 by ykifadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*trim_temp(char *temp, char *final)
{
	char	*before_nl;
	char	*after_nl;
	size_t	i;

	i = 0;
	while (temp[i] != '\n')
		i++;
	before_nl = ft_substr(temp, 0, i + 1);
	after_nl = ft_substr(temp, i + 1, (ft_strlen(temp) - i));
	final = ft_strjoin(final, before_nl);
	ft_strcpy(temp, after_nl);
	free(before_nl);
	free(after_nl);
	return (final);
}

char	*trim_buf(char *temp, char *final, char *buf)
{
	char	*before_nl;
	char	*after_nl;
	size_t	i;

	i = 0;
	while (buf[i] != '\n')
		i++;
	before_nl = ft_substr(buf, 0, i + 1);
	after_nl = ft_substr(buf, i + 1, (ft_strlen(buf) - i));
	final = ft_strjoin(final, before_nl);
	ft_strcpy(temp, after_nl);
	free(before_nl);
	free(after_nl);
	return (final);
}

char	*get_l(char *temp, char *final, char *buf, int ret)
{
	if (ret == -1)
	{
		free(final);
		temp[0] = '\0';
		return (0);
	}
	buf[ret] = '\0';
	if (ft_strchr(buf, '\n'))
		final = trim_buf(temp, final, buf);
	else
		final = ft_strjoin(final, buf);
	return (final);
}

char	*get_next_line(int fd)
{
	char		buf[BUFFER_SIZE + 1];
	static char	temp[BUFFER_SIZE + 1];
	int			ret;
	char		*final;

	ret = -1;
	buf[0] = '\0';
	final = malloc(sizeof(char));
	final[0] = '\0';
	if (ft_strchr(temp, '\n') && *temp)
		return (trim_temp(temp, final));
	final = ft_strjoin(final, temp);
	while (!ft_strchr(buf, '\n') && ret)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret == -1)
			return (get_l(temp, final, buf, ret));
		final = get_l(temp, final, buf, ret);
	}
	if (ret == 0 && final[0] == '\0')
	{
		free(final);
		final = NULL;
		temp[0] = 0;
		return (0);
	}
	else if (ret == 0 && ft_strchr(temp, '\n'))
		temp[0] = 0;
	return (final);
}
