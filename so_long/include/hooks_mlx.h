/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_mlx.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalarco <saalarco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 11:56:36 by saalarco          #+#    #+#             */
/*   Updated: 2025/01/10 17:49:31 by saalarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// game.h
#ifndef HOOKS_MLX_H
# define HOOKS_MLX_H
# include "../MLX42/include/MLX42/MLX42.h"
# include "../libft/include/libft.h"
# include "get_map.h"

typedef struct s_game
{
	mlx_t			*mlx;
	t_parsed_map	*map;
	mlx_image_t		*wall_image;
	mlx_image_t		*nowall_image;
	mlx_image_t		*player_image;
	mlx_image_t		*collectible_image;
	mlx_image_t		*exit_image;
	mlx_texture_t	*wall_texture;
	mlx_texture_t	*nowall_texture;
	mlx_texture_t	*player_texture;
	mlx_texture_t	*collectible_texture;
	mlx_texture_t	*exit_texture;
	int				movements;
	int				p_x;
	int				p_y;
	int				c_left;
}					t_game;

void				end_game(t_game *game);

// Function to update position of player
void				move_player(t_game *game, int dx, int dy);

// Function to disable collectible and print some message
void				collect(t_game *game, int x, int y);

// On movement update map
void				move(t_game *game, int x, int y);

// Function is movement alllowed
int					is_movement_allowed(t_game *game, int x, int y);

#endif
