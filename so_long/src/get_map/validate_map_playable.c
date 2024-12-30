/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_playable.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalarco <saalarco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 08:40:34 by saalarco          #+#    #+#             */
/*   Updated: 2024/12/30 12:32:52 by saalarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	flood_fill_mark(char **map, unsigned int from_x, unsigned int from_y)
{
	if ((map[from_x][from_y] == WALL) || (map[from_x][from_y] & 0x80) != 0)
		return ;
	if (map[from_x][from_y] != NOWALL && map[from_x][from_y] != PLAYER
		&& map[from_x][from_y] != EXITMAP && map[from_x][from_y] != COLLEC)
		return ;
	map[from_x][from_y] |= 0x80;
	flood_fill_mark(map, from_x + 1, from_y);
	flood_fill_mark(map, from_x - 1, from_y);
	flood_fill_mark(map, from_x, from_y + 1);
	flood_fill_mark(map, from_x, from_y - 1);
	return ;
}

void	flood_fill_unmark(char **map, unsigned int from_x, unsigned int from_y)
{
	if ((map[from_x][from_y] == WALL) || (map[from_x][from_y] & 0x80) == 0)
		return ;
	map[from_x][from_y] &= 0x7F;
	flood_fill_unmark(map, from_x + 1, from_y);
	flood_fill_unmark(map, from_x - 1, from_y);
	flood_fill_unmark(map, from_x, from_y + 1);
	flood_fill_unmark(map, from_x, from_y - 1);
	return ;
}

int	is_exit_reachable(t_parsed_map *map)
{
	flood_fill_mark(map->cells, map->player_start.y, map->player_start.x);
	if ((map->cells[map->exit_pos.y][map->exit_pos.x] & 0x80) == 0)
	{
		flood_fill_unmark(map->cells, map->player_start.y, map->player_start.x);
		return (FALSE);
	}
	flood_fill_unmark(map->cells, map->player_start.y, map->player_start.x);
	return (TRUE);
}

int	are_collectables_reachable(t_parsed_map *map)
{
	int			index;
	t_list		*collec_node;
	t_position	*collectable_pos;

	index = 0;
	while (index < map->num_collectables)
	{
		collec_node = map->collectables;
		collectable_pos = collec_node->content;
		flood_fill_mark(map->cells, collectable_pos->y, collectable_pos->x);
		if ((map->cells[map->exit_pos.y][map->exit_pos.x] & 0x80) == 0)
		{
			flood_fill_unmark(map->cells, collectable_pos->y,
				collectable_pos->x);
			return (FALSE);
		}
		collec_node = collec_node->next;
		index++;
	}
    flood_fill_unmark(map->cells, collectable_pos->y,collectable_pos->x);
	return (TRUE);
}

// before storing them in map->collectibles
int	validate_map_playable(t_parsed_map *map)
{
	if (!map)
		return (FALSE);
	if (!is_exit_reachable(map) || !are_collectables_reachable(map))
		return (FALSE);
	else
		return (TRUE);
}