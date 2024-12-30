/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_parsed_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalarco <saalarco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 13:23:14 by saalarco          #+#    #+#             */
/*   Updated: 2024/12/30 13:00:07 by saalarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	free_parsed_map(t_parsed_map *map_data)
{
	int	i;

	if (!map_data)
		return ;
	i = 0;
	if (map_data->cells)
	{
		while (i < map_data->height)
		{
			if (map_data->cells[i])
				free(map_data->cells[i]);
			i++;
		}
		free(map_data->cells);
	}
	if (map_data->collectables)
	{
		ft_lstclear(&(map_data->collectables), free);
		free(map_data->collectables);
	}
	free(map_data);
}
