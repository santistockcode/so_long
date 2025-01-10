#include "../MLX42/include/MLX42/MLX42.h"
# include "../libft/include/libft.h"
#include "../include/so_long.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static const char	*files[] = {"textures/player.png", "textures/nowall.png",
		"textures/wall.png", "textures/collec.png", "textures/exit.png", NULL};

void	render_map(t_game *game)
{
    int	x;
    int	y;

    y = 0;
    while (y < game->map->height)
    {
        x = 0;
        while (x < game->map->width)
        {
            if (game->map->cells[y][x] == WALL)
                mlx_image_to_window(game->mlx, game->wall_image, x * IMAGE_SIZE,
                    y * IMAGE_SIZE);
            else if (game->map->cells[y][x] == NOWALL)
                mlx_image_to_window(game->mlx, game->nowall_image, x * IMAGE_SIZE,
                    y * IMAGE_SIZE);
            else if (game->map->cells[y][x] == PLAYER)
                mlx_image_to_window(game->mlx, game->player_image, x * IMAGE_SIZE,
                    y * IMAGE_SIZE);
            else if (game->map->cells[y][x] == COLLEC)
                mlx_image_to_window(game->mlx, game->collectible_image, x * IMAGE_SIZE,
                    y * IMAGE_SIZE);
            else if (game->map->cells[y][x] == EXITMAP)
                mlx_image_to_window(game->mlx, game->exit_image, x * IMAGE_SIZE,
                    y * IMAGE_SIZE);
            x++;
        }
        y++;
    }
}

void	mock_load_images(t_game *game)
{
	game->player_image = mlx_texture_to_image(game->mlx, game->player_texture);
	game->nowall_image = mlx_texture_to_image(game->mlx, game->nowall_texture);
	game->wall_image = mlx_texture_to_image(game->mlx, game->wall_texture);
	game->collectible_image = mlx_texture_to_image(game->mlx,
			game->collectible_texture);
	game->exit_image = mlx_texture_to_image(game->mlx, game->exit_texture);
	if (!game->player_image || !game->nowall_image || !game->wall_image
		|| !game->collectible_image || !game->exit_image)
		ft_error(ERROR_IMAGES);
}

void	mock_load_textures(t_game *game)
{
	game->player_texture = mlx_load_png(files[0]);
	game->nowall_texture = mlx_load_png(files[1]);
	game->wall_texture = mlx_load_png(files[2]);
	game->collectible_texture = mlx_load_png(files[3]);
	game->exit_texture = mlx_load_png(files[4]);
	if (!game->player_texture || !game->nowall_texture || !game->wall_texture
		|| !game->collectible_texture || !game->exit_texture)
		ft_error(ERROR_TEXTURE);
}

int	main(void)
{
	t_game *game;
	mlx_t *window9;

	int fd9 = open("maps/valid/18.ber", O_RDONLY);
	t_file *file9 = ft_file_read_all(fd9);
	assert(fd9 != -1 && "Could not open file validh for testing");
	close(fd9);
	if (!file9)
		return (0);
	t_parsed_map *map9 = parse_map(file9);
	ft_file_free(&file9);
	int contents9 = validate_map_contents(map9);
	assert(contents9 == 1 && "map valid is not valid");
	int playable9 = validate_map_playable(map9);
	assert(playable9 == 1
		&& "map validh reads as non playable but it is playable");
	window9 = init_window(map9->width, map9->height, "so_long");

	game = calloc(1, sizeof(t_game));
	game->map = map9;
	game->mlx = window9;
	mock_load_textures(game);
	mock_load_images(game);
	render_map(game);
    mlx_loop(game->mlx);
    mlx_delete_image(game->mlx, game->wall_image);
	mlx_delete_image(game->mlx, game->nowall_image);
	mlx_delete_image(game->mlx, game->player_image);
	mlx_delete_image(game->mlx, game->collectible_image);
	mlx_delete_image(game->mlx, game->exit_image);
	mlx_delete_texture(game->wall_texture);
	mlx_delete_texture(game->nowall_texture);
	mlx_delete_texture(game->player_texture);
	mlx_delete_texture(game->collectible_texture);
	mlx_delete_texture(game->exit_texture);
	free_parsed_map(map9);
	close_window(window9);
	free(game);
}