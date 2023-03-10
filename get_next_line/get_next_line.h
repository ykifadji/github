/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykifadji <ykifadji@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 15:34:20 by ykifadji          #+#    #+#             */
/*   Updated: 2023/01/22 11:03:50 by ykifadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <string.h>
# include <stdlib.h>
# include <unistd.h>

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