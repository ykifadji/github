/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykifadji <ykifadji@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 09:39:45 by ykifadji          #+#    #+#             */
/*   Updated: 2022/12/07 08:17:33 by ykifadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *s, ...);

int		ft_print_putnbr(int n);
size_t	ft_print_putchar(char c);
size_t	ft_print_putstr(char *s);
size_t	ft_print_unsgn(unsigned int u);
size_t	ft_putnbr_base(unsigned long long n, char *base);

size_t	ft_count(long u);
size_t	ft_count_base(size_t n);

#endif