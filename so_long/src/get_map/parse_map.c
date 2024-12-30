/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalarco <saalarco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 13:19:41 by saalarco          #+#    #+#             */
/*   Updated: 2024/12/30 16:52:24 by saalarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

// /*
// Function initializes map_data struct
// */
static void	initialize_map_data(t_parsed_map *map_data)
{
	map_data->cells = NULL;
	map_data->height = 0;
	map_data->width = 0;
	map_data->collectables = NULL;
	map_data->num_collectables = 0;
	map_data->player_start.x = 0;
	map_data->player_start.y = 0;
	map_data->exit_pos.x = 0;
	map_data->exit_pos.y = 0;
}

/*
Function check if map has valid characters
*/
static int	check_has_valid_chars(t_parsed_map *map_data)
{
	int	i;
	int	j;

	i = 0;
	while (i < map_data->height)
	{
		j = 0;
		while (j < map_data->width)
		{
			if (map_data->cells[i][j] != WALL && map_data->cells[i][j] != NOWALL
				&& map_data->cells[i][j] != PLAYER
				&& map_data->cells[i][j] != EXITMAP
				&& map_data->cells[i][j] != COLLEC)
				return (FALSE);
			j++;
		}
		i++;
	}
	return (TRUE);
}

/*
Function checks if map has walls
*/
static int	check_has_walls(t_parsed_map *map_data)
{
	int	i;
	int	j;

	i = 0;
	while (i < map_data->height)
	{
		j = 0;
		if (i == 0 || i == map_data->height - 1)
		{
			while (j < map_data->width)
			{
				if (map_data->cells[i][j] != WALL)
					return (FALSE);
				j++;
			}
		}
		else
		{
			if (map_data->cells[i][0] != WALL
				|| map_data->cells[i][map_data->width - 1] != WALL)
				return (FALSE);
		}
		i++;
	}
	return (TRUE);
}

/*
Functions check if map is a rectangle
*/
static int	check_is_rectangle(t_parsed_map *map_data)
{
	int	i;
	int	len;

	len = ft_strlen(map_data->cells[0]);
	if (len <= 2)
		return (FALSE);
	i = 0;
	while (i < map_data->height)
	{
		if ((int)ft_strlen(map_data->cells[i]) != len)
			return (FALSE);
		i++;
	}
	map_data->width = len;
	if (map_data->width == map_data->height)
		return (FALSE);
	return (TRUE);
}

/*

*/
t_parsed_map	*parse_map(t_file *file)
{
	t_parsed_map	*map_data;
	int				i;

	map_data = NULL;
	i = 0;
	if (!file || file->line_count < 3)
		return (NULL);
	map_data = (t_parsed_map *)malloc(sizeof(t_parsed_map));
	if (map_data == NULL)
		return (NULL);
	initialize_map_data(map_data);
	map_data->cells = ft_split(file->buffer, '\n');
	if (map_data->cells == NULL)
		return (free(map_data), NULL);
	while (map_data->cells[i] != NULL)
		i++;
	map_data->height = i;
	if (map_data->height != (int)file->line_count
		|| !check_is_rectangle(map_data) || !check_has_walls(map_data)
		|| !check_has_valid_chars(map_data))
	{
		free_parsed_map(map_data);
		return (NULL);
	}
	return (map_data);
}
