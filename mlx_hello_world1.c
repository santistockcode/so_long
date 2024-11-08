#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "MLX42/MLX42.h"

#define WIDTH 5120
#define HEIGHT 2880

static void error(void)
{
	puts(mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

// static void check_file(const char* filepath)
// {
//     FILE* file = fopen(filepath, "r");
//     if (!file)
//     {
//         perror("Failed to open file");
//         exit(EXIT_FAILURE);
//     }

//     printf("File content:\n");
//     char ch;
//     while ((ch = fgetc(file)) != EOF)
//     {
//         putchar(ch);
//     }
//     fclose(file);
//     printf("\n");
// }

int32_t main(void)
{
    //const char* filepath = "./textures/test.xpm42";
    //check_file(filepath);

    mlx_t* mlx;

    // Initialize MLX
    if (!(mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true)))
    {
        error();
    }
    // Try to load the file
	xpm_t* xpm = mlx_load_xpm42("./textures/test0.xpm42");
	if (!xpm)
		error();

    mlx_image_t* img = mlx_texture_to_image(mlx, &xpm->texture);
	if (!img)
		error();

	

	// Display the image
	if (mlx_image_to_window(mlx, img, 0, 0) < 0)
		error();

    // Start MLX loop
    mlx_loop(mlx);

    // Clean up
    mlx_delete_image(mlx, img);
    mlx_delete_xpm42(xpm);
    mlx_terminate(mlx);

    return (EXIT_SUCCESS);
}