#ifndef RENDER_H
#define RENDER_H
# include "../MLX42/include/MLX42/MLX42.h"
#include "game.h"
#include <stdio.h>
#include <stdlib.h>

// Function to initialize the game struct
void initialize_game(t_game *game, mlx_t *mlx, t_parsed_map *map);
// Function to load images and textures to the game struct
// static void load_images_textures(t_game *game);
// Function to put images to window (images I already have in the structure) The structure needs some type of count of instances
// static void render_map(t_game *game);
void free_images_textures(t_game *game);

#endif
