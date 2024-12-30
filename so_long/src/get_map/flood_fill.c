/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalarco <saalarco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 17:20:14 by saalarco          #+#    #+#             */
/*   Updated: 2024/12/30 19:57:44 by saalarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static t_position	*create_pos(unsigned int y, unsigned int x)
{
	t_position	*pt;

	pt = (t_position *)malloc(sizeof(t_position));
	if (!pt)
		return (NULL);
	pt->y = y;
	pt->x = x;
	return (pt);
}

static int	mark_visited(char **map, unsigned int y, unsigned int x,
		t_list **list)
{
	t_position	*adjacent_pt;
	t_list		*new_node;

	if (map[y][x] == WALL || (map[y][x] & 0x80) != 0)
		return (1);
	if (map[y][x] == NOWALL || map[y][x] == PLAYER || map[y][x] == EXITMAP
		|| map[y][x] == COLLEC)
	{
		map[y][x] |= 0x80;
		adjacent_pt = create_pos(y, x);
		if (!adjacent_pt)
		{
			free(adjacent_pt);
			return (0);
		}
		new_node = ft_lstnew(adjacent_pt);
		if (!new_node)
		{
			ft_lstclear(list, free);
			return (0);
		}
		ft_lstadd_back(list, new_node);
	}
	return (1);
}

/*
Moves head to the next node and frees the previous node
*/
static void	surrounding_cells(char **map, t_list *list)
{
	t_list		*front_node;
	t_position	*current;

	while (list)
	{
		front_node = list;
		list = list->next;
		current = front_node->content;
		free(front_node);
		if (!mark_visited(map, current->y + 1, current->x, &list)
			|| !mark_visited(map, current->y - 1, current->x, &list)
			|| !mark_visited(map, current->y, current->x + 1, &list)
			|| !mark_visited(map, current->y, current->x - 1, &list))
		{
			ft_lstclear(&list, free);
			free(current);
			return ;
		}
		free(current);
	}
}

/*
Creates a new empty list
Creates the starting position
If the start is valid, mark it and add it to list
Goes for the neightbors of the starting position
*/
void	flood_fill_mark(char **map, unsigned int from_y, unsigned int from_x)
{
	t_list		*list;
	t_position	*start_position;
	t_list		*new_node;

	list = NULL;
	start_position = create_pos(from_y, from_x);
	if (!start_position)
		return ;
	if (map[from_y][from_x] != WALL && ((map[from_y][from_x] & 0x80) == 0)
		&& (map[from_y][from_x] == NOWALL || map[from_y][from_x] == PLAYER
			|| map[from_y][from_x] == EXITMAP || map[from_y][from_x] == COLLEC))
	{
		map[from_y][from_x] |= 0x80;
		new_node = ft_lstnew(start_position);
		if (!new_node)
			return (free(start_position));
		ft_lstadd_back(&list, new_node);
	}
	else
		return ;
	surrounding_cells(map, list);
}
