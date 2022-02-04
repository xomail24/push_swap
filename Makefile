# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: icheri <icheri@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/03 22:23:23 by icheri            #+#    #+#              #
#    Updated: 2022/02/04 23:11:33 by icheri           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap
NAME_B	=	checker

LIBFTDIR = ./libft

SRCS	=	push_swap.c check_input.c make_linked_list.c operation.c radix_sort.c sort_for_index.c sort_small_stack.c
SRCS_B	=	bonus/checker.c check_input.c make_linked_list.c operation.c sort_for_index.c get_next_line.c radix_sort.c sort_small_stack.c

HEADER	=	push_swap.h

OBJ		=	$(patsubst %.c, %.o, $(SRCS))

OBJ_B	=	$(patsubst %.c, %.o, $(SRCS_B))

CC		=	gcc
FLAGS	=	-Wall -Wextra -Werror -I$(HEADER)

FLAGS_BONUS	=	-Wall -Wextra -Werror -I$(HEADER_BONUS)

.PHONY	:	all clean fclean re bonus

all		:	$(NAME)

$(NAME)	:	$(OBJ) $(HEADER)
	@make bonus -C $(LIBFTDIR)
	$(CC) -L./libft -lft $(OBJ) -o $(NAME)

%.o		:	%.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

clean	:
	@rm -f $(OBJ)
	@rm -f $(OBJ_B)
	@make clean -C $(LIBFTDIR)

fclean	:	clean
	@rm -f $(NAME)
	@rm -f $(NAME_B)
	@make fclean -C $(LIBFTDIR)

$(NAME_B)	: $(OBJ_B) $(HEADER)
	@make bonus -C $(LIBFTDIR)
	$(CC) -L./libft -lft $(OBJ_B) -o $(NAME_B)

bonus : $(NAME_B)

re		:	fclean all
