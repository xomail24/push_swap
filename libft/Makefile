# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: icheri <icheri@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/23 23:38:14 by icheri            #+#    #+#              #
#    Updated: 2022/02/01 20:56:03 by icheri           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= libft.a

SRCS			=	ft_isalpha.c	ft_isdigit.c	ft_isalnum.c\
					ft_isascii.c	ft_isprint.c	ft_strlen.c\
					ft_memset.c		ft_bzero.c		ft_memcpy.c\
					ft_memmove.c	ft_strlcpy.c	ft_strlcat.c\
					ft_toupper.c	ft_tolower.c	ft_strchr.c \
					ft_strrchr.c	ft_strncmp.c	ft_memchr.c\
					ft_memcmp.c		ft_strnstr.c	ft_atoi.c\
					ft_calloc.c		ft_strdup.c		ft_substr.c\
					ft_strjoin.c	ft_strtrim.c	ft_itoa.c\
					ft_split.c		ft_strmapi.c	ft_striteri.c\
					ft_putchar_fd.c	ft_putstr_fd.c	ft_putendl_fd.c\
					ft_putnbr_fd.c	ft_strcmp.c

BONUS			=

HEADER			= libft.h
OBJ				= $(SRCS:.c=.o)
OBJ_B			= $(BONUS:.c=.o)

CC				= gcc
CFLAGS			= -Wall -Wextra -Werror -I$(HEADER)

.PHONY:			all clean fclean re bonus

all:			$(NAME)

$(NAME):		$(OBJ) $(HEADER)
				ar rcs $(NAME) $?

%.o:			 %.c $(HEADER)
				$(CC) $(CFLAGS) -c $< -o $@

bonus:			$(OBJ) $(OBJ_B)
				ar rcs $(NAME) $(OBJ) $(OBJ_B)

clean:
				rm -f $(OBJ) $(OBJ_B)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all




