/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_mlx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalarco <saalarco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 18:47:11 by saalarco          #+#    #+#             */
/*   Updated: 2025/01/09 13:03:48 by saalarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"


void display_graphics(t_game *game, mlx_t *mlx, t_parsed_map *map)
{
	game->mlx = mlx;
	game->map = map;
	if (!load_textures(game))
	{
		free_parsed_map(map);
		close_window(mlx);
		ft_error(ERROR_IMAGES);
	}
	if (!load_images(game))
	{
		free_textures(game);
		free_parsed_map(map);
		close_window(mlx);
		ft_error(ERROR_IMAGES);
	}
	render_map(game);
}
