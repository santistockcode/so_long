/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_playable.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalarco <saalarco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 08:40:34 by saalarco          #+#    #+#             */
/*   Updated: 2024/12/30 14:21:21 by saalarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

/*
Marks all the cells that are reachable from the player's starting position
*/
void	flood_fill_mark(char **map, unsigned int from_y, unsigned int from_x)
{
	if ((map[from_y][from_x] == WALL) || (map[from_y][from_x] & 0x80) != 0)
		return ;
	if (map[from_y][from_x] != NOWALL && map[from_y][from_x] != PLAYER
		&& map[from_y][from_x] != EXITMAP && map[from_y][from_x] != COLLEC)
		return ;
	map[from_y][from_x] |= 0x80;
	flood_fill_mark(map, from_y + 1, from_x);
	flood_fill_mark(map, from_y - 1, from_x);
	flood_fill_mark(map, from_y, from_x + 1);
	flood_fill_mark(map, from_y, from_x - 1);
	return ;
}

/*
Unmarks all the cells that are reachable from the player's starting position
*/
void	flood_fill_unmark(char **map, unsigned int from_y, unsigned int from_x)
{
	if ((map[from_y][from_x] == WALL) || (map[from_y][from_x] & 0x80) == 0)
		return ;
	map[from_y][from_x] &= 0x7F;
	flood_fill_unmark(map, from_y + 1, from_x);
	flood_fill_unmark(map, from_y - 1, from_x);
	flood_fill_unmark(map, from_y, from_x + 1);
	flood_fill_unmark(map, from_y, from_x - 1);
	return ;
}

/*
Checks if the exit is reachable from the player's starting position
*/
int	is_exit_reachable(t_parsed_map *map)
{
	if ((map->cells[map->exit_pos.y][map->exit_pos.x] & 0x80) == 0)
	{
		return (FALSE);
	}
	return (TRUE);
}

/*
Checks if all the collectables are reachable from the exit
*/
int	are_collectables_reachable(t_parsed_map *map)
{
	int			index;
	t_list		*collec_node;
	t_position	*collectable_pos;

	index = 0;
	collec_node = map->collectables;
	while (index < map->num_collectables)
	{
		collectable_pos = (t_position *)collec_node->content;
		if ((map->cells[collectable_pos->y][collectable_pos->x] & 0x80) == 0)
			return (FALSE);
		collec_node = collec_node->next;
		index++;
	}
	return (TRUE);
}

/*
Validates if the map is playable
*/
int	validate_map_playable(t_parsed_map *map)
{
	if (!map)
		return (FALSE);
	flood_fill_mark(map->cells, map->player_start.y, map->player_start.x);
	if (!is_exit_reachable(map) || !are_collectables_reachable(map))
	{
		flood_fill_unmark(map->cells, map->player_start.y, map->player_start.x);
		return (FALSE);
	}
	else
	{
		flood_fill_unmark(map->cells, map->player_start.y, map->player_start.x);
		return (TRUE);
	}
}
