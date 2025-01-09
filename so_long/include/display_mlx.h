#ifndef RENDER_H
#define RENDER_H
# include "../MLX42/include/MLX42/MLX42.h"
#include "game.h"
#include <stdio.h>
#include <stdlib.h>

# define P_PATH "textures/player.png"
# define W_PATH "textures/wall.png"
# define NW_PATH "textures/nowall.png"
# define C_PATH "textures/collec.png"
# define E_PATH "textures/exit.png"


// Functions to load images and textures to the game struct
int	load_textures(t_game *game);
int	load_images(t_game *game);

// Function to put images to window (images I already have in the structure) The structure needs some type of count of instances
void	render_map(t_game *game);

// Function to free the textures and images
void free_textures(t_game *game);
void free_images_textures(t_game *game);

#endif
