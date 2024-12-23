# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: saalarco <saalarco@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/04 17:50:16 by saalarco          #+#    #+#              #
#    Updated: 2024/12/23 12:27:04 by saalarco         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
#                                     CONFIG                                   #
################################################################################

NAME		:= so_long
CC		:= cc
FLAGS    	:= -g -Wall -Wextra -Werror

HEADERS	= -I ./include -I ${LIBMLX}/include

ifdef VERBOSE
    SILENT :=
else
    SILENT := @
endif

LIBMLX		= ./MLX42
LIBFT		= ./libft

# LIBS	= ${LIBMLX}/build/libmlx42.a -ldl -lglfw -pthread -lm ${LIBFT}/libft.a 
LIBS = ${LIBFT}/libft.a


################################################################################
#                                 PROGRAM'S SRCS                               #
################################################################################

SRCS		= src/so_long.c \
	src/arguments_valid.c

# SRCS		= ./hello_world_mlx/mlx_hello_world0.c
                         
OBJS        := $(SRCS:.c=.o)

.c.o:
	${CC} ${FLAGS} -o $@ -c $< ${HEADERS}

################################################################################
#                                  Makefile  objs                              #
################################################################################


CLR_RMV		:= \033[0m
RED		    := \033[1;31m
GREEN		:= \033[1;32m
YELLOW		:= \033[1;33m
BLUE		:= \033[1;34m
CYAN 		:= \033[1;36m
RM		    := rm -f

all: libft libmlx ${NAME}

libft:
	@${MAKE} -C ${LIBFT}

libmlx:
	@cmake -DDEBUG=1 $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

${NAME}: ${OBJS}
	@${CC} ${FLAGS} ${OBJS} ${LIBS} ${HEADERS} -o ${NAME}

clean:
	rm -rf ${LIBMLX}/build
	make -C ${LIBFT} clean
	@rm -rf $(OBJS)

fclean: clean
	make -C ${LIBFT} fclean
	@rm -rf $(OBJS)
	@rm -rf $(NAME)

re: clean all

.PHONY: all clean fclean re libmlx libft
