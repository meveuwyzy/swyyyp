# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dalonso <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/19 15:38:37 by dalonso           #+#    #+#              #
#    Updated: 2021/10/19 15:38:40 by dalonso          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

FLAGS =  -Wall -Wextra -Werror

SRCS = ./main.c \
		utils1.c \
        stack_filler.c \
		src/ft_putstr_fd.c \
		src/ft_atoi.c \
		operations/op1.c \
		operations/op2.c \
		operations/op3.c \
		swyyp/transfer.c \
		swyyp/utils_swp.c \
		swyyp/go_game.c \
		swyyp/small_case.c \
		swyyp/back.c \
		swyyp/back1.c \
		swyyp/go_game2.c \

OBJS = $(SRCS:.cpp=.o)

%.o : %.c
	@gcc $(FLAGS)  -c $< -o $@

all :  $(NAME)

$(NAME):	$(OBJS)
			gcc $(FLAGS) $(OBJS) -o $(NAME)

clean :
	@rm -f $(OBJ)

fclean : clean
	@rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
