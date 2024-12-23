/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalarco <saalarco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:11:26 by saalarco          #+#    #+#             */
/*   Updated: 2024/12/23 12:36:29 by saalarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../MLX42/include/MLX42/MLX42.h"
# include "../libft/include/libft.h"

# include "../include/check_valid_map.h"


# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <errno.h>
# include <string.h>

# define ERROR_USAGE "Error\nIncorrect extension or number of params"
# define ERROR_OPEN "Error: Failure to open file"
# define ERROR_EMPTY "Error: empty file"
# define ERROR_FETCH "Error: problem fetching map"
# define ERROR_EXTENSION "Error: map extension incorrect"
# define ERROR_MEMORY "Error: malloc failed"
# define ERROR_MEASURE "Error: error measuring map"
# define ERROR_IRREGULAR "Error: map not a rectangle"
# define FALSE		0
# define TRUE		1

int is_extension_correct(char *file);

#endif
