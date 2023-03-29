# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shamsate <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/18 15:11:52 by shamsate          #+#    #+#              #
#    Updated: 2023/03/18 15:11:56 by shamsate         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

CC	= cc

CFLAGS	= -Wall -Wextra -Werror

AR	= ar rc

RM	= rm -Rf

SRC	= src

SRCS =	$(SRC)/ft_printf_dependency.c \
			$(SRC)/ft_printf_uns_dependecy.c \
			ft_printf.c \

OBJ =	$(SRCS:.c=.o)


$(NAME):$(OBJ)
		$(AR) $(NAME) $(OBJ)

all:	$(NAME)

%.o: %.c include/ft_printf.h
		$(CC) $(CFLAGS)  -c  $< -o $@

clean:
		$(RM) $(OBJ)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
