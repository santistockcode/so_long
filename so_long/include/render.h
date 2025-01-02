#ifndef RENDER_H
#define RENDER_H
# include <../MLX42/include/MLX42/MLX42.h>
#include "game.h"
#include <stdio.h>
#include <stdlib.h>

void load_textures(t_game *game);
void render_map(t_game *game);
// differenciate between render initial map and update map

#endif
