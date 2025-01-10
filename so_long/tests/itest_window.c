
#include <stdio.h>
#include <assert.h>
#include "../include/so_long.h"
#include "../include/get_map.h"


int mock_fits_screen_size(int width, int height) {
    if (MAX_MONITOR_WIDTH <= (IMAGE_SIZE * width) || MAX_MONITOR_HEIGHT <= (IMAGE_SIZE * height))
        return 0;
    return 1;
}

void test_is_screen_size_valid_ko(t_parsed_map *map)
{
    int width = map->width;
    int height = map->height;
    int response = mock_fits_screen_size(width, height);
    assert(response == 0 && "Screen size is read as ok but it's not");
}

void test_is_screen_size_valid_ok(t_parsed_map *map)
{

    int width = map->width;
    int height = map->height;
    int response = mock_fits_screen_size(width, height);
    assert(response == 1 && "Screen size is read as not ok but it is ok");
}


int main(void)
{

    // fits_screen_size
    // prepare
    // map h.ber ************************************************************************************
    int fd7 = open("maps/invalid/h_screen.ber", O_RDONLY);
    t_file *file7 = ft_file_read_all(fd7);
    assert(fd7 != -1 && "Could not open file h for testing");
    close(fd7);
    if (!file7)
        return (0) ;
    t_parsed_map *map7 = parse_map(file7);
    ft_file_free(&file7);
    int contents7 = validate_map_contents(map7);
    assert(contents7 == 1 && "map h is not valid");
    int playable7 = validate_map_playable(map7);
    assert(playable7 == 1 && "map h reads as non playable but it is playable");

    // map w.ber ************************************************************************************
    int fd8 = open("maps/invalid/w_screen.ber", O_RDONLY);
    t_file *file8 = ft_file_read_all(fd8);
    assert(fd8 != -1 && "Could not open file w for testing");
    close(fd8);
    if (!file8)
        return (0) ;
    t_parsed_map *map8 = parse_map(file8);
    ft_file_free(&file8);
    int contents8 = validate_map_contents(map8);
    assert(contents8 == 1 && "map w is not valid");
    int playable8 = validate_map_playable(map8);
    assert(playable8 == 1 && "map w reads as non playable but it is playable");

    // map validh.ber ************************************************************************************
    int fd9 = open("maps/valid/h_screen.ber", O_RDONLY);
    t_file *file9 = ft_file_read_all(fd9);
    assert(fd9 != -1 && "Could not open file validh for testing");
    close(fd9);
    if (!file9)
        return (0) ;
    t_parsed_map *map9 = parse_map(file9);
    // map9 = map9 + 1000000; // force segfault
    // map9->height = 10;
    ft_file_free(&file9);
    int contents9 = validate_map_contents(map9);
    assert(contents9 == 1 && "map valid is not valid");
    int playable9 = validate_map_playable(map9);
    assert(playable9 == 1 && "map validh reads as non playable but it is playable");

    // test
    test_is_screen_size_valid_ko(map7);
    test_is_screen_size_valid_ko(map8);
    test_is_screen_size_valid_ok(map9);

    // cleanup
    free_parsed_map(map7);
    free_parsed_map(map8);
    free_parsed_map(map9);

    // test init_window
    // prepare
    int width1 = 30;
    int height1 = 20; 
    mlx_t *window1 = init_window(width1, height1, MLX42_TITLE);
    assert(window1 != NULL && "Failed to initialize window");
    close_window(window1);

    int width5 = (MAX_MONITOR_WIDTH / IMAGE_SIZE) -1;
    int height5 = (MAX_MONITOR_HEIGHT / IMAGE_SIZE) -1;
    mlx_t* window5 = init_window(width5, height5, MLX42_TITLE);
    assert(window5 != NULL && "Failed to initialize window");
    close_window(window5);

    // uncomment for exit program at this point
    // int width2 = 1000;
    // int height2 = 500;
    // mlx_t* window2 = init_window(width2, height2, "Window NOT CREATED");
    // assert(window2 == NULL && "Failed to initialize window");
    // close_window(window2);

    // int width3 = 0;
    // int height3 = 768;
    // mlx_t* window3 = init_window(width3, height3, MLX42_TITLE);
    // assert(window3 == NULL && "Failed to initialize window");
    // close_window(window3);

    // int width6 = MAX_MONITOR_WIDTH / IMAGE_SIZE + 1;
    // int height6 = MAX_MONITOR_HEIGHT / IMAGE_SIZE + 1;
    // const char* title6 = "Invalid Screen Size Window";
    // mlx_t* window6 = init_window(width6, height6, title6);
    // assert(window6 == NULL && "Failed to initialize window");
    // close_window(window6);

    return 0;
}