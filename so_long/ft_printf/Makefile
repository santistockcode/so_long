# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: saalarco <saalarco@student.42madrid>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/12 18:50:25 by saalarco          #+#    #+#              #
#    Updated: 2024/11/04 17:46:51 by saalarco         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ******** VARIABLES GENERALES ********

NAME = libftprintf.a

LIB = ar rcs


SRC = ft_printf.c ft_putchar_count.c ft_putnbr_count.c ft_putstr_count.c ft_putbase_count.c ft_strlen.c

OBJ = ${SRC:.c=.o}

RM = rm -f

CC = cc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	$(LIB) $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
