/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalarco <saalarco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:15:16 by saalarco          #+#    #+#             */
/*   Updated: 2025/01/03 18:47:34 by saalarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	t_parsed_map	*map;
	mlx_t			*mlx;

	map = argument_valid(argc, argv);
	if (!map)
		return (ft_printf(ERROR_ARGUMENT), 0);
	ft_printf("Map is good \n");
	mlx = init_window(map->width, map->height, MLX42_TITLE);
	close_window(mlx);
	ft_printf("and fits!\n");
	free_parsed_map(map);
	return (1);
}
	// mlx_image_t
	// load images
	// game_t
	// game logic
	// run game loop
	// cleanup
	/*
	// Implement the functions here...
t_parsed_map	*parse_and_validate_arguments(int argc, char **argv) {
	// Implementation of argument parsing and validation
}

mlx_t	*initialize_window(void) {
	// Implementation of window initialization using mlx42
}

mlx_image_t	*load_images(mlx_t *mlx) {
	// Implementation of image loading
}

game_t	*initialize_game_logic(t_parsed_map *map, mlx_t *mlx,
		mlx_image_t *images) {
	// Implementation of game logic initialization
}

void	run_game_loop(game_t *game) {
	// Implementation of the game loop
}

void	cleanup(t_parsed_map *map, mlx_t *mlx, mlx_image_t *images,
		game_t *game) {
	// Implementation of resource cleanup

	*/