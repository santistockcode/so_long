/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalarco <saalarco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:15:16 by saalarco          #+#    #+#             */
/*   Updated: 2024/11/29 16:44:26 by saalarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void initialize_map(Map *map)
{
	map->height = 0;
	map->width = 0;
	map->map = NULL;
}


int	main(int argc, char **argv)
{
	Map game_map;

	if (argc <= 1 || !is_extension_correct(argv[1]))
	{
		return(perror(ERROR_USAGE), 1);
	}
	// initialize variables for map
	initialize_map(&game_map);

	// open file measure map close file, check for errors
	if (measure_map(argv[1], &game_map) == -1)
		return(ft_printf("measure_map %s: %s\n", argv[1], strerror(errno)), 1);

	// open file fetch map into memory close map, check for errors
	//have_map(argv[1], &game_map);

	// print hurray 

	// printf("Map after fetch:\n");
    // for (int i = 0; i < 12; i++) {
    //     printf("%s\n", map[i]);
    // }

	// cosas mlx
	return (1);
}
