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

	// 10
	int fd10 = open("maps/invalid/10.ber", O_RDONLY);
	assert(fd10 != -1 && "Could not open file10 for testing");
	t_file *file10 = ft_file_read_all(fd10);
	close(fd10);
	if (!file10)
		return ;
	t_parsed_map *map10 = parse_map(file10);
	ft_file_free(&file10);
	int response10 = validate_map_contents(map10);
	assert(response10 == 0 && "map10 is valid");
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
	int response11 = validate_map_contents(map11);
	assert(response11 == 0 && "map11 is valid");
	free_parsed_map(map11);

        // map 15.ber ************************************************************************************
    int fd15 = open("maps/invalid/15.ber", O_RDONLY);
    t_file *file15 = ft_file_read_all(fd15);
    close(fd15);
    if (!file15)
        return ;
    t_parsed_map *map15 = parse_map(file15);
    ft_file_free(&file15);
    int contents15 = validate_map_contents(map15);
    assert(contents15 == 0 && "map15 is read as valid");
    free_parsed_map(map15);
    // map 16.ber ************************************************************************************
    int fd16 = open("maps/invalid/16.ber", O_RDONLY);
    t_file *file16 = ft_file_read_all(fd16);
    close(fd16);
    if (!file16)
        return ;
    t_parsed_map *map16 = parse_map(file16);
    ft_file_free(&file16);
    int contents16 = validate_map_contents(map16);
    assert(contents16 == 0 && "map16 is read as valid but is not");
    free_parsed_map(map16);
    // map 17.ber ************************************************************************************
    int fd17 = open("maps/invalid/17.ber", O_RDONLY);
    t_file *file17 = ft_file_read_all(fd17);
    close(fd17);
    if (!file17)
        return ;
    t_parsed_map *map17 = parse_map(file17);
    ft_file_free(&file17);
    int contents17 = validate_map_contents(map17);
    assert(contents17 == 0 && "map17 is not valid but is read as valid");
    free_parsed_map(map17);
    // map 18.ber ************************************************************************************
    int fd18 = open("maps/invalid/18.ber", O_RDONLY);
    t_file *file18 = ft_file_read_all(fd18);
    close(fd18);
    if (!file18)
        return ;
    t_parsed_map *map18 = parse_map(file18);
    ft_file_free(&file18);
    int contents18 = validate_map_contents(map18);
    assert(contents18 == 0 && "map18 is not valid");
    free_parsed_map(map18);
    // map 19.ber ************************************************************************************
    int fd19 = open("maps/invalid/19.ber", O_RDONLY);
    t_file *file19 = ft_file_read_all(fd19);
    close(fd19);
    if (!file19)
        return ;
    t_parsed_map *map19 = parse_map(file19);
    ft_file_free(&file19);
    int contents19 = validate_map_contents(map19);
    assert(contents19 == 0 && "map19 is not valid");
    free_parsed_map(map19);
    // map 20.ber ************************************************************************************
    int fd20 = open("maps/invalid/20.ber", O_RDONLY);
    t_file *file20 = ft_file_read_all(fd20);
    close(fd20);
    if (!file20)
        return ;
    t_parsed_map *map20 = parse_map(file20);
    ft_file_free(&file20);
    int contents20 = validate_map_contents(map20);
    assert(contents20 == 0 && "map20 is not valid");
    free_parsed_map(map20);
    // map 21.ber ************************************************************************************
    int fd21 = open("maps/invalid/21.ber", O_RDONLY);
    t_file *file21 = ft_file_read_all(fd21);
    close(fd21);
    if (!file21)
        return ;
    t_parsed_map *map21 = parse_map(file21);
    ft_file_free(&file21);
    int contents21 = validate_map_contents(map21);
    assert(contents21 == 0 && "map21 is not valid");
    free_parsed_map(map21);
    // map 22.ber ************************************************************************************
    int fd22 = open("maps/invalid/22.ber", O_RDONLY);
    t_file *file22 = ft_file_read_all(fd22);
    close(fd22);
    if (!file22)
        return ;
    t_parsed_map *map22 = parse_map(file22);
    ft_file_free(&file22);
    int contents22 = validate_map_contents(map22);
    assert(contents22 == 0 && "map22 is not valid");
    free_parsed_map(map22);
    // map 23.ber ************************************************************************************
    int fd23 = open("maps/invalid/23.ber", O_RDONLY);
    t_file *file23 = ft_file_read_all(fd23);
    close(fd23);
    if (!file23)
        return ;
    t_parsed_map *map23 = parse_map(file23);
    ft_file_free(&file23);
    int contents23 = validate_map_contents(map23);
    assert(contents23 == 0 && "map23 is not valid");
    free_parsed_map(map23);
    // map 24.ber ************************************************************************************
    int fd24 = open("maps/invalid/24.ber", O_RDONLY);
    t_file *file24 = ft_file_read_all(fd24);
    close(fd24);
    if (!file24)
        return ;
    t_parsed_map *map24 = parse_map(file24);
    ft_file_free(&file24);
    int contents24 = validate_map_contents(map24);
    assert(contents24 == 0 && "map24 is not valid");
    free_parsed_map(map24);
    // map 25.ber ************************************************************************************
    int fd25 = open("maps/invalid/25.ber", O_RDONLY);
    t_file *file25 = ft_file_read_all(fd25);
    close(fd25);
    if (!file25)
        return ;
    t_parsed_map *map25 = parse_map(file25);
    ft_file_free(&file25);
    int contents25 = validate_map_contents(map25);
    assert(contents25 == 0 && "map25 is not valid");
    free_parsed_map(map25);
    // map 28.ber ************************************************************************************
    int fd28 = open("maps/invalid/28.ber", O_RDONLY);
    t_file *file28 = ft_file_read_all(fd28);
    close(fd28);
    if (!file28)
        return ;
    t_parsed_map *map28 = parse_map(file28);
    ft_file_free(&file28);
    int contents28 = validate_map_contents(map28);
    assert(contents28 == 0 && "map28 is not valid");
    free_parsed_map(map28);
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

void aux_flood_fill_mark(char **map, unsigned int from_x, unsigned int from_y)
{
    if((map[from_x][from_y] == WALL ) || (map[from_x][from_y] & 0x80) != 0)
        return;
    
    if(map[from_x][from_y] != NOWALL && map[from_x][from_y] != PLAYER && map[from_x][from_y] != EXITMAP && map[from_x][from_y] != COLLEC)
        return;
    
    map[from_x][from_y] |= 0x80;

    aux_flood_fill_mark(map, from_x + 1, from_y);
    aux_flood_fill_mark(map, from_x - 1, from_y);
    aux_flood_fill_mark(map, from_x, from_y + 1); 
    aux_flood_fill_mark(map, from_x, from_y - 1);

   return;
}

void aux_flood_fill_unmark(char **map, unsigned int from_x, unsigned int from_y)
{
    if((map[from_x][from_y] == WALL ) || (map[from_x][from_y] & 0x80) == 0)
        return;
    
    map[from_x][from_y] &= 0x7F;

    aux_flood_fill_unmark(map, from_x + 1, from_y);
    aux_flood_fill_unmark(map, from_x - 1, from_y);
    aux_flood_fill_unmark(map, from_x, from_y + 1); 
    aux_flood_fill_unmark(map, from_x, from_y - 1);

   return;
}

static void test_validate_map_playable_ok()
{
    // map 5.ber ************************************************************************************
    int fd5 = open("maps/valid/5.ber", O_RDONLY);
    assert(fd5 != -1 && "Could not open file 5 for testing");
    t_file *file5 = ft_file_read_all(fd5);
    close(fd5);
    if (!file5)
        return ;
    t_parsed_map *map5 = parse_map(file5);
    ft_file_free(&file5);
    assert(map5 != NULL && "parse_map returned NULL for valid map5");
    assert(map5->cells != NULL && "map5 cells are null, map not assigned");
    assert(map5->height == 3 && "map5 height is not 3");
    
    int response5 = validate_map_contents(map5);
    assert(map5->num_collectables == 1 && "map5 num_collectables is not 1");
    assert(response5 == 1 && "map5 is not valid");
    
    t_list  *collectables5 = map5->collectables;
    t_position *position5 = collectables5->content;
    assert(position5->x == 9 && "position x being 9 for C is incorrect");
    assert(position5->y == 1 && "position y being 1 for C is incorrect");
    assert(map5->exit_pos.x == 8 && "exit_pos.x is incorrect");
    assert(map5->exit_pos.y == 1 && "exit_pos.y is incorrect");
    assert(map5->player_start.x == 7 && "player_start.x is incorrect");
    assert(map5->player_start.y == 1 && "player_start.y is incorrect");

    // Test flood fill marking
    aux_flood_fill_mark(map5->cells, map5->player_start.y, map5->player_start.x);
    
    // Test that reachable empty spaces are marked
    assert(((map5->cells[1][4] & 0x80) != 0) && "empty pos not marked although reachable");
    assert(((map5->cells[1][8] & 0x80) != 0) && "exit_pos not marked although reachable");
    assert(((map5->cells[1][9] & 0x80) != 0) && "collectable position not marked");
    
    // Test that walls remain unmarked
    assert(((map5->cells[1][0] & 0x80) == 0) && "wall should not be marked");

    // Test unmarking
    aux_flood_fill_unmark(map5->cells, map5->player_start.y, map5->player_start.x);
    
    // Test that all marked positions are cleaned
    assert(((map5->cells[1][4] & 0x80) == 0) && "empty pos still marked although cleaned");
    assert(((map5->cells[1][8] & 0x80) == 0) && "exit_pos still marked although cleaned");
    assert(((map5->cells[1][9] & 0x80) == 0) && "collectable position still marked");

    // Ensure walls remain unmarked
    assert(((map5->cells[1][0] & 0x80) == 0) && "wall marked during cleaning");

    int playable5 = validate_map_playable(map5);
    assert(playable5 == 1 && "map5 reads as non playable but it is playable");

    free_parsed_map(map5);

    // map 6.ber ************************************************************************************
    // Open the map file
    int fd6 = open("maps/valid/6.ber", O_RDONLY);
    assert(fd6 != -1 && "Could not open file 6.ber for testing");
    
    // Read the map file
    t_file *file6 = ft_file_read_all(fd6);
    close(fd6);
    if (!file6)
        return;

    // Parse the map
    t_parsed_map *map6 = parse_map(file6);
    ft_file_free(&file6);
    assert(map6 != NULL && "parse_map returned NULL for valid map6");
    assert(map6->cells != NULL && "map6 cells are null, map not assigned");

    int response6 = validate_map_contents(map6);
    assert(map6->num_collectables != 0 && "map6 num_collectables is 0");
    assert(response6 == 1 && "map6 is not valid");

    // Perform flood-fill marking
    aux_flood_fill_mark(map6->cells, map6->player_start.y, map6->player_start.x);

    // Ensure the player position is marked
    assert(((map6->cells[map6->player_start.y][map6->player_start.x] & 0x80) != 0) && 
           "player position not marked during flood-fill");

    // Ensure the exit position is marked
    assert(((map6->cells[map6->exit_pos.y][map6->exit_pos.x] & 0x80) != 0) && 
           "exit position not marked during flood-fill");

    // Ensure walls remain unmarked (using position 0,0 which is always a wall)
    assert(((map6->cells[0][0] & 0x80) == 0) && 
           "wall at position (0,0) should not be marked during flood-fill");

    // Perform flood-fill unmarking
    aux_flood_fill_unmark(map6->cells, map6->player_start.y, map6->player_start.x);

    // Ensure the player position is unmarked
    assert(((map6->cells[map6->player_start.y][map6->player_start.x] & 0x80) == 0) && 
           "player position still marked after unmarking");

    // Ensure the exit position is unmarked
    assert(((map6->cells[map6->exit_pos.y][map6->exit_pos.x] & 0x80) == 0) && 
           "exit position still marked after unmarking");

    // Ensure walls remain unmarked (using position 0,0 which is always a wall)
    assert(((map6->cells[0][0] & 0x80) == 0) && 
           "wall at position (0,0) marked during unmarking");
    
    int playable6 = validate_map_playable(map6);
    assert(playable6 == 1 && "map6 reads as non playable but it is playable");

    // Free parsed map resources
    free_parsed_map(map6);

    // map 7.ber ************************************************************************************
    int fd7 = open("maps/valid/7.ber", O_RDONLY);
    t_file *file7 = ft_file_read_all(fd7);
    assert(fd7 != -1 && "Could not open file 7 for testing");
    close(fd7);
    if (!file7)
        return ;
    t_parsed_map *map7 = parse_map(file7);
    ft_file_free(&file7);
    int contents7 = validate_map_contents(map7);
    assert(contents7 == 1 && "map7 is not valid");
    int playable7 = validate_map_playable(map7);
    assert(playable7 == 1 && "map7 reads as non playable but it is playable");
    free_parsed_map(map7);

    // map 8.ber ************************************************************************************
    int fd8 = open("maps/valid/8.ber", O_RDONLY);
    t_file *file8 = ft_file_read_all(fd8);
    assert(fd8 != -1 && "Could not open file 8.ber for testing");
    close(fd8);
    if (!file8)
        return ;
    t_parsed_map *map8 = parse_map(file8);
    ft_file_free(&file8);
    assert(map8 != NULL && "parse_map returned NULL for valid map8");
    assert(map8->cells != NULL && "map8 cells are null, map not assigned");
    int response8 = validate_map_contents(map8);
    assert(map8->num_collectables != 0 && "map8 num_collectables is 0");
    assert(response8 == 1 && "map8 is not valid");
    int playable8 = validate_map_playable(map8);
    assert(playable8 == 1 && "map8 reads as non playable but it is playable");
    free_parsed_map(map8);

    // map 9.ber ************************************************************************************
    int fd9 = open("maps/valid/9.ber", O_RDONLY);
    t_file *file9 = ft_file_read_all(fd9);
    assert(fd9 != -1 && "Could not open file 9.ber for testing");
    close(fd9);
    if (!file9)
        return ;
    t_parsed_map *map9 = parse_map(file9);
    ft_file_free(&file9);
    assert(map9 != NULL && "parse_map returned NULL for valid map9");
    assert(map9->cells != NULL && "map9 cells are null, map not assigned");
    int response9 = validate_map_contents(map9);
    assert(response9 == 0 && "map9 is not valid");
    free_parsed_map(map9);

    // map 10.ber ************************************************************************************
    int fd10 = open("maps/valid/10.ber", O_RDONLY);
    t_file *file10 = ft_file_read_all(fd10);
    assert(fd10 != -1 && "Could not open file 10.ber for testing");
    close(fd10);
    if (!file10)
        return ;
    t_parsed_map *map10 = parse_map(file10);
    ft_file_free(&file10);
    assert(map10 != NULL && "parse_map returned NULL for valid map10");
    assert(map10->cells != NULL && "map10 cells are null, map not assigned");
    int response10 = validate_map_contents(map10);
    assert(map10->num_collectables != 0 && "map10 num_collectables is 0");
    assert(response10 == 1 && "map10 is not valid");
    int playable10 = validate_map_playable(map10);
    assert(playable10 == 1 && "map10 reads as non playable but it is playable");
    free_parsed_map(map10);

    // map 11.ber ************************************************************************************
    int fd11 = open("maps/valid/11.ber", O_RDONLY);
    t_file *file11 = ft_file_read_all(fd11);
    assert(fd11 != -1 && "Could not open file 11.ber for testing");
    close(fd11);
    if (!file11)
        return ;
    t_parsed_map *map11 = parse_map(file11);
    ft_file_free(&file11);
    assert(map11 != NULL && "parse_map returned NULL for valid map11");
    assert(map11->cells != NULL && "map11 cells are null, map not assigned");
    int response11 = validate_map_contents(map11);
    assert(map11->num_collectables != 0 && "map11 num_collectables is 0");
    assert(response11 == 1 && "map11 is not valid");
    int playable11 = validate_map_playable(map11);
    assert(playable11 == 1 && "map11 reads as non playable but it is playable");
    free_parsed_map(map11);

    // map 12.ber ************************************************************************************
    int fd12 = open("maps/valid/12.ber", O_RDONLY);
    t_file *file12 = ft_file_read_all(fd12);
    assert(fd12 != -1 && "Could not open file 12.ber for testing");
    close(fd12);
    if (!file12)
        return ;
    t_parsed_map *map12 = parse_map(file12);
    ft_file_free(&file12);
    assert(map12 != NULL && "parse_map returned NULL for valid map12");
    assert(map12->cells != NULL && "map12 cells are null, map not assigned");
    int response12 = validate_map_contents(map12);
    assert(map12->num_collectables != 0 && "map12 num_collectables is 0");
    assert(response12 == 1 && "map12 is not valid");
    int playable12 = validate_map_playable(map12);
    assert(playable12 == 1 && "map12 reads as non playable but it is playable");
    free_parsed_map(map12);

    // map 13.ber ************************************************************************************
    int fd13 = open("maps/valid/13.ber", O_RDONLY);
    t_file *file13 = ft_file_read_all(fd13);
    assert(fd13 != -1 && "Could not open file 13.ber for testing");
    close(fd13);
    if (!file13)
        return ;
    t_parsed_map *map13 = parse_map(file13);
    ft_file_free(&file13);
    assert(map13 != NULL && "parse_map returned NULL for valid map13");
    assert(map13->cells != NULL && "map13 cells are null, map not assigned");
    int response13 = validate_map_contents(map13);
    assert(map13->num_collectables != 0 && "map13 num_collectables is 0");
    assert(response13 == 1 && "map13 is not valid");
    int playable13 = validate_map_playable(map13);
    assert(playable13 == 1 && "map13 reads as non playable but it is playable");
    free_parsed_map(map13);

    // map 14.ber ************************************************************************************
    int fd14 = open("maps/valid/14.ber", O_RDONLY);
    t_file *file14 = ft_file_read_all(fd14);
    assert(fd14 != -1 && "Could not open file 14.ber for testing");
    close(fd14);
    if (!file14)
        return ;
    t_parsed_map *map14 = parse_map(file14);
    ft_file_free(&file14);
    assert(map14 != NULL && "parse_map returned NULL for valid map14");
    assert(map14->cells != NULL && "map14 cells are null, map not assigned");
    int response14 = validate_map_contents(map14);
    assert(map14->num_collectables != 0 && "map14 num_collectables is 0");
    assert(response14 == 1 && "map14 is not valid");
    int playable14 = validate_map_playable(map14);
    assert(playable14 == 1 && "map14 reads as non playable but it is playable");
    free_parsed_map(map14);

    // 42 lines file -> longer than that it doesn't pass fsanitize
    // map 15.ber ************************************************************************************
    int fd15 = open("maps/valid/15.ber", O_RDONLY);
    t_file *file15 = ft_file_read_all(fd15);
    assert(fd15 != -1 && "Could not open file 15.ber for testing");
    close(fd15);
    if (!file15)
        return ;
    t_parsed_map *map15 = parse_map(file15);
    ft_file_free(&file15);
    assert(map15 != NULL && "parse_map returned NULL for valid map15");
    int contents15 = validate_map_contents(map15);
    assert(contents15 == 1 && "map15 is not valid");
    int playable15 = validate_map_playable(map15);
    assert(playable15 == 1 && "map15 reads as non playable but it is playable");
    free_parsed_map(map15);

    // map 16.ber ************************************************************************************
    int fd16 = open("maps/valid/16.ber", O_RDONLY);
    t_file *file16 = ft_file_read_all(fd16);
    assert(fd16 != -1 && "Could not open file 16.ber for testing");
    close(fd16);
    if (!file16)
        return ;
    t_parsed_map *map16 = parse_map(file16);
    ft_file_free(&file16);
    assert(map16 != NULL && "parse_map returned NULL for valid map16");
    assert(map16->cells != NULL && "map16 cells are null, map not assigned");
    int response16 = validate_map_contents(map16);
    assert(map16->num_collectables != 0 && "map16 num_collectables is 0");
    assert(response16 == 1 && "map16 is not valid");
    int playable16 = validate_map_playable(map16);
    assert(playable16 == 1 && "map16 reads as non playable but it is playable");
    free_parsed_map(map16);

    // map 17.ber ************************************************************************************
    int fd17 = open("maps/valid/17.ber", O_RDONLY);
    t_file *file17 = ft_file_read_all(fd17);
    assert(fd17 != -1 && "Could not open file 17.ber for testing");
    close(fd17);
    if (!file17)
        return ;
    t_parsed_map *map17 = parse_map(file17);
    ft_file_free(&file17);
    assert(map17 != NULL && "parse_map returned NULL for valid map17");
    assert(map17->cells != NULL && "map17 cells are null, map not assigned");
    int response17 = validate_map_contents(map17);
    assert(map17->num_collectables != 0 && "map17 num_collectables is 0");
    assert(response17 == 1 && "map17 is not valid");
    int playable17 = validate_map_playable(map17);
    assert(playable17 == 1 && "map17 reads as non playable but it is playable");
    free_parsed_map(map17);

    // map 18.ber ************************************************************************************
    int fd18 = open("maps/valid/18.ber", O_RDONLY);
    t_file *file18 = ft_file_read_all(fd18);
    assert(fd18 != -1 && "Could not open file 18.ber for testing");
    close(fd18);
    if (!file18)
        return ;
    t_parsed_map *map18 = parse_map(file18);
    ft_file_free(&file18);
    assert(map18 != NULL && "parse_map returned NULL for valid map18");
    assert(map18->cells != NULL && "map18 cells are null, map not assigned");
    int response18 = validate_map_contents(map18);
    assert(map18->num_collectables != 0 && "map18 num_collectables is 0");
    assert(response18 == 1 && "map18 is not valid");
    int playable18 = validate_map_playable(map18);
    assert(playable18 == 1 && "map18 reads as non playable but it is playable");
    free_parsed_map(map18);

    // map 19.ber ************************************************************************************
    int fd19 = open("maps/valid/19.ber", O_RDONLY);
    t_file *file19 = ft_file_read_all(fd19);
    assert(fd19 != -1 && "Could not open file 19.ber for testing");
    close(fd19);
    if (!file19)
        return ;
    t_parsed_map *map19 = parse_map(file19);
    ft_file_free(&file19);
    assert(map19 != NULL && "parse_map returned NULL for valid map19");
    assert(map19->cells != NULL && "map19 cells are null, map not assigned");
    int response19 = validate_map_contents(map19);
    assert(map19->num_collectables != 0 && "map19 num_collectables is 0");
    assert(response19 == 1 && "map19 is not valid");
    int playable19 = validate_map_playable(map19);
    assert(playable19 == 1 && "map19 reads as non playable but it is playable");
    free_parsed_map(map19);

    // 1000 lines map
    // // map 20.ber ************************************************************************************
    // int fd20 = open("maps/valid/20.ber", O_RDONLY);
    // t_file *file20 = ft_file_read_all(fd20);
    // assert(fd20 != -1 && "Could not open file 20.ber for testing");
    // close(fd20);
    // if (!file20)
    //     return ;
    // t_parsed_map *map20 = parse_map(file20);
    // ft_file_free(&file20);
    // assert(map20 != NULL && "parse_map returned NULL for valid map20");
    // assert(map20->cells != NULL && "map20 cells are null, map not assigned");
    // int response20 = validate_map_contents(map20);
    // assert(map20->num_collectables != 0 && "map20 num_collectables is 0");
    // assert(response20 == 1 && "map20 is not valid");
    // int playable20 = validate_map_playable(map20);
    // assert(playable20 == 1 && "map20 reads as non playable but it is playable");
    // free_parsed_map(map20);
}

static void test_validate_map_playable_ko()
{

    // map 9.ber ************************************************************************************
	int fd9 = open("maps/invalid/9.ber", O_RDONLY);
	assert(fd9 != -1 && "Could not open file9 for testing");
	t_file *file9 = ft_file_read_all(fd9);
	close(fd9);
	if (!file9)
		return ;
	t_parsed_map *map9 = parse_map(file9);
	ft_file_free(&file9);
	int response9 = validate_map_contents(map9);
	assert(response9 == 1 && "map9 is valid");
    int playable = validate_map_playable(map9);
    assert(playable == 0 && "map9 reads as playable but it is not playable");
	free_parsed_map(map9);

    // map 12.ber ************************************************************************************
    int fd12 = open("maps/invalid/12.ber", O_RDONLY);
    t_file *file12 = ft_file_read_all(fd12);
    close(fd12);
    if (!file12)
        return ;
    t_parsed_map *map12 = parse_map(file12);
    ft_file_free(&file12);
    int contents12 = validate_map_contents(map12);
    assert(contents12 == 1 && "map12 is not valid");
    int playable12 = validate_map_playable(map12);
    assert(playable12 == 0 && "map12 reads as playable but it is not playable");
    free_parsed_map(map12);
    
    // map 13.ber ************************************************************************************
    int fd13 = open("maps/invalid/13.ber", O_RDONLY);
    t_file *file13 = ft_file_read_all(fd13);
    close(fd13);
    if (!file13)
        return ;
    t_parsed_map *map13 = parse_map(file13);
    ft_file_free(&file13);
    int contents13 = validate_map_contents(map13);
    assert(contents13 == 1 && "map13 is not valid");
    int playable13 = validate_map_playable(map13);
    assert(playable13 == 0 && "map13 reads as playable but it is not playable");
    free_parsed_map(map13);

    // map 14.ber ************************************************************************************
    int fd14 = open("maps/invalid/14.ber", O_RDONLY);
    t_file *file14 = ft_file_read_all(fd14);
    close(fd14);
    if (!file14)
        return ;
    t_parsed_map *map14 = parse_map(file14);
    ft_file_free(&file14);
    int contents14 = validate_map_contents(map14);
    assert(contents14 == 1 && "map14 is not valid");
    int playable14 = validate_map_playable(map14);
    assert(playable14 == 0 && "map14 reads as playable but it is not playable");
    free_parsed_map(map14);

     // map 27.ber ************************************************************************************
    int fd27 = open("maps/fail/27.ber", O_RDONLY);
    t_file *file27 = ft_file_read_all(fd27);
    close(fd27);
    if (!file27)
        return ;
    t_parsed_map *map27 = parse_map(file27);
    ft_file_free(&file27);
    int contents27 = validate_map_contents(map27);
    assert(contents27 == 1 && "map27 is not valid");
    int playable27 = validate_map_playable(map27);
    assert(playable27 == 0 && "map27 reads as playable but it is not playable");
    free_parsed_map(map27);


}

// TODO: distinguish between CI tests and how-to-use examples, that is refine scope and decouple
int main(void)
{
    test_parse_map_valid();
    test_parse_map_invalid();	
    test_validate_map_content_ko();
	test_validate_map_content_ok();

    test_validate_map_playable_ok();
    test_validate_map_playable_ko();
    return 0;
}