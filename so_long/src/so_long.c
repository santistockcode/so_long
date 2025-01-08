/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalarco <saalarco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:15:16 by saalarco          #+#    #+#             */
/*   Updated: 2025/01/08 13:15:09 by saalarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	t_parsed_map	*map;
	mlx_t			*mlx;

	map = argument_valid(argc, argv);
	// if (!map)
	// 	return (ft_printf(ERROR_ARGUMENT), 0);
	ft_printf("Map is good \n");
	mlx = init_window(map->width, map->height, MLX42_TITLE);
	// protect
	// initialize game
	// protect, check !game
	// render map
	// in case of error

	// loop for exit game
	// loop check for key press
	// run game loop
	close_window(mlx);
	free_parsed_map(map);
	// free images and textures
	// free game
	return (1);
}
