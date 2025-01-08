/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalarco <saalarco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 13:48:08 by saalarco          #+#    #+#             */
/*   Updated: 2025/01/08 13:15:47 by saalarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../MLX42/include/MLX42/MLX42.h"
# include "../libft/include/libft.h"
# include "window.h"
# include "get_map.h"
# include "game.h"
# include "render.h"
# include "common.h"
# include "colors.h"
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>

typedef struct	s_helloworld
{
    mlx_t		*mlx;
}				t_helloworld;

t_parsed_map	*argument_valid(int argc, char **argv);
mlx_t* init_window(int width, int height, const char *title);
void close_window(mlx_t *mlx);

#endif
