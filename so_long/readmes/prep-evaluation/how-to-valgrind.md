# How to valgrind

## Example makefile 
```makefile
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: saalarco <saalarco@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/04 17:50:16 by saalarco          #+#    #+#              #
#    Updated: 2025/01/03 17:23:30 by saalarco         ###   ########.fr        #
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
	src/get_map/flood_fill.c
                         
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

TEST_WINDOW_SRCS	= $(TEST_DIR)/test_window.c \
	src/get_map/free_parsed_map.c \
	src/get_map/parse_map.c \
	src/get_map/validate_map_contents.c \
	src/get_map/validate_map_playable.c \
	src/get_map/flood_fill.c \
	src/window.c

TEST_WINDOW_BIN		= ./$(TEST_DIR)/tests_window

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
	@echo "$(GREEN)Tests valgrind window module passed! $(CLR_RMV)$(BLUE)but you better check the output above$(CLR_RMV)"

tfsanitize_window: libft libmlx $(TEST_WINDOW_BIN)
	$(CC) $(FLAGS) -fsanitize=address $(INCLUDES) $(TEST_WINDOW_SRCS) $(LIBS) -o $(TEST_WINDOW_BIN)
	@echo "$(YELLOW)Running tests...$(CLR_RMV)"
	@./$(TEST_WINDOW_BIN)
	@echo "$(GREEN)Tests fsanitize window module passed! $(CLR_RMV)$(BLUE)but you better check the output above$(CLR_RMV)"

tlldb_window : libft libmlx $(TEST_WINDOW_BIN)
	$(CC) $(FLAGS) -g $(INCLUDES) $(TEST_WINDOW_SRCS) $(LIBS) -o $(TEST_WINDOW_BIN)
	@echo "$(YELLOW)Running tests...$(CLR_RMV)"
	lldb ./$(TEST_WINDOW_BIN)

$(TEST_HELLO_WORLD_BIN): $(TEST_HELLO_WORLD_SRCS)
	$(CC) $(FLAGS) $(INCLUDES) $(TEST_HELLO_WORLD_SRCS) $(LIBS) -o $(TEST_HELLO_WORLD_BIN)

tval_hello_world: libft libmlx $(TEST_HELLO_WORLD_BIN)
	$(CC) $(FLAGS) $(INCLUDES) $(TEST_HELLO_WORLD_SRCS) $(LIBS) -o $(TEST_HELLO_WORLD_BIN)
	@echo "$(YELLOW)Running tests...$(CLR_RMV)"
	@valgrind  --leak-check=full \
			--show-leak-kinds=all \
			--track-origins=yes \
			--log-file=valgrind_hello_world.log \
			./$(TEST_HELLO_WORLD_BIN)
	@echo "$(GREEN)Tests valgrind hello_world module passed! $(CLR_RMV)$(BLUE)but you better check the output above$(CLR_RMV)"

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
	@rm -rf $(TEST_WINDOW_BIN)
	@rm -rf $(TEST_HELLO_WORLD_BIN)

re: clean all

.PHONY: all clean fclean re libmlx libft
```

## Examples of Using Valgrind

Valgrind is a powerful tool for detecting memory leaks and other memory-related errors in C programs. Here are some examples of how to use Valgrind in the context of the provided Makefile:

### Running Valgrind Tests for the `get_map` Module

To run Valgrind tests for the `get_map` module, use the following command:

```bash
make tval_get_map
```

This command will compile the test code for the `get_map` module and run it with Valgrind. Valgrind will perform memory leak checks, track memory origins, and generate a log file (`tests/valgrind_get_map.log`) with the results.

### Running Valgrind Tests for the `window` Module

To run Valgrind tests for the `window` module, use the following command:

```bash
make tval_window
```

This command will compile the test code for the `window` module and run it with Valgrind. Valgrind will perform memory leak checks, suppress known issues related to the `mlx` library, and generate a log file (`tests/valgrind_window.log`) with the results.

### Running Valgrind Tests for the `hello_world` Module

To run Valgrind tests for the `hello_world` module, use the following command:

```bash
make tval_hello_world
```

This command will compile the test code for the `hello_world` module and run it with Valgrind. Valgrind will perform memory leak checks, track memory origins, and generate a log file (`valgrind_hello_world.log`) with the results.

Remember to check the output of the Valgrind tests for any memory-related issues or errors. Valgrind can help you identify and fix potential memory leaks and other memory-related bugs in your C programs.

## Flags Used in Valgrind Commands

--leak-check=full: This flag enables detailed memory leak checking. Valgrind will provide information about all memory leaks detected, including the stack trace of the allocation.

--show-leak-kinds=all: With this flag, Valgrind will display information about all types of memory leaks, including reachable, indirect, and definitely lost memory.

--track-origins=yes: Enabling this flag allows Valgrind to track the origin of uninitialized values. It can help identify the source of uninitialized memory errors.

--quiet: This flag suppresses unnecessary output from Valgrind, making the test results easier to read.

--tool=memcheck: This flag specifies the Valgrind tool to use. In this case, we are using the memcheck tool, which is the default tool for detecting memory errors.

--keep-debuginfo=yes: Enabling this flag preserves the debug information in the executable, allowing Valgrind to provide more accurate and detailed error reports.

## How to use valgrind to generate supressions file

Use a Suppression File

    Generate Suppressions:
    Run:

valgrind --leak-check=full \
         --show-leak-kinds=all \
         --gen-suppressions=all \
         --log-file=valgrind_supp.log \
         ./your_executable

Then copy the relevant suppression blocks from valgrind_supp.log into a file, e.g. mlx.supp, like this example: 

{
   <insert_a_suppression_name_here>
   Memcheck:Leak
   match-leak-kinds: definite
   fun:malloc
   fun:malloc
   fun:_dl_find_object_update
   fun:dl_open_worker_begin
   fun:_dl_catch_exception
   fun:dl_open_worker
   fun:_dl_catch_exception
   fun:_dl_open
   fun:dlopen_doit
   fun:_dl_catch_exception
   fun:_dl_catch_error
   fun:_dlerror_run
   fun:dlopen_implementation
   fun:dlopen@@GLIBC_2.34
}
{
   <insert_a_suppression_name_here>
   Memcheck:Addr8
   fun:strncmp
   fun:is_dst
   fun:_dl_dst_substitute
   fun:fillin_rpath.isra.0
   fun:decompose_rpath
   fun:cache_rpath
   fun:cache_rpath
   fun:_dl_map_object
   fun:openaux
   fun:_dl_catch_exception
   fun:_dl_map_object_deps
   fun:dl_open_worker_begin
   fun:_dl_catch_exception
   fun:dl_open_worker
}
{
   <insert_a_suppression_name_here>
   Memcheck:Addr8
   fun:strncmp
   fun:is_dst
   fun:_dl_dst_count
   fun:expand_dynamic_string_token
   fun:fillin_rpath.isra.0
   fun:decompose_rpath
   fun:cache_rpath
   fun:cache_rpath
   fun:_dl_map_object
   fun:openaux
   fun:_dl_catch_exception
   fun:_dl_map_object_deps
   fun:dl_open_worker_begin
   fun:_dl_catch_exception
   fun:dl_open_worker
}

Apply the Suppressions:

valgrind --leak-check=full \
         --show-leak-kinds=all \
         --suppressions=mlx.supp \
         ./your_executable

Now Valgrind won’t list known library allocations as leaks, making your logs much cleaner.