
// game.h
#ifndef GAME_H
#define GAME_H
# include "../MLX42/include/MLX42/MLX42.h"
# include "../libft/include/libft.h"
# include "get_map.h"


typedef struct s_game
{
	mlx_t			*mlx;
	t_parsed_map	*map;
	mlx_image_t *wall_image;
	mlx_image_t *nowall_image;
	mlx_image_t *player_image;
	mlx_image_t *collectible_image;
	mlx_image_t *exit_image;
	mlx_texture_t *wall_texture;
	mlx_texture_t *nowall_texture;
	mlx_texture_t *player_texture;
	mlx_texture_t *collectible_texture;
	mlx_texture_t *exit_texture;
}					t_game;



void move_player(t_game *game, int dx, int dy);

#endif
