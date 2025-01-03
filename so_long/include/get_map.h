/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalarco <saalarco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 13:48:56 by saalarco          #+#    #+#             */
/*   Updated: 2025/01/02 19:18:40 by saalarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_MAP_H
# define GET_MAP_H
# include <limits.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft/include/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"
# include "common.h"


# define WALL '1'
# define NOWALL '0'
# define PLAYER 'P'
# define EXITMAP 'E'
# define COLLEC 'C'

// map_data.h
typedef struct s_position
{
	unsigned int	x;
	unsigned int	y;
}					t_position;

typedef struct s_parsed_map
{
	int				height;
	int				width;
	char			**cells;
	t_position		player_start;
	t_position		exit_pos;
	t_list			*collectables;
	int				num_collectables;
}					t_parsed_map;

// Alloc t_parsed_map and minimal checks
t_parsed_map		*parse_map(t_file *file);

// validate map contents
int					validate_map_contents(t_parsed_map *map);

// validaate map playable
int					validate_map_playable(t_parsed_map *map);

// free map data
void				free_parsed_map(t_parsed_map *map_data);

// flood fill with linked lists
void				flood_fill_mark(char **map, unsigned int from_y,
						unsigned int from_x);

#endif
