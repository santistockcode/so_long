# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: saalarco <saalarco@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/04 17:50:16 by saalarco          #+#    #+#              #
#    Updated: 2024/12/23 19:43:36 by saalarco         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
#                                     CONFIG                                   #
################################################################################

NAME		:= so_long
CC		:= cc
FLAGS    	:= -g -Wall -Wextra -Werror
HEADERS	= -I ./include -I ${LIBMLX}/include
TEST_DIR = tests

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
	src/arguments_valid.c \
	src/check_valid_map/free_map_data.c \
	src/check_valid_map/get_map_data.c
                         
OBJS        := $(SRCS:.c=.o)

.c.o:
	${CC} ${FLAGS} -o $@ -c $< ${HEADERS}

TEST_CHECK_VALID_MAP_SRCS  	= $(TEST_DIR)/test_check_valid_map.c \
	src/check_valid_map/free_map_data.c \
	src/check_valid_map/get_map_data.c
	
TEST_CHECK_VALID_MAP_BIN     = ./$(TEST_DIR)/tests_check_valid_map


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

test: libft $(TEST_CHECK_VALID_MAP_BIN)
	@echo "$(YELLOW)Running tests...$(CLR_RMV)"
	@./$(TEST_DIR)/tests_check_valid_map
	@echo "$(GREEN)Tests passed!$(CLR_RMV)"

$(TEST_CHECK_VALID_MAP_BIN): $(TEST_CHECK_VALID_MAP_SRCS)
	$(CC) $(FLAGS) $(INCLUDES) $(TEST_CHECK_VALID_MAP_SRCS) $(LIBS) -o $(TEST_CHECK_VALID_MAP_BIN)

tval: libft $(TEST_CHECK_VALID_MAP_BIN)
	$(CC) $(FLAGS) $(INCLUDES) $(TEST_CHECK_VALID_MAP_SRCS) $(LIBS) -o $(TEST_CHECK_VALID_MAP_BIN)
	@echo "$(YELLOW)Running tests...$(CLR_RMV)"
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(TEST_DIR)/tests_check_valid_map
	@echo "$(GREEN)Tests passed!$(CLR_RMV)"

tfsanitize: libft $(TEST_CHECK_VALID_MAP_BIN)
	$(CC) $(FLAGS) -fsanitize=address $(INCLUDES) $(TEST_CHECK_VALID_MAP_SRCS) $(LIBS) -o $(TEST_CHECK_VALID_MAP_BIN)
	@echo "$(YELLOW)Running tests...$(CLR_RMV)"
	@./$(TEST_DIR)/tests_check_valid_map
	@echo "$(GREEN)Tests passed!$(CLR_RMV)"

clean:
	rm -rf ${LIBMLX}/build
	make -C ${LIBFT} clean
	@rm -rf $(OBJS)

fclean: clean
	make -C ${LIBFT} fclean
	@rm -rf $(OBJS)
	@rm -rf $(NAME)
	@rm -rf $(TEST_CHECK_VALID_MAP_BIN)

re: clean all

.PHONY: all clean fclean re libmlx libft
