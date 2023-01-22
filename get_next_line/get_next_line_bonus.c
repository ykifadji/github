/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykifadji <ykifadji@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 11:38:55 by ykifadji          #+#    #+#             */
/*   Updated: 2023/01/22 13:21:08 by ykifadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	final = ft_strjoin(final, before_nl, 1);
	ft_strcpy(temp, after_nl);
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
	after_nl = ft_substr(buf, i + 1, ft_strlen(buf) - i);
	final = ft_strjoin(final, before_nl, 1);
	ft_strcpy(temp, after_nl);
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
		final = ft_strjoin(final, buf, 0);
	return (final);
}

char	*ft_error(char *final, char *temp)
{
	free(final);
	final = NULL;
	temp[0] = 0;
	return (0);
}

char	*get_next_line(int fd)
{
	t_list		var;
	static char	temp[1024][BUFFER_SIZE + 1];

	var.ret = 1;
	var.buf[0] = '\0';
	if (fd < 0 || fd > 1024)
		return (0);
	var.final = malloc(sizeof(char));
	var.final[0] = '\0';
	if (ft_strchr(temp[fd], '\n') && *temp[fd])
		return (trim_temp(temp[fd], var.final));
	var.final = ft_strjoin(var.final, temp[fd], 0);
	while (var.ret && !ft_strchr(var.buf, '\n'))
	{
		var.ret = read(fd, var.buf, BUFFER_SIZE);
		if (var.ret == -1)
			return (get_l(temp[fd], var.final, var.buf, var.ret));
		var.final = get_l(temp[fd], var.final, var.buf, var.ret);
	}
	if (var.ret == 0 && var.final[0] == '\0')
		return (ft_error(var.final, temp[fd]));
	else if (var.ret == 0 && !ft_strchr(temp[fd], '\n'))
		temp[fd][0] = 0;
	return (var.final);
}
