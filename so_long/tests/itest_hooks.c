#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../MLX42/include/MLX42/MLX42.h"
# include "../libft/include/libft.h"
#include "../include/so_long.h"


// helper debugging function to print number of key pressed
static void game_key_hook(mlx_key_data_t keydata, void *param) {
    (void)param;
    printf("Key pressed: %d\n", keydata.key);
    return;
}

int main() {
    mlx_t *mlx;
    mlx = init_window(20, 20, "Hello, world!");
    mlx_key_hook(mlx, &game_key_hook, NULL);
    mlx_loop(mlx);
    mlx_terminate(mlx);
    return 0;
}