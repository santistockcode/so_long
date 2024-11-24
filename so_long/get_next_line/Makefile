# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: saalarco <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/04 17:40:13 by saalarco          #+#    #+#              #
#    Updated: 2024/11/04 17:47:39 by saalarco         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line.a

LIB = ar rcs

SRC = get_next_line.c \
	get_next_line_utils.c

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
