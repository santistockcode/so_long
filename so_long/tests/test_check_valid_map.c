#include "../include/so_long.h"
#include "../include/check_valid_map.h"
#include <assert.h>

static void test_get_map_data_invalid(void)
{
    int fd = open("maps/0.ber", O_RDONLY);
    assert(fd != -1 && "Could not open file for testing");

    t_file *file = ft_file_read_all(fd);
    close(fd);
    if (!file)
            return ;
    
    t_map_data *map = get_map_data(file);
    ft_file_free(&file);
    assert(map == NULL && "returned get_map_data for invalid map");
}

static void test_get_map_data_valid(void)
{
    int fd = open("maps/1.ber", O_RDONLY);
    assert(fd != -1 && "Could not open file for testing");

    t_file *file = ft_file_read_all(fd);
    close(fd);
    if (!file)
        return ;
    
    t_map_data *map = get_map_data(file);
    ft_file_free(&file);
    assert(map != NULL && "get_map_data returned NULL for valid map");
    assert(map->map != NULL && "map is null so not assigned");
    free_map_data(map);
}

// test to check if t_map_data *get_map_data(t_file *file); and int validate_map_data(t_map_data *map_data); works
int main(void)
{
    test_get_map_data_valid();
    test_get_map_data_invalid();


    printf("\x1b[32mAll check_valid_map tests went ok!\n\x1b[0m");
    return 0;
}