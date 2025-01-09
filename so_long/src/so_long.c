/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalarco <saalarco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:15:16 by saalarco          #+#    #+#             */
/*   Updated: 2025/01/09 13:03:52 by saalarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	t_game 			*game;
	t_parsed_map	*map;
	mlx_t			*mlx;

	map = argument_valid(argc, argv);
	mlx = init_window(map->width, map->height, MLX42_TITLE);
	if (!map || !mlx)
		ft_error(ERROR_UNKNOWN);
	game = ft_calloc(1, sizeof(t_game));
	if (!game)
	{
		close_window(mlx);
		free_parsed_map(map);
		ft_error(ERROR_MALLOC);
	}
	display_graphics(game, mlx, map);
	mlx_loop(game->mlx);

	free_images_textures(game);
	free_parsed_map(map);
	close_window(game->mlx);
	free(game);
	return (1);
}
