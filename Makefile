# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: saalarco <saalarco@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/04 17:50:16 by saalarco          #+#    #+#              #
#    Updated: 2024/11/13 19:00:51 by saalarco         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
#                                     CONFIG                                   #
################################################################################

NAME		:= so_long
CC		:= cc
FLAGS    	:= -Wall -Wextra -Werror

HEADERS	= -I ./includes -I ${LIBMLX}/include -I ${LIBFT} -I ${LIBGNL} -I ${LIBPRINTF}

ifdef VERBOSE
    SILENT :=
else
    SILENT := @
endif

LIBMLX		= ./MLX42
LIBFT		= ./libft
LIBPRINTF	= ./ft_printf
LIBGNL		= ./get_next_line
LIBS	= ${LIBMLX}/build/libmlx42.a -ldl -lglfw -pthread -lm ${LIBFT}/libft.a ${LIBPRINTF}/libftprintf.a ${LIBGNL}/get_next_line.a

################################################################################
#                                 PROGRAM'S SRCS                               #
################################################################################

# SRCS		= so_long.c utils.c
SRCS		= mlx_hello_world0.c
                         
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

all: libft libmlx libprintf libgnl ${NAME}

libft:
	@${MAKE} -C ${LIBFT}

libmlx:
	@cmake -DDEBUG=1 $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

libprintf:
	@${MAKE} -C ${LIBPRINTF}

libgnl:
	@${MAKE} -C ${LIBGNL}

${NAME}: ${OBJS}
	@${CC} ${FLAGS} ${OBJS} ${LIBS} ${HEADERS} -o ${NAME}

clean:
	rm -rf ${LIBMLX}/build
	make -C ${LIBFT} clean
	make -C ${LIBPRINTF} clean
	make -C ${LIBGNL} clean
	@rm -rf $(OBJS)

fclean: clean
	make -C ${LIBFT} fclean
	make -C ${LIBPRINTF} fclean
	make -C ${LIBGNL} fclean
	@rm -rf $(OBJS)


	@rm -rf $(NAME)

re: clean all

.PHONY: all clean fclean re libmlx libft libprintf libgnl
