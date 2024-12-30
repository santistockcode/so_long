# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: saalarco <saalarco@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/04 17:50:16 by saalarco          #+#    #+#              #
#    Updated: 2024/12/30 17:22:14 by saalarco         ###   ########.fr        #
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
	src/get_map/free_parsed_map.c \
	src/get_map/parse_map.c
                         
OBJS        := $(SRCS:.c=.o)

.c.o:
	${CC} ${FLAGS} -o $@ -c $< ${HEADERS}

TEST_GET_MAP_SRCS  	= $(TEST_DIR)/test_get_map.c \
	src/get_map/free_parsed_map.c \
	src/get_map/parse_map.c \
	src/get_map/validate_map_contents.c \
	src/get_map/validate_map_playable.c \
	src/get_map/flood_fill.c
	
TEST_GET_MAP_BIN     = ./$(TEST_DIR)/tests_get_map


################################################################################
#                                  Makefile recipes                            #
################################################################################


CLR_RMV		:= \033[0m
RED		    := \033[1;31m
GREEN		:= \033[1;32m
YELLOW		:= \033[1;33m
BLUE		:= \033[1;34m
CYAN 		:= \033[1;36m
BPURPLE		:= \033[1;35m
RM		    := rm -f

all: libft libmlx ${NAME}

libft:
	@${MAKE} -C ${LIBFT}

libmlx:
	@cmake -DDEBUG=1 $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

${NAME}: ${OBJS}
	@${CC} ${FLAGS} ${OBJS} ${LIBS} ${HEADERS} -o ${NAME}


################################################################################
#                                  Tests                                       #
################################################################################

test_get_map: libft $(TEST_GET_MAP_BIN)
	@echo "$(YELLOW)Running tests...$(CLR_RMV)"
	@./$(TEST_GET_MAP_BIN)
	@echo "$(GREEN)Unit tests for get_map module passed!$(CLR_RMV)"

$(TEST_GET_MAP_BIN): $(TEST_GET_MAP_SRCS)
	$(CC) $(FLAGS) $(INCLUDES) $(TEST_GET_MAP_SRCS) $(LIBS) -o $(TEST_GET_MAP_BIN)

# test_other_module...

# $(TEST_OTER_MOUDLE_BIN)...

tval_get_map: libft $(TEST_GET_MAP_BIN)
	$(CC) $(FLAGS) $(INCLUDES) $(TEST_GET_MAP_SRCS) $(LIBS) -o $(TEST_GET_MAP_BIN)
	@echo "$(YELLOW)Running tests...$(CLR_RMV)"
	@valgrind --leak-check=full \
			--show-leak-kinds=all \
			--track-origins=yes \
			./$(TEST_GET_MAP_BIN)
	@echo "$(GREEN)Tests valgrind get_map module passed! $(CLR_RMV)$(BLUE)but you better check the output above$(CLR_RMV)"

tfsanitize_get_map: libft $(TEST_GET_MAP_BIN)
	$(CC) $(FLAGS) -fsanitize=address $(INCLUDES) $(TEST_GET_MAP_SRCS) $(LIBS) -o $(TEST_GET_MAP_BIN)
	@echo "$(YELLOW)Running tests...$(CLR_RMV)"
	@./$(TEST_GET_MAP_BIN)
	@echo "$(GREEN)Tests fsanitize get_map module passed! $(CLR_RMV)$(BLUE)but you better check the output above$(CLR_RMV)"

# utils lldb
tlldb_get_map : libft $(TEST_GET_MAP_BIN)
	$(CC) $(FLAGS) -g $(INCLUDES) $(TEST_GET_MAP_SRCS) $(LIBS) -o $(TEST_GET_MAP_BIN)
	@echo "$(YELLOW)Running tests...$(CLR_RMV)"
	lldb ./$(TEST_GET_MAP_BIN)

# test: test_get_map test_render  # add other module test targets
#	@echo "$(GREEN)All tests in all modules passed!$(CLR_RMV)"

# tval_all: tval_get_map tval_render
# 	@echo "$(GREEN)All Valgrind tests passed for all modules!$(CLR_RMV)"

# Mimic a full CI pipeline
ci: clean
	@echo "==> Building libraries..."
	@$(MAKE) libft
	@$(MAKE) libmlx

	@echo "==> Building main project..."
	@$(MAKE) all

	@echo "==> Running get_map tests..."
	@$(MAKE) test_get_map

	@echo "==> Running Valgrind tests..."
	@$(MAKE) tval_get_map

	@echo "==> Running AddressSanitizer tests..."
	@$(MAKE) tfsanitize_get_map

	@echo "==> CI-like pipeline complete!"

clean:
	rm -rf ${LIBMLX}/build
	make -C ${LIBFT} clean
	@rm -rf $(OBJS)

fclean: clean
	make -C ${LIBFT} fclean
	@rm -rf $(OBJS)
	@rm -rf $(NAME)
	@rm -rf $(TEST_GET_MAP_BIN)

re: clean all

.PHONY: all clean fclean re libmlx libft
