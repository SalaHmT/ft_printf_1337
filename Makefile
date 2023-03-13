# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shamsate <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/13 22:47:12 by shamsate          #+#    #+#              #
#    Updated: 2023/03/14 00:22:29 by shamsate         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= lib_ft_printf.a

CC	= cc 

CFLAGS	= -Wall -Wextra -Werror

AR	= ar rc

RM	= rm -Rf

SRC_DIR	= src

SRCS =	$(SRC_DIR)/ft_printf_putchar.c \
				$(SRC_DIR)/ft_printf_putstr.c \
				$(SRC_DIR)/ft_printf_putnbr.c \
				$(SRC_DIR)/ft_printf_uns_putnbr.c \
				$(SRC_DIR)/ft_printf_uns_putpointer.c \
				$(SRC_DIR)/ft_printf_puthex.c \
				ft_printf.c \

OBJ =	 $(SRCS:%.c=.$(BUILD_DIR)/%.o)

all:	$(NAME)

$(NAME):  $(OBJ)
		$(AR) $(NAME) $(OBJ)  		

$(BUILD_DIR)/%.o: %.c ft_printf.h
		$(CC) $(CFLAGS)  -c  $< 

clean:
		$(RM) $(OBJ) 

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re