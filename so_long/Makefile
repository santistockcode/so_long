# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: saalarco <saalarco@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/04 17:50:16 by saalarco          #+#    #+#              #
#    Updated: 2025/01/09 17:05:01 by saalarco         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

###############################################################################
#                              PROJECT SETTINGS                               #
###############################################################################

NAME		:= so_long

# Compiler & Flags
CC		:= cc
FLAGS    	:= -g -Wall -Wextra -Werror
MAKEFLAGS += --no-print-directory

# Headers
HEADERS	= -I ./include -I ${LIBMLX}/include

# Libraries
LIBMLX		= ./MLX42
LIBFT		= ./libft
MLX_LIB    := $(LIBMLX)/build/libmlx42.a
LIBFT_LIB  := $(LIBFT)/libft.a
LIBS	= ${LIBMLX}/build/libmlx42.a -ldl -lglfw -pthread -lm ${LIBFT}/libft.a 

ifdef VERBOSE
    SILENT :=
else
    SILENT := @
endif

###############################################################################
#                              COLOR SETTINGS                                 #
###############################################################################

CLR_RMV   := \033[0m
RED       := \033[1;31m
GREEN     := \033[1;32m
YELLOW    := \033[1;33m
BLUE      := \033[1;34m
CYAN      := \033[1;36m
BPURPLE   := \033[1;35m

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
	src/window.c \
	src/display_mlx.c \
	src/render/images_textures.c \
	src/render/images_textures_utils.c
                         
OBJS        := $(SRCS:.c=.o)

###############################################################################
#                              TEST DIRECTORIES & FILES                       #
###############################################################################

TEST_DIR = tests

TEST_GET_MAP_SRCS  	= $(TEST_DIR)/test_get_map.c \
	src/get_map/free_parsed_map.c \
	src/get_map/parse_map.c \
	src/get_map/validate_map_contents.c \
	src/get_map/validate_map_playable.c \
	src/common.c \
	src/get_map/flood_fill.c
TEST_GET_MAP_BIN     = $(TEST_DIR)/tests_get_map

TEST_WINDOW_SRCS	= $(TEST_DIR)/test_window.c \
	src/get_map/free_parsed_map.c \
	src/get_map/parse_map.c \
	src/get_map/validate_map_contents.c \
	src/get_map/validate_map_playable.c \
	src/get_map/flood_fill.c \
	src/common.c \
	src/window.c
TEST_WINDOW_BIN		= $(TEST_DIR)/tests_window

TEST_COMMON_SRCS	= $(TEST_DIR)/test_common.c
TEST_COMMON_BIN		= $(TEST_DIR)/tests_common

TEST_HELLO_WORLD_SRCS = $(TEST_DIR)/test_hello_world.c 
TEST_HELLO_WORLD_BIN = $(TEST_DIR)/tests_hello_world

TEST_RENDER_SRCS = $(TEST_DIR)/integrate_render.c \
	src/argument_valid.c \
	src/get_map/free_parsed_map.c \
	src/get_map/parse_map.c \
	src/get_map/validate_map_contents.c \
	src/get_map/validate_map_playable.c \
	src/get_map/flood_fill.c \
	src/common.c \
	src/window.c
TEST_RENDER_BIN = $(TEST_DIR)/integrate_render

###############################################################################
#                              DEFAULT RULES                                  #
###############################################################################

.PHONY: all clean fclean re

all: $(NAME)

# Compile the main executable 
$(NAME): $(OBJS) $(LIBFT_LIB) $(MLX_LIB)
	@echo "$(BLUE)[Linking]$(CLR_RMV) $@"
	$(SILENT)$(CC) $(FLAGS) $^ $(LIBS) $(HEADERS) -o $@

# Generic rule to build object files from .c
%.o: %.c
	@echo "$(GREEN)[Compiling]$(CLR_RMV) $<"
	$(SILENT)$(CC) $(FLAGS) -c $< -o $@ $(HEADERS)

###############################################################################
#                              LIBRARIES                                      #
###############################################################################

$(LIBFT_LIB):
	@echo "Building libft..."
	@$(MAKE) -C $(LIBFT)
	# (That Makefile in libft should produce libft.a inside that directory.)

$(MLX_LIB):
	@echo "Building MLX..."
	@cmake -DDEBUG=1 -DGLFW_FETCH=0 -S $(LIBMLX) -B $(LIBMLX)/build
	@make -C $(LIBMLX)/build -j4



###############################################################################
#                              TESTS                                          #
###############################################################################

##
## 1) get_map module tests
##
test_get_map: $(TEST_GET_MAP_BIN) $(LIBFT_LIB)
	@echo "$(YELLOW)Running get_map tests...$(CLR_RMV)"
	$(SILENT)@./$(TEST_GET_MAP_BIN)
	@echo "$(GREEN)Unit tests for get_map module passed!$(CLR_RMV)"

$(TEST_GET_MAP_BIN): $(TEST_GET_MAP_SRCS)
	$(SILENT)$(CC) $(FLAGS) $(INCLUDES) $(TEST_GET_MAP_SRCS) $(LIBS) -o $(TEST_GET_MAP_BIN)


tval_get_map: $(TEST_GET_MAP_BIN) $(LIBFT_LIB)
	$(SILENT)$(CC) $(FLAGS) $(INCLUDES) $(TEST_GET_MAP_SRCS) $(LIBS) -o $(TEST_GET_MAP_BIN)
	@echo "$(YELLOW)Running valgrind get_map tests...$(CLR_RMV)"
	$(SILENT)@valgrind --leak-check=full \
			--show-leak-kinds=all \
			--track-origins=yes \
			--log-file=tests/valgrind_get_map.log \
			./$(TEST_GET_MAP_BIN)
	@echo "$(GREEN)Tests valgrind get_map module passed! $(CLR_RMV)$(BLUE)...but you better check the output$(CLR_RMV)"

tfsanitize_get_map: $(TEST_GET_MAP_BIN) $(LIBFT_LIB)
	$(SILENT)$(CC) $(FLAGS) -fsanitize=address $(INCLUDES) $(TEST_GET_MAP_SRCS) $(LIBS) -o $(TEST_GET_MAP_BIN)
	@echo "$(YELLOW)Running fsanitize get_map tests...$(CLR_RMV)"
	$(SILENT)@./$(TEST_GET_MAP_BIN)
	@echo "$(GREEN)Tests fsanitize get_map module passed! $(CLR_RMV)$(BLUE)...but you better check the output$(CLR_RMV)"

tlldb_get_map : $(TEST_GET_MAP_BIN) $(LIBFT_LIB) 
	$(CC) $(FLAGS) -g $(INCLUDES) $(TEST_GET_MAP_SRCS) $(LIBS) -o $(TEST_GET_MAP_BIN)
	@echo "$(YELLOW)Running tests...$(CLR_RMV)"
	lldb ./$(TEST_GET_MAP_BIN)

##
## 2) window module tests
##
test_window: $(TEST_WINDOW_BIN) $(LIBFT_LIB) $(MLX_LIB)
	@echo "$(YELLOW)Running test_window tests...$(CLR_RMV)"
	$(SILENT)@./$(TEST_WINDOW_BIN)
	@echo "$(GREEN)Unit tests for window module passed!$(CLR_RMV)"

$(TEST_WINDOW_BIN): $(TEST_WINDOW_SRCS)
	$(SILENT)$(CC) $(FLAGS) $(INCLUDES) $(TEST_WINDOW_SRCS) $(LIBS) -o $(TEST_WINDOW_BIN)

tval_window: $(TEST_WINDOW_BIN) $(LIBFT_LIB) $(MLX_LIB)
	$(SILENT)$(CC) $(FLAGS) $(INCLUDES) $(TEST_WINDOW_SRCS) $(LIBS) -o $(TEST_WINDOW_BIN)
	@echo "$(YELLOW)Running valgrind test_window tests...$(CLR_RMV)"
	$(SILENT)@valgrind  --leak-check=full \
			--show-leak-kinds=definite \
			--suppressions=mlx_dl.supp \
			--log-file=tests/valgrind_window.log \
			./$(TEST_WINDOW_BIN)
	@echo "$(YELLOW)Checking Valgrind log for definitely lost leaks...$(CLR_RMV)"
	# Parse the log to see if “definitely lost” is non-zero.
	$(SILENT)@grep -q "definitely lost: 0 bytes in 0 blocks" tests/valgrind_window.log && \
		echo "$(GREEN)No definite leaks found!$(CLR_RMV)" || \
		( echo "$(RED)Definite leaks found! Check tests/valgrind_window.log$(CLR_RMV)" ; exit 1 )

	@echo "$(BLUE)Valgrind test for window module complete!$(CLR_RMV)"

tfsanitize_window: $(TEST_WINDOW_BIN) $(LIBFT_LIB) $(MLX_LIB)
	$(SILENT)$(CC) $(FLAGS) -fsanitize=address $(INCLUDES) $(TEST_WINDOW_SRCS) $(LIBS) -o $(TEST_WINDOW_BIN)
	@echo "$(YELLOW)Running fsanitize test_window tests...$(CLR_RMV)"
	$(SILENT)@./$(TEST_WINDOW_BIN)
	@echo "$(GREEN)Tests fsanitize window module passed! $(CLR_RMV)$(BLUE)...but you better check the output$(CLR_RMV)"

tlldb_window : $(TEST_WINDOW_BIN) $(LIBFT_LIB) $(MLX_LIB)
	$(CC) $(FLAGS) -g $(INCLUDES) $(TEST_WINDOW_SRCS) $(LIBS) -o $(TEST_WINDOW_BIN)
	@echo "$(YELLOW)Running tests...$(CLR_RMV)"
	lldb ./$(TEST_WINDOW_BIN)

##
## 3) common module tests
##
test_common: $(TEST_COMMON_BIN) $(LIBFT_LIB) $(MLX_LIB)
	@echo "$(YELLOW)Running common tests...$(CLR_RMV)"
	$(SILENT)@./$(TEST_COMMON_BIN)
	@echo "$(GREEN)Unit tests for common module passed!$(CLR_RMV)"

$(TEST_COMMON_BIN): $(TEST_COMMON_SRCS)
	$(SILENT)$(CC) $(FLAGS) $(INCLUDES) $(TEST_COMMON_SRCS) $(LIBS) -o $(TEST_COMMON_BIN)

tval_common: $(TEST_COMMON_BIN) $(LIBFT_LIB) $(MLX_LIB)
	$(SILENT)$(CC) $(FLAGS) $(INCLUDES) $(TEST_COMMON_SRCS) $(LIBS) -o $(TEST_COMMON_BIN)
	@echo "$(YELLOW)Running valgrind common tests...$(CLR_RMV)"
	$(SILENT)@valgrind --leak-check=full \
			--show-leak-kinds=all \
			--track-origins=yes \
			--log-file=tests/valgrind_common.log \
			./$(TEST_COMMON_BIN)
	@echo "$(GREEN)Tests valgrind common module passed! $(CLR_RMV)$(BLUE)...but you better check the output$(CLR_RMV)"

tfsanitize_common: $(TEST_COMMON_BIN) $(LIBFT_LIB) $(MLX_LIB)
	$(SILENT)$(CC) $(FLAGS) -fsanitize=address $(INCLUDES) $(TEST_COMMON_SRCS) $(LIBS) -o $(TEST_COMMON_BIN)
	@echo "$(YELLOW)Running fsanitize common tests...$(CLR_RMV)"
	$(SILENT)@./$(TEST_COMMON_BIN)
	@echo "$(GREEN)Tests fsanitize common module passed! $(CLR_RMV)$(BLUE)...but you better check the output$(CLR_RMV)"

##
## how-to) hello_world tests (example)
##
$(TEST_HELLO_WORLD_BIN): $(TEST_HELLO_WORLD_SRCS)
	$(CC) $(FLAGS) $(INCLUDES) $(TEST_HELLO_WORLD_SRCS) $(LIBS) -o $(TEST_HELLO_WORLD_BIN)

tval_hello_world: $(TEST_HELLO_WORLD_BIN) $(LIBFT_LIB) $(MLX_LIB)
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

##
## integration-test) render
##
$(TEST_RENDER_BIN): $(TEST_RENDER_SRCS) $(LIBFT_LIB) $(MLX_LIB)
	$(CC) $(FLAGS) $(INCLUDES) $(TEST_RENDER_SRCS) $(LIBS) -o $(TEST_RENDER_BIN)

test_i_render: $(TEST_RENDER_BIN) $(LIBFT_LIB) $(MLX_LIB)
	@echo "$(YELLOW)Running integration tests...$(CLR_RMV)"
	$(SILENT)@./$(TEST_RENDER_BIN)
	@echo "$(GREEN)Integration tests for render module passed!$(CLR_RMV)"

test_i_lldbrender: $(TEST_RENDER_BIN) $(LIBFT_LIB) $(MLX_LIB)
	$(CC) $(FLAGS) -g $(INCLUDES) $(TEST_RENDER_SRCS) $(LIBS) -o $(TEST_RENDER_BIN)
	@echo "$(YELLOW)Running tests...$(CLR_RMV)"
	lldb ./$(TEST_RENDER_BIN)

test_i_valrender: $(TEST_RENDER_BIN) $(LIBFT_LIB) $(MLX_LIB)
	$(SILENT)$(CC) $(FLAGS) $(INCLUDES) $(TEST_RENDER_SRCS) $(LIBS) -o $(TEST_RENDER_BIN)
	@echo "$(YELLOW)Running valgrind integration tests...$(CLR_RMV)"
	$(SILENT)@valgrind --leak-check=full \
			--show-leak-kinds=all \
			--track-origins=yes \
			--log-file=tests/valgrind_render.log \
			./$(TEST_RENDER_BIN)
	@echo "$(GREEN)Tests valgrind render module passed! $(CLR_RMV)$(BLUE)...but you better check the output$(CLR_RMV)"

test_i_fsanrender: $(TEST_RENDER_BIN) $(LIBFT_LIB) $(MLX_LIB)
	$(SILENT)$(CC) $(FLAGS) -fsanitize=address $(INCLUDES) $(TEST_RENDER_SRCS) $(LIBS) -o $(TEST_RENDER_BIN)
	@echo "$(YELLOW)Running fsanitize integration tests...$(CLR_RMV)"
	$(SILENT)@./$(TEST_RENDER_BIN)
	@echo "$(GREEN)Tests fsanitize render module passed! $(CLR_RMV)$(BLUE)...but you better check the output$(CLR_RMV)"


###############################################################################
#                              CI-LIKE PIPELINE                               #
###############################################################################

ci: fclean $(LIBFT_LIB) $(MLX_LIB)
	
	# TODO: library libft and limlx directly from git

	@echo "==> Module get_map tests..."
	$(SILENT)$(MAKE) test_get_map

	@echo "==> Module Valgrind tests for get_map..."
	$(SILENT)$(MAKE) tval_get_map

	@echo "==> Module FSanitize tests for get_map..."
	$(SILENT)$(MAKE) tfsanitize_get_map

	@echo "==> Module window tests..."
	$(SILENT)$(MAKE) test_window

	@echo "==> Module Valgrind window tests..."
	$(SILENT)$(MAKE) tval_window

	@echo "==> Module FSanitize window tests..."
	$(SILENT)$(MAKE) tfsanitize_window

	@echo "==> Module common tests..."
	$(SILENT)$(MAKE) test_common

	@echo "==> Module Valgrind common tests..."
	$(SILENT)$(MAKE) tval_common

	@echo "==> Module FSanitize common tests..."
	$(SILENT)$(MAKE) tfsanitize_common

	@echo "==> Building main project..."
	$(SILENT)$(MAKE) all

	@echo "$(GREEN)==> CI-like pipeline complete!$(CLR_RMV)"

###############################################################################
#                              CLEAN RULES                                    #
###############################################################################

clean:
	@echo "$(RED)[Cleaning objects]$(CLR_RMV)"
	$(SILENT)rm -rf $(OBJS)
	$(SILENT)make -C $(LIBFT) clean
	$(SILENT)rm -rf $(LIBMLX)/build

fclean: clean
	@echo "$(RED)[Removing executables]$(CLR_RMV)"
	$(SILENT)make -C $(LIBFT) fclean
	$(SILENT)rm -rf $(NAME)
	$(SILENT)rm -rf $(TEST_GET_MAP_BIN)
	$(SILENT)rm -rf $(TEST_WINDOW_BIN)
	$(SILENT)rm -rf $(TEST_COMMON_BIN)
	$(SILENT)rm -rf $(TEST_HELLO_WORLD_BIN)
	$(SILENT)rm -rf $(TEST_RENDER_BIN)

re: fclean all

# .PHONY: all clean fclean re libmlx libft
