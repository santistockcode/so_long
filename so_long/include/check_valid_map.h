#ifndef CHECK_VALID_MAP_H
# define CHECK_VALID_MAP_H
# include <stddef.h>
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>

// map_data.h
typedef struct s_position {
    unsigned int x;
    unsigned int y;
} t_position;

typedef struct s_map_data {
    int height;
    int width;
    char **map; // split by \n
    t_position player_start;
    t_position exit_pos;
    t_position *collectables;
    int num_collectables;
} t_map_data;

// fullfill map_data struct
t_map_data *get_map_data(t_file *file);

// check if map is valid
int validate_map_data(t_map_data *map_data);

// en una sola función y todas las de dentro son static (de esta forma si usas lldb sabes donde cohones ha fallado)

// // checks map its a rectangle
// int check_is_rectangle(t_map_data *map_data);

// // check map has valid characters
// int check_has_valid_chars(t_map_data *map_data);

// check map has walls around it
// int check_has_walls(t_map_data *map_data);

// check has at least one player, exit, collectable
// int check_has_player_exit_collectable(t_map_data *map_data);

// check if collectables and exit are reachable
int check_pathfind(t_map_data *map_data);

// free map data
void free_map_data(t_map_data *map_data);

// Valorar según haga pruebas si crear un .h para todos los borradores

#endif