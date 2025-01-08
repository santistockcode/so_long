# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: saalarco <saalarco@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/04 17:50:16 by saalarco          #+#    #+#              #
#    Updated: 2025/01/08 13:36:14 by saalarco         ###   ########.fr        #
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

LIBS	= ${LIBMLX}/build/libmlx42.a -ldl -lglfw -pthread -lm ${LIBFT}/libft.a 
# LIBS = ${LIBFT}/libft.a


################################################################################
#                                 PROGRAM'S SRCS                               #
################################################################################

SRCS		= src/so_long.c \
	src/argument_valid.c \
	src/get_map/free_parsed_map.c \
	src/get_map/parse_map.c \
	src/get_map/validate_map_contents.c \
	src/get_map/validate_map_playable.c \
	src/get_map/flood_fill.c \
	src/common.c \
	src/window.c
                         
OBJS        := $(SRCS:.c=.o)

.c.o:
	${CC} ${FLAGS} -o $@ -c $< ${HEADERS}

TEST_GET_MAP_SRCS  	= $(TEST_DIR)/test_get_map.c \
	src/get_map/free_parsed_map.c \
	src/get_map/parse_map.c \
	src/get_map/validate_map_contents.c \
	src/get_map/validate_map_playable.c \
	src/common.c \
	src/get_map/flood_fill.c
	
TEST_GET_MAP_BIN     = ./$(TEST_DIR)/tests_get_map

TEST_WINDOW_SRCS	= $(TEST_DIR)/test_window.c \
	src/get_map/free_parsed_map.c \
	src/get_map/parse_map.c \
	src/get_map/validate_map_contents.c \
	src/get_map/validate_map_playable.c \
	src/get_map/flood_fill.c \
	src/common.c \
	src/window.c

TEST_WINDOW_BIN		= ./$(TEST_DIR)/tests_window

TEST_COMMON_SRCS	= $(TEST_DIR)/test_common.c

TEST_COMMON_BIN		= ./$(TEST_DIR)/tests_common


TEST_HELLO_WORLD_SRCS = $(TEST_DIR)/test_hello_world.c 

TEST_HELLO_WORLD_BIN = ./$(TEST_DIR)/tests_hello_world



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
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

${NAME}: ${OBJS}
	@${CC} ${FLAGS} ${OBJS} ${LIBS} ${HEADERS} -o ${NAME}


################################################################################
#                                  Tests                                       #
################################################################################

# get_map module
test_get_map: libft $(TEST_GET_MAP_BIN)
	@echo "$(YELLOW)Running tests...$(CLR_RMV)"
	@./$(TEST_GET_MAP_BIN)
	@echo "$(GREEN)Unit tests for get_map module passed!$(CLR_RMV)"

$(TEST_GET_MAP_BIN): $(TEST_GET_MAP_SRCS)
	$(CC) $(FLAGS) $(INCLUDES) $(TEST_GET_MAP_SRCS) $(LIBS) -o $(TEST_GET_MAP_BIN)


tval_get_map: libft $(TEST_GET_MAP_BIN)
	$(CC) $(FLAGS) $(INCLUDES) $(TEST_GET_MAP_SRCS) $(LIBS) -o $(TEST_GET_MAP_BIN)
	@echo "$(YELLOW)Running tests...$(CLR_RMV)"
	@valgrind --leak-check=full \
			--show-leak-kinds=all \
			--track-origins=yes \
			--log-file=tests/valgrind_get_map.log \
			./$(TEST_GET_MAP_BIN)
	@echo "$(GREEN)Tests valgrind get_map module passed! $(CLR_RMV)$(BLUE)but you better check the output above$(CLR_RMV)"

tfsanitize_get_map: libft $(TEST_GET_MAP_BIN)
	$(CC) $(FLAGS) -fsanitize=address $(INCLUDES) $(TEST_GET_MAP_SRCS) $(LIBS) -o $(TEST_GET_MAP_BIN)
	@echo "$(YELLOW)Running tests...$(CLR_RMV)"
	@./$(TEST_GET_MAP_BIN)
	@echo "$(GREEN)Tests fsanitize get_map module passed! $(CLR_RMV)$(BLUE)but you better check the output above$(CLR_RMV)"

tlldb_get_map : libft $(TEST_GET_MAP_BIN)
	$(CC) $(FLAGS) -g $(INCLUDES) $(TEST_GET_MAP_SRCS) $(LIBS) -o $(TEST_GET_MAP_BIN)
	@echo "$(YELLOW)Running tests...$(CLR_RMV)"
	lldb ./$(TEST_GET_MAP_BIN)

# window module
test_window: libft libmlx $(TEST_WINDOW_BIN)
	@echo "$(YELLOW)Running tests...$(CLR_RMV)"
	@./$(TEST_WINDOW_BIN)
	@echo "$(GREEN)Unit tests for window module passed!$(CLR_RMV)"

$(TEST_WINDOW_BIN): $(TEST_WINDOW_SRCS)
	$(CC) $(FLAGS) $(INCLUDES) $(TEST_WINDOW_SRCS) $(LIBS) -o $(TEST_WINDOW_BIN)

tval_window: libft libmlx $(TEST_WINDOW_BIN)
	$(CC) $(FLAGS) $(INCLUDES) $(TEST_WINDOW_SRCS) $(LIBS) -o $(TEST_WINDOW_BIN)
	@echo "$(YELLOW)Running tests...$(CLR_RMV)"
	@valgrind  --leak-check=full \
			--show-leak-kinds=definite \
			--suppressions=mlx_dl.supp \
			--log-file=tests/valgrind_window.log \
			./$(TEST_WINDOW_BIN)
	@echo "$(YELLOW)Checking Valgrind log for definitely lost leaks...$(CLR_RMV)"
	# Parse the log to see if “definitely lost” is non-zero.
	@grep -q "definitely lost: 0 bytes in 0 blocks" tests/valgrind_window.log && \
		echo "$(GREEN)No definite leaks found!$(CLR_RMV)" || \
		( echo "$(RED)Definite leaks found! Check tests/valgrind_window.log$(CLR_RMV)" ; exit 1 )

	@echo "$(BLUE)Valgrind test for window module complete!$(CLR_RMV)"

tfsanitize_window: libft libmlx $(TEST_WINDOW_BIN)
	$(CC) $(FLAGS) -fsanitize=address $(INCLUDES) $(TEST_WINDOW_SRCS) $(LIBS) -o $(TEST_WINDOW_BIN)
	@echo "$(YELLOW)Running tests...$(CLR_RMV)"
	@./$(TEST_WINDOW_BIN)
	@echo "$(GREEN)Tests fsanitize window module passed! $(CLR_RMV)$(BLUE)but you better check the output above$(CLR_RMV)"

tlldb_window : libft libmlx $(TEST_WINDOW_BIN)
	$(CC) $(FLAGS) -g $(INCLUDES) $(TEST_WINDOW_SRCS) $(LIBS) -o $(TEST_WINDOW_BIN)
	@echo "$(YELLOW)Running tests...$(CLR_RMV)"
	lldb ./$(TEST_WINDOW_BIN)

# hello_world lmx module

$(TEST_HELLO_WORLD_BIN): $(TEST_HELLO_WORLD_SRCS)
	$(CC) $(FLAGS) $(INCLUDES) $(TEST_HELLO_WORLD_SRCS) $(LIBS) -o $(TEST_HELLO_WORLD_BIN)

tval_hello_world: libft libmlx $(TEST_HELLO_WORLD_BIN)
	$(CC) $(FLAGS) $(INCLUDES) $(TEST_HELLO_WORLD_SRCS) $(LIBS) -o $(TEST_HELLO_WORLD_BIN)
	@echo "$(YELLOW)Running tests...$(CLR_RMV)"
	@valgrind  --leak-check=full \
			--show-leak-kinds=all \
			--track-origins=yes \
			--log-file=tests/valgrind_hello_world.log \
			./$(TEST_HELLO_WORLD_BIN)
	@echo "$(YELLOW)Checking Valgrind log for definitely lost leaks...$(CLR_RMV)"
	@grep -q "definitely lost: 0 bytes in" tests/valgrind_hello_world.log && \
		echo "$(GREEN)No definite leaks found!$(CLR_RMV)" || \
		( echo "$(RED)Definite leaks found! Check tests/valgrind_hello_world.log$(CLR_RMV)" ; exit 1 )

	@echo "$(BLUE)Valgrind test for window module complete!$(CLR_RMV)"

# common tests
test_common: libft libmlx $(TEST_COMMON_BIN)
	@echo "$(YELLOW)Running tests...$(CLR_RMV)"
	@./$(TEST_COMMON_BIN)
	@echo "$(GREEN)Unit tests for common module passed!$(CLR_RMV)"

$(TEST_COMMON_BIN): $(TEST_COMMON_SRCS)
	$(CC) $(FLAGS) $(INCLUDES) $(TEST_COMMON_SRCS) $(LIBS) -o $(TEST_COMMON_BIN)


# TODO: library libft and limlx directly from git

# Mimic a full CI pipeline
ci: clean
	@echo "==> Building libraries..."
	@$(MAKE) libft
	@$(MAKE) libmlx

	@echo "==> Running get_map tests..."
	@$(MAKE) test_get_map

	@echo "==> Running Valgrind tests..."
	@$(MAKE) tval_get_map

	@echo "==> Running AddressSanitizer tests..."
	@$(MAKE) tfsanitize_get_map

	@echo "==> Running window tests..."
	@$(MAKE) test_window

	@echo "==> Running Valgrind window tests..."
	@$(MAKE) tval_window

	@echo "==> Running common tests..."
	@$(MAKE) test_common

	@echo "==> Building main project..."
	@$(MAKE) all

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
	@rm -rf $(TEST_WINDOW_BIN)
	@rm -rf $(TEST_HELLO_WORLD_BIN)

re: clean all

.PHONY: all clean fclean re libmlx libft
