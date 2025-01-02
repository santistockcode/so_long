
// game.h
#ifndef GAME_H
#define GAME_H
# include <../MLX42/include/MLX42/MLX42.h>
# include <get_map.h>

typedef struct s_game
{
	mlx_t			*mlx;
	mlx_image_t		*map_image;
	t_parsed_map	*map;
	int				screen_width;
	int				screen_height;
	int				map_width;
	int				map_height;
}					t_game;


void move_player(t_game *game, int dx, int dy);

#endif
