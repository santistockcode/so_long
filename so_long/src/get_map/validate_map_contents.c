/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_contents.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalarco <saalarco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 12:14:29 by saalarco          #+#    #+#             */
/*   Updated: 2024/12/27 17:29:51 by saalarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

// alloc_list_collectables

// flood fill from player

// flood fill clean from player

// flood fill check is reachable

// Count and locate P, E, C
static void	count_player_exitmap_collectables(t_parsed_map *map, int *count_players, int *count_exits)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->cells[i][j] == PLAYER)
			{
				(*count_players)++;
			}
			else if (map->cells[i][j] == EXITMAP)
			{
				(*count_exits)++;
			}
			else if (map->cells[i][j] == COLLEC)
				map->num_collectables++;
			j++;
		}
		i++;
	}
}

// before storing them in map->collectibles
int	validate_map_contents(t_parsed_map *map)
{
	int count_players;
    int count_exits;

	count_players = 0;
	count_exits = 0;
	if (!map)
		return (FALSE);
	count_player_exitmap_collectables(map, &count_players, &count_exits);
	if (map->num_collectables == 0 || count_players != 1 || count_exits != 1)
		return (FALSE);
	// if(!alloc_list_collectables(map))
	// 	return (FALSE);
	return (TRUE);
}
