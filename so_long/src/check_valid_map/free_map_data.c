/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalarco <saalarco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 13:23:14 by saalarco          #+#    #+#             */
/*   Updated: 2024/12/23 20:03:36 by saalarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"


void free_map_data(t_map_data *map_data)
{
    int i;

    if (!map_data)
        return;

    /* Free each row of the map */
    if (map_data->map)
    {
        for (i = 0; i < map_data->height; i++)
        {
            if (map_data->map[i])
                free(map_data->map[i]);
        }
        /* Free the array of row pointers */
        free(map_data->map);
    }

    /* Free collectables array */
    // if (map_data->collectables)
    //     free(map_data->collectables);

    /* Finally, free the struct itself */
    free(map_data);
}
