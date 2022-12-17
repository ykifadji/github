# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ykifadji <ykifadji@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/18 13:59:43 by ykifadji          #+#    #+#              #
#    Updated: 2022/11/29 08:19:02 by ykifadji         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_bzero.c \
	ft_isalnum.c \
	ft_isascii.c \
	ft_isprint.c \
	ft_strlen.c \
	ft_toupper.c \
	ft_isalpha.c \
	ft_isdigit.c \
	ft_memset.c \
	ft_tolower.c \
	ft_strlcpy.c \
	ft_strlcat.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_atoi.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_strdup.c \
	ft_strncmp.c \
	ft_memcmp.c \
	ft_memchr.c \
	ft_calloc.c \
	ft_strnstr.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_substr.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_strmapi.c \
	ft_striteri.c \
	ft_split.c \
	ft_itoa.c

OBJS = $(SRCS:.c=.o)

SRCS_BONUS = ft_lstnew.c \
	ft_lstadd_front.c \
	ft_lstsize.c \
	ft_lstlast.c \
	ft_lstadd_back.c \
	ft_lstdelone.c \
	ft_lstiter.c \
	ft_lstclear.c \
	ft_lstmap.c

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

NAME = libft.a
all : $(NAME)

.c.o:
		gcc -Wall -Wextra -Werror -c -I ./include $< -o $(<:.c=.o)

ifdef BONUS_EXIST
OBJ = $(OBJS) $(OBJS_BONUS)
else
OBJ = $(OBJS)
endif

$(NAME): $(OBJ)
	ar cr $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -rf $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

bonus:
	$(MAKE) BONUS_EXIST=1
	ranlib $(NAME)

.PHONY: all clean fclean re