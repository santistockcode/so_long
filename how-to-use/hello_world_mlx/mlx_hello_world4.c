#include <stdlib.h>
#include <stdio.h>
#include "MLX42/MLX42.h"

#define WIDTH 512
#define HEIGHT 512

void my_keyhook(mlx_key_data_t keydata, void* param)
{
    (void)param;
    if (keydata.key == MLX_KEY_J && keydata.action == MLX_PRESS)
        puts("Hello");
    if (keydata.key == MLX_KEY_K && keydata.action == MLX_RELEASE)
        puts("World");
    if (keydata.key == MLX_KEY_L && keydata.action == MLX_REPEAT)
        puts("!");
}

int32_t main(void)
{
    mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "My Window", true);
    mlx_key_hook(mlx, my_keyhook, NULL);
    mlx_loop(mlx);
    return 0;
}