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

static void test_validate_map_content_ko(void)
{
	// 9
	int fd9 = open("maps/invalid/9.ber", O_RDONLY);
	assert(fd9 != -1 && "Could not open file9 for testing");
	t_file *file9 = ft_file_read_all(fd9);
	close(fd9);
	if (!file9)
		return ;
	t_parsed_map *map9 = parse_map(file9);
	ft_file_free(&file9);
	int response = validate_map_contents(map9);
	assert(response == 0 && "map9 is valid");
	free_parsed_map(map9);

	// 10
	int fd10 = open("maps/invalid/10.ber", O_RDONLY);
	assert(fd10 != -1 && "Could not open file10 for testing");
	t_file *file10 = ft_file_read_all(fd10);
	close(fd10);
	if (!file10)
		return ;
	t_parsed_map *map10 = parse_map(file10);
	ft_file_free(&file10);
	response = validate_map_contents(map10);
	assert(response == 0 && "map10 is valid");
	free_parsed_map(map10);

	// 11
	int fd11 = open("maps/invalid/11.ber", O_RDONLY);
	assert(fd11 != -1 && "Could not open file11 for testing");
	t_file *file11 = ft_file_read_all(fd11);
	close(fd11);
	if (!file11)
		return ;
	t_parsed_map *map11 = parse_map(file11);
	ft_file_free(&file11);
	response = validate_map_contents(map11);
	assert(response == 0 && "map11 is valid");
	free_parsed_map(map11);

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
    free_parsed_map(map0);

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
    free_parsed_map(map1);

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
    free_parsed_map(map2);
}

static void test_validate_map_content_ok(void)
{
	// map exists and has at least one P C and E
    int fd3 = open("maps/valid/3.ber", O_RDONLY);
    assert(fd3 != -1 && "Could not open file for testing");
    t_file *file3 = ft_file_read_all(fd3);
    close(fd3);
    if (!file3)
        return ;
    t_parsed_map *map3 = parse_map(file3);
	ft_file_free(&file3);
	assert(map3 != NULL && "parse_map returned NULL for valid map3");
	assert(map3->cells != NULL && "map3 is null so not assigned");
	assert(map3->height == 5 && "map3 height is not 5");
	int response3 = validate_map_contents(map3);
	assert(map3->num_collectables == 1 && "map3 num_collectables is not 1");
	assert(response3 == 1 && "map3 is not valid");
    assert(map3->collectables != NULL && "collectables are null");
	free_parsed_map(map3);

    // map 4.ber
    int fd4 = open("maps/valid/4.ber", O_RDONLY);
    assert(fd4 != -1 && "Could not open file for testing");
    t_file *file4 = ft_file_read_all(fd4);
    close(fd4);
    if (!file4)
        return ;
    t_parsed_map *map4 = parse_map(file4);
	ft_file_free(&file4);
	assert(map4 != NULL && "parse_map returned NULL for valid map4");
	assert(map4->cells != NULL && "map4 is null so not assigned");
	assert(map4->height == 3 && "map4 height is not 3");
	int response4 = validate_map_contents(map4);
	assert(map4->num_collectables == 1 && "map4 num_collectables is not 1");
	assert(response4 == 1 && "map4 is not valid");
    t_list  *collectables = map4->collectables;
    t_position *position = collectables->content;
    assert(position->x == 9 && "position x being 9 for C is incorrect");
    assert(position->y == 1 && "position y being 1 for C is incorrect");
	free_parsed_map(map4);
}

// TODO: distinguish between CI tests and how-to-use examples, that is refine scope and decouple
int main(void)
{
    test_parse_map_valid();
    test_parse_map_invalid();	
    test_validate_map_content_ko();
	test_validate_map_content_ok();
    return 0;
}