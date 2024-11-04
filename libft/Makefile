# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: saalarco <saalarco@student.42madrid>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/02 12:51:21 by saalarco          #+#    #+#              #
#    Updated: 2024/02/14 10:11:15 by saalarco         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ******** VARIABLES GENERALES ********

NAME = libft.a
CC = gcc
MKDIR = /usr/bin/mkdir
CFLAGS = -Wall -Werror -Wextra
AR := ar -rc
OBJDIR := objects/
RM := rm -rf
HEADER = ./
SILENT = @

# ******** COLORES ********

GREEN	=	\033[38;5;76m
RED		=	\033[38;5;160m
YELLOW	=	\033[38;5;226m
ORANGE	=	\033[38;5;202m
BLUE	=	\033[38;5;117m
INDI	=	\033[38;5;99m
RESET	=	\033[00m
BLINK   =   \e[5m

# ******** VARIABLES PARTE OBLIGATORIA ********

SRC := ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_strlen.c \
		ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_strlcpy.c \
		ft_strlcat.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strncmp.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memmove.c \
		ft_strnstr.c \
		ft_atoi.c \
		ft_calloc.c \
		ft_strdup.c \
		ft_substr.c \
		ft_itoa.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_split.c \
		ft_striteri.c \
		ft_strmapi.c \
		ft_putnbr_fd.c \
		ft_putstr_fd.c \
		ft_putchar_fd.c \
		ft_putendl_fd.c

OBJ_NAME = $(SRC:%.c=$(OBJDIR)%.o)

# ******** VARIABLES PARTE BONUS ********

SRC_BONUS := ft_lstnew_bonus.c \
			ft_lstadd_front_bonus.c \
			ft_lstsize_bonus.c \
			ft_lstlast_bonus.c \
			ft_lstadd_back_bonus.c \
			ft_lstdelone_bonus.c \
			ft_lstclear_bonus.c \
			ft_lstiter_bonus.c \
			ft_lstmap_bonus.c

OBJ_NAME_BONUS := $(SRC_BONUS:%.c=$(OBJDIR)%.o)

# ******** REGLAS ********

.PHONY: all re clean fclean

all : $(NAME)

$(NAME): $(OBJ_NAME)
	$(SILENT) $(AR) $@ $^

$(OBJDIR)%.o: %.c 
	$(SILENT) $(MKDIR) -p $(OBJDIR)
	$(SILENT) $(CC) -c $(CFLAGS) $< -I $(HEADER) -o $@

# ** reglas para los bonus

bonus: $(OBJ_NAME_BONUS)
	$(SILENT) $(AR) $(NAME) $(OBJ_NAME_BONUS)

# ** CLEAN FCLEAN RE 

clean:
	$(SILENT) $(RM) $(OBJ_NAME)
	$(SILENT) $(RM) $(OBJ_NAME_BONUS)
	$(SILENT) $(RM) -r $(OBJDIR) 

fclean:	clean 
	$(SILENT) $(RM) $(NAME)

re: fclean all
