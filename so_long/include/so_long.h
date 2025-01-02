/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalarco <saalarco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 13:48:08 by saalarco          #+#    #+#             */
/*   Updated: 2025/01/02 14:59:13 by saalarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../MLX42/include/MLX42/MLX42.h"
# include "../include/window.h"
# include "../include/get_map.h"
# include "../libft/include/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>

# define ERROR "Error\n"
# define ERROR_ARGUMENT "Argument is not valid for the game"
# define ERROR_USAGE "Incorrect extension or number of params\n"
# define ERROR_OPEN "Failure to open file\n"
# define ERROR_EMPTY "Problem reading the file\n"
# define ERROR_PARSE "Error parsing the map\n"
# define ERROR_EXTENSION "Map extension incorrect\n"
# define ERROR_CONTENTS "Contents of map not valid\n"
# define ERROR_PLAYABLE "Not a playable map under subject rules\n"
# define FALSE 0
# define TRUE 1

t_parsed_map	*argument_valid(int argc, char **argv);

#endif
