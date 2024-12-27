/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_contents.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalarco <saalarco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 12:14:29 by saalarco          #+#    #+#             */
/*   Updated: 2024/12/27 19:48:39 by saalarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

t_list	*create_position(int i, int j)
{
	t_position *position_new;

	position_new = (t_position *) malloc (sizeof(t_position));
	if (position_new == NULL)
		return (NULL);
	position_new->x=(unsigned int) j;
	position_new->y=(unsigned int) i;
	return (ft_lstnew((t_position	*) position_new));
}
// alloc_list_collectables
t_list	*alloc_list_collectables(t_parsed_map *map)
{
	t_list	*list_head;
	t_list	*new_node;
	int	i;
	int	j;

	i = 0;
	list_head = NULL;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->cells[i][j] == COLLEC)
			{
				new_node = create_position(i, j);
				if (!new_node)
					return (ft_lstclear(&list_head, free), NULL);
				ft_lstadd_back(&list_head, new_node);
			}
			j++;
		}
		i++;
	}
	return (list_head);
}

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
	t_list	*collectables;

	count_players = 0;
	count_exits = 0;
	if (!map)
		return (FALSE);
	count_player_exitmap_collectables(map, &count_players, &count_exits);
	if (map->num_collectables == 0 || count_players != 1 || count_exits != 1)
		return (FALSE);
	collectables = alloc_list_collectables(map);
	if(!collectables)
		return (FALSE);
	map->collectables = collectables;
	return (TRUE);
}
