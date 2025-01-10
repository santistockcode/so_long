/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalarco <saalarco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 13:48:08 by saalarco          #+#    #+#             */
/*   Updated: 2025/01/10 16:47:42 by saalarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../MLX42/include/MLX42/MLX42.h"
# include "../libft/include/libft.h"
# include "colors.h"
# include "common.h"
# include "display_mlx.h"
# include "get_map.h"
# include "hooks_mlx.h"
# include "window_mlx.h"
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>

typedef struct s_helloworld
{
	mlx_t		*mlx;
}				t_helloworld;

t_parsed_map	*argument_valid(int argc, char **argv);

mlx_t			*init_window(int width, int height, const char *title);
void			close_window(mlx_t *mlx);

void			display_graphics(t_game *game, mlx_t *mlx, t_parsed_map *map);

// function to manage key pressed and update graphics based on logic
void			key_handle(mlx_key_data_t keydata, void *param);
// function to manage window exit pressing x
void			window_exit_handle(void *ptr);
// function to print movements on terminal
void			print_movements_handle(void *ptr);

#endif
