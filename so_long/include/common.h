/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalarco <saalarco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 11:53:36 by saalarco          #+#    #+#             */
/*   Updated: 2025/01/10 16:47:16 by saalarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H

# include "../MLX42/include/MLX42/MLX42.h"
# include "../libft/include/libft.h"
# include "hooks_mlx.h"

# define ERROR "Error\n"
# define ERROR_ARGUMENT "Argument is not valid for the game"
# define ERROR_USAGE "Incorrect extension or number of params\n"
# define ERROR_OPEN "Failure to open file\n"
# define ERROR_EMPTY "Problem reading the file\n"
# define ERROR_PARSE "Problem parsing the map\n"
# define ERROR_EXTENSION "Map extension incorrect\n"
# define ERROR_CONTENTS "Contents of map not valid\n"
# define ERROR_PLAYABLE "Not a playable map under subject rules\n"
# define ERROR_SCREEN "Map does not fit screen size\n"
# define ERROR_MLX_WINDOW "Failed to initialize window\n"
# define ERROR_TEXTURE "Failed to load textures\n"
# define ERROR_IMAGES "Failed to load images\n"
# define ERROR_MALLOC "Failed to allocate memory\n"
# define ERROR_UNKNOWN "Error unknown\n"
# define FALSE 0
# define TRUE 1
# define MAX_MONITOR_WIDTH 3840
# define MAX_MONITOR_HEIGHT 2160
# define IMAGE_SIZE 64
# define MLX42_TITLE "So Long"

void	ft_error(char *msg);

#endif
