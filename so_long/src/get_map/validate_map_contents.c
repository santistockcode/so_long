/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_contents.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalarco <saalarco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 12:14:29 by saalarco          #+#    #+#             */
/*   Updated: 2024/12/30 13:00:29 by saalarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

/*
Creates a new position node for the list
*/
t_list	*create_position(int i, int j)
{
	t_position	*position_new;

	position_new = (t_position *)malloc(sizeof(t_position));
	if (position_new == NULL)
		return (NULL);
	position_new->x = (unsigned int)j;
	position_new->y = (unsigned int)i;
	return (ft_lstnew((t_position *)position_new));
}

/*
Allocates a list of collectables
*/
t_list	*alloc_list_collectables(t_parsed_map *map)
{
	t_list	*list_head;
	t_list	*new_node;
	int		i;
	int		j;

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

/*
Find the player and exitmap
*/
static void	find_player_and_exitmap(t_parsed_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->cells[i][j] == EXITMAP)
			{
				map->exit_pos.x = (unsigned int)j;
				map->exit_pos.y = (unsigned int)i;
			}
			else if (map->cells[i][j] == PLAYER)
			{
				map->player_start.x = (unsigned int)j;
				map->player_start.y = (unsigned int)i;
			}
			j++;
		}
		i++;
	}
}

/*
Count and locate P, E, C
*/
static void	count_player_exitmap_collectables(t_parsed_map *map,
		int *count_players, int *count_exits)
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

/*
Validates the contents of the map
*/
int	validate_map_contents(t_parsed_map *map)
{
	int		count_players;
	int		count_exits;
	t_list	*collectables;

	count_players = 0;
	count_exits = 0;
	if (!map)
		return (FALSE);
	count_player_exitmap_collectables(map, &count_players, &count_exits);
	if (map->num_collectables == 0 || count_players != 1 || count_exits != 1)
		return (FALSE);
	find_player_and_exitmap(map);
	collectables = alloc_list_collectables(map);
	if (!collectables)
		return (FALSE);
	map->collectables = collectables;
	return (TRUE);
}
