/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalarco <saalarco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 13:23:14 by saalarco          #+#    #+#             */
/*   Updated: 2024/12/27 14:16:45 by saalarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"


void free_map_data_no_collectables(t_parsed_map *map_data)
{
    int i;

    if (!map_data)
        return;

    /* Free each row of the map */
    if (map_data->cells)
    {
        for (i = 0; i < map_data->height; i++)
        {
            if (map_data->cells[i])
                free(map_data->cells[i]);
        }
        /* Free the array of row pointers */
        free(map_data->cells);
    }

    /* Free collectables array */
    // if (map_data->collectables)
    //     free(map_data->collectables);

    /* Finally, free the struct itself */
    free(map_data);
}

void free_map_data(t_parsed_map *map_data)
{
    int i;

    if (!map_data)
        return;

    /* Free each row of the map */
    if (map_data->cells)
    {
        for (i = 0; i < map_data->height; i++)
        {
            if (map_data->cells[i])
                free(map_data->cells[i]);
        }
        /* Free the array of row pointers */
        free(map_data->cells);
    }

    /* Free collectables array */
    free(map_data->collectables);

    /* Finally, free the struct itself */
    free(map_data);
}
