/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykifadji <ykifadji@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 11:39:03 by ykifadji          #+#    #+#             */
/*   Updated: 2023/01/22 12:55:21 by ykifadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <string.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_list
{
	int		ret;
	char	buf[BUFFER_SIZE + 1];
	char	*final;
}	t_list;

char	*get_next_line(int fd);
char	*get_l(char *temp, char *final, char *buf, int ret);
char	*trim_temp(char *temp, char *final);
char	*trim_buf(char *temp, char *final, char *buf);
char	*ft_error(char *final, char *temp);

size_t	ft_strlen(char const *str);
char	*ft_strchr(char *s, int c);
char	*ft_strcpy(char *dest, char *src);
char	*ft_strjoin(char const *s1, char const *s2, int x);
char	*ft_substr(char *s, unsigned int start, size_t len);

#endif