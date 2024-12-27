#include "../include/so_long.h"
#include "../include/get_map.h"
#include <assert.h>

static void test_parse_map_invalid(void)
{
    // empty
    int fd0 = open("maps/invalid/0.ber", O_RDONLY);
    assert(fd0 != -1 && "Could not open file for testing");
    t_file *file0 = ft_file_read_all(fd0);
    close(fd0);
    if (!file0)
            return ;
    t_parsed_map *map0 = parse_map(file0);
    ft_file_free(&file0);
    assert(map0 == NULL && "returned parse_map for invalid map");

    // not a rectangle
    int fd1 = open("maps/invalid/1.ber", O_RDONLY);
    assert(fd1 != -1 && "Could not open file for testing");
    t_file *file1 = ft_file_read_all(fd1);
    close(fd1);
    if (!file1)
            return ;
    t_parsed_map *map1= parse_map(file1);
    ft_file_free(&file1);
    assert(map1 == NULL && "returned parse_map for invalid map");  

    // rectangle but \n at the beggining end or middle
    int fd2 = open("maps/invalid/2.ber", O_RDONLY);
    assert(fd2 != -1 && "Could not open file2 for testing");
    t_file *file2 = ft_file_read_all(fd2);
    close(fd2);
    if (!file2)
            return ;
    t_parsed_map *map2 = parse_map(file2);
    ft_file_free(&file2);
    assert(map2 == NULL && "returned parse_map for invalid map");

    // 3
    int fd3 = open("maps/invalid/3.ber", O_RDONLY);
    assert(fd3 != -1 && "Could not open file3 for testing");
    t_file *file3 = ft_file_read_all(fd3);
    close(fd3);
    if (!file3)
            return ;
    t_parsed_map *map3 = parse_map(file3);
    ft_file_free(&file3);
    assert(map3 == NULL && "returned parse_map for invalid map");

    // 4
    int fd4 = open("maps/invalid/4.ber", O_RDONLY);
    assert(fd4 != -1 && "Could not open file4 for testing");
    t_file *file4 = ft_file_read_all(fd4);
    close(fd4);
    if (!file4)
            return ;
    t_parsed_map *map4 = parse_map(file4);
    ft_file_free(&file4);
    assert(map4 == NULL && "returned parse_map for invalid map");

    // 5
    int fd5 = open("maps/invalid/5.ber", O_RDONLY);
    assert(fd5 != -1 && "Could not open file5 for testing");
    t_file *file5 = ft_file_read_all(fd5);
    close(fd5);
    if (!file5)
            return ;
    t_parsed_map *map5 = parse_map(file5);
    ft_file_free(&file5);
    assert(map5 == NULL && "returned parse_map for invalid map");

    // 6
    int fd6 = open("maps/invalid/6.ber", O_RDONLY);
    assert(fd6 != -1 && "Could not open file6 for testing");
    t_file *file6 = ft_file_read_all(fd6);
    close(fd6);
    if (!file6)
            return ;
    t_parsed_map *map6 = parse_map(file6);
    ft_file_free(&file6);
    assert(map6 == NULL && "returned parse_map for invalid map");

    // 7
    int fd7 = open("maps/invalid/7.ber", O_RDONLY);
    assert(fd7 != -1 && "Could not open file7 for testing");
    t_file *file7 = ft_file_read_all(fd7);
    close(fd7);
    if (!file7)
            return ;
    t_parsed_map *map7 = parse_map(file7);
    ft_file_free(&file7);
    assert(map7 == NULL && "returned parse_map for invalid map");

    // 8
    int fd8 = open("maps/invalid/8.ber", O_RDONLY);
    assert(fd8 != -1 && "Could not open file8 for testing");
    t_file *file8 = ft_file_read_all(fd8);
    close(fd8);
    if (!file8)
            return ;
    t_parsed_map *map8 = parse_map(file8);
    ft_file_free(&file8);
    assert(map8 == NULL && "returned parse_map for invalid map");

}

static void test_parse_map_valid(void)
{
    // map exists 
    int fd0 = open("maps/valid/0.ber", O_RDONLY);
    assert(fd0 != -1 && "Could not open file for testing");
    t_file *file0 = ft_file_read_all(fd0);
    close(fd0);
    if (!file0)
        return ;
    t_parsed_map *map0 = parse_map(file0);
    ft_file_free(&file0);
    assert(map0 != NULL && "parse_map returned NULL for valid map0");
    assert(map0->cells != NULL && "map0 is null so not assigned");
    free_map_data_no_collectables(map0);

    // map exists and has a /n at the end height is 5
    int fd1 = open("maps/valid/1.ber", O_RDONLY);
    assert(fd1 != -1 && "Could not open file for testing");
    t_file *file1 = ft_file_read_all(fd1);
    close(fd1);
    if (!file1)
        return ;
    t_parsed_map *map1 = parse_map(file1);
    ft_file_free(&file1);
    assert(map1 != NULL && "parse_map returned NULL for valid map1");
    assert(map1->cells != NULL && "map1 is null so not assigned");
    assert(map1->height == 7 && "map1 height is not 7");
    free_map_data_no_collectables(map1);

    // map exists and end in EOF height is 5
    int fd2 = open("maps/valid/2.ber", O_RDONLY);
    assert(fd2 != -1 && "Could not open file for testing");
    t_file *file2 = ft_file_read_all(fd2);
    close(fd2);
    if (!file2)
        return ;
    t_parsed_map *map2 = parse_map(file2);
    ft_file_free(&file2);
    assert(map2 != NULL && "parse_map returned NULL for valid map2");
    assert(map2->cells != NULL && "map2 is null so not assigned");
    assert(map2->height == 5 && "map2 height is not 5");
    free_map_data_no_collectables(map2);

    // map exists and has at least one collectable

}

// test to check if t_map_data *parse_map(t_file *file); and int validate_map_data(t_map_data *map_data); works
int main(void)
{
    test_parse_map_valid();
    test_parse_map_invalid();

    printf("\x1b[32mAll check_valid_map tests went ok!\n\x1b[0m");
    return 0;
}