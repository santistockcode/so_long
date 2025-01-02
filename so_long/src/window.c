#include "../../include/window.h"

mlx_t* init_window(int width, int height, const char *title) {
    mlx_t *mlx = mlx_init(width, height, title, true);
    if (!mlx) {
        //fprintf(stderr, "Error: Failed to initialize MLX42.\n");
        exit(1);
    }
    return mlx;
}

void close_window(mlx_t *mlx) {
    if (mlx) mlx_terminate(mlx);
}
