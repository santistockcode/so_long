#include "MLX42/MLX42.h"
#include <stdlib.h>
#include <string.h>

// Bytes Per Pixel. Since each pixel is represented as an integer, it will be four bytes for four channels.
#define BPP sizeof(int32_t)

#define WIDTH 512
#define HEIGHT 512

void error_callback(int error, const char* description)
{
    fprintf(stderr, "Error: %s\n", description);
}


void set_pixel_color(mlx_image_t* img, int x, int y, uint32_t color)
{
    if (x < 0 || x >= (int) img->width || y < 0 || y >= (int) img->height)
        return;

    // Calculate the index in the pixel buffer
    int index = (y * img->width + x) * 4;

    // Set the color (assuming RGBA format)
    img->pixels[index + 0] = (color >> 24) & 0xFF; // Red
    img->pixels[index + 1] = (color >> 16) & 0xFF; // Green
    img->pixels[index + 2] = (color >> 8) & 0xFF;  // Blue
    img->pixels[index + 3] = color & 0xFF;         // Alpha
}

int32_t	main(void)
{
    // Init mlx with a canvas size of 256x256 and the ability to resize the window.
    mlx_t* mlx = mlx_init(256, 256, "MLX42", true);
    
    if (!mlx) exit(EXIT_FAILURE);

    // Create a 128x128 image.
    mlx_image_t* img = mlx_new_image(mlx, 128, 128);

    // Set the channels of each pixel in our image to the maximum byte value of 255. 
    // memset(img->pixels, 100, img->width * img->height * BPP);

    for (int y = 0; y < HEIGHT; ++y)
    {
        for (int x = 0; x < WIDTH; ++x)
        {
            // Example: Set to red with full opacity
            uint32_t color = 0x6a818F; // RGBA
            set_pixel_color(img, x, y, color);
        }
    }
    // Draw the image at coordinate (0, 0).
    mlx_image_to_window(mlx, img, 0, 0);

    // Run the main loop and terminate on quit.  
    mlx_loop(mlx);
    mlx_terminate(mlx);

    return (EXIT_SUCCESS);
}
