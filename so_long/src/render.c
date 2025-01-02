// // render.c
// #include "render.h"

// void load_textures(t_game *game) {
//     game->wall_texture = mlx_load_png("textures/wall.png");
//     game->player_texture = mlx_load_png("textures/player.png");
//     game->exit_texture = mlx_load_png("textures/exit.png");
//     game->collectible_texture = mlx_load_png("textures/collectible.png");
//     if (!game->wall_texture || !game->player_texture || !game->exit_texture || !game->collectible_texture) {
//         fprintf(stderr, "Error: Failed to load textures.\n");
//         exit(EXIT_FAILURE);
//     }
// }

// void render_map(t_game *game) {
//     for (int y = 0; y < game->map_height; y++) {
//         for (int x = 0; x < game->map_width; x++) {
//             mlx_texture_t *texture = NULL;
//             char tile = game->map[y][x];
//             if (tile == '1') texture = game->wall_texture;
//             else if (tile == 'P') texture = game->player_texture;
//             else if (tile == 'C') texture = game->collectible_texture;
//             else if (tile == 'E') texture = game->exit_texture;

//             if (texture) {
//                 mlx_image_t *image = mlx_texture_to_image(game->mlx, texture);
//                 mlx_image_to_window(game->mlx, image, x * TILE_SIZE, y * TILE_SIZE);
//                 mlx_delete_image(game->mlx, image); // Clean up after rendering.
//             }
//         }
//     }
// }
