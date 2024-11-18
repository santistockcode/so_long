#include <stdlib.h>
#include <stdio.h>
#include "MLX42/MLX42.h"

#define WIDTH 800
#define HEIGHT 600

// Function to be called every frame
void frame_update(void* param)
{
    static int frame_count = 0;
    mlx_t* mlx = (mlx_t*)param;

    char title[256];
    snprintf(title, sizeof(title), "MLX42 - Frame: %d", frame_count++);
    mlx_set_window_title(mlx, title);
}

int32_t main(void)
{
    mlx_t* mlx;

    // Initialize MLX
    if (!(mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true)))
    {
        fprintf(stderr, "Failed to initialize MLX\n");
        return (EXIT_FAILURE);
    }

    // Try to load the file
    xpm_t* xpm = mlx_load_xpm42("./textures/test.xpm42");
    if (!xpm)
    {
        fprintf(stderr, "Failed to load XPM file\n");
        mlx_terminate(mlx);
        return (EXIT_FAILURE);
    }

    mlx_image_t* img = mlx_texture_to_image(mlx, &xpm->texture);
    if (!img)
    {
        fprintf(stderr, "Failed to convert texture to image\n");
        mlx_delete_xpm42(xpm);
        mlx_terminate(mlx);
        return (EXIT_FAILURE);
    }

    // Display the image
    if (mlx_image_to_window(mlx, img, 0, 0) < 0)
    {
        fprintf(stderr, "Failed to display image\n");
        mlx_delete_image(mlx, img);
        mlx_delete_xpm42(xpm);
        mlx_terminate(mlx);
        return (EXIT_FAILURE);
    }

    // Set the generic hook
    mlx_loop_hook(mlx, frame_update, mlx);

    // Start MLX loop
    mlx_loop(mlx);

    // Clean up
    mlx_delete_image(mlx, img);
    mlx_delete_xpm42(xpm);
    mlx_terminate(mlx);

    return (EXIT_SUCCESS);
}