/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalarco <saalarco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:11:26 by saalarco          #+#    #+#             */
/*   Updated: 2024/11/28 18:12:22 by saalarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H


# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include "get_next_line/get_next_line.h"
# include "MLX42/include/MLX42/MLX42.h"

# include "libft/libft.h"
# include "get_next_line/get_next_line.h"

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

# define ERROR_USAGE "Error: Incorrect extension or number of params"
# define ERROR_OPEN "Error: Failure to open file"
# define ERROR_EMPTY "Error: empty file"
# define ERROR_FETCH "Error: problem fetching map"
# define ERROR_EXTENSION "Error: map extension incorrect"
# define ERROR_MEMORY "Error: malloc failed"
# define FALSE		0
# define TRUE		1

typedef struct {
    int height;
    int width;
    char **map;
} Map;

int is_extension_correct(char *file);
void print_error(const char *error_message);

#endif
