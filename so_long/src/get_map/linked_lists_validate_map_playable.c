#include "../../include/so_long.h"

typedef struct s_point {
    unsigned int y;
    unsigned int x;
} t_point;


static t_point *create_point(unsigned int y, unsigned int x)
{
    t_point *pt = (t_point *)malloc(sizeof(t_point));
    if (!pt)
        return (NULL);
    pt->y = y;
    pt->x = x;
    return (pt);
}
/**
 * @brief Mark reachable cells by setting the 0x80 bit,
 *        starting from (start_y, start_x).
 * 
 * @param map       2D array of chars (map->cells)
 * @param height    Map height (map->height)
 * @param width     Map width (map->width)
 * @param start_y   Starting row
 * @param start_x   Starting column
 */
void bfs_mark(char **map, unsigned int height, unsigned int width,
              unsigned int start_y, unsigned int start_x)
{
    t_list  *queue;
    t_point *start_pt;

    // 1) Create a queue (empty list)
    queue = NULL;

    // 2) Create the starting point
    start_pt = create_point(start_y, start_x);
    if (!start_pt)
        return;

    // 3) Check if the start is valid for marking (not wall, not visited)
    //    and if so, mark it and enqueue it.
    if (map[start_y][start_x] != WALL
        && ((map[start_y][start_x] & 0x80) == 0) // not visited yet
        && (map[start_y][start_x] == NOWALL
            || map[start_y][start_x] == PLAYER
            || map[start_y][start_x] == EXITMAP
            || map[start_y][start_x] == COLLEC))
    {
        // Mark visited
        map[start_y][start_x] |= 0x80;
        // Enqueue
        ft_lstadd_back(&queue, ft_lstnew(start_pt));
    }
    else
    {
        // If it's invalid or already visited, just free start_pt and return
        free(start_pt);
        return;
    }

    // 4) Directions: up, down, left, right
    const int dirY[4] = {1, -1, 0,  0};
    const int dirX[4] = {0,  0, 1, -1};

    // 5) BFS loop
    while (queue)
    {
        // pop front
        t_list  *front_node = queue;
        queue = queue->next;

        t_point *cur = (t_point *)front_node->content;
        free(front_node); // free the node; we keep 'cur' pointer

        // For each neighbor
        for (int i = 0; i < 4; i++)
        {
            unsigned int ny = cur->y + dirY[i];
            unsigned int nx = cur->x + dirX[i];

            // If you are certain out-of-bound is impossible because
            // your map is guaranteed closed with walls, you can skip checks.
            if (ny >= height || nx >= width)
                continue;

            if (map[ny][nx] == WALL || (map[ny][nx] & 0x80) != 0)
                continue;

            if (map[ny][nx] == NOWALL
                || map[ny][nx] == PLAYER
                || map[ny][nx] == EXITMAP
                || map[ny][nx] == COLLEC)
            {
                // Mark visited
                map[ny][nx] |= 0x80;
                // Allocate neighbor point and enqueue
                t_point *neighbor_pt = create_point(ny, nx);
                if (neighbor_pt)
                    ft_lstadd_back(&queue, ft_lstnew(neighbor_pt));
            }
        }
        // Done exploring current cell
        free(cur); // Now we can free the coordinate struct as well
    }
}

static void clear_visited_bits(char **map, unsigned int height, unsigned int width)
{
    for (unsigned int r = 0; r < height; r++)
    {
        for (unsigned int c = 0; c < width; c++)
            map[r][c] &= 0x7F;
    }
}

int is_exit_reachable(t_parsed_map *map)
{
    // If exit cell has 0x80 bit set => visited => reachable
    if ((map->cells[map->exit_pos.y][map->exit_pos.x] & 0x80) == 0)
        return (FALSE);
    return (TRUE);
}

int are_collectables_reachable(t_parsed_map *map)
{
    t_list  *node = map->collectables;
    int     i = 0;

    while (i < map->num_collectables && node)
    {
        t_position *collectable_pos = (t_position *)node->content;
        // If not visited => unreachable
        if ((map->cells[collectable_pos->y][collectable_pos->x] & 0x80) == 0)
            return (FALSE);
        node = node->next;
        i++;
    }
    return (TRUE);
}



int validate_map_playable(t_parsed_map *map)
{
    if (!map)
        return (FALSE);

    // 1) Mark all reachable cells from player's position
    bfs_mark(
        map->cells,
        map->height,
        map->width,
        map->player_start.y,
        map->player_start.x
    );

    // 2) Check exit & collectables
    if (!is_exit_reachable(map) || !are_collectables_reachable(map))
    {
        // 2a) If not reachable => unmark from the player's position
        clear_visited_bits(
            map->cells,
            map->height,
            map->width
        );
        return (FALSE);
    }

    // 3) If everything reachable => unmark
    clear_visited_bits(
            map->cells,
            map->height,
            map->width
        );

    return (TRUE);
}

