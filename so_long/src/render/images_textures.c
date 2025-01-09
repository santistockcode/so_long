/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalarco <saalarco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 12:30:22 by saalarco          #+#    #+#             */
/*   Updated: 2025/01/09 13:06:14 by saalarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	load_textures(t_game *game)
{
	game->player_texture = mlx_load_png(P_PATH);
	if (!game->player_texture)
		return (FALSE);
	game->nowall_texture = mlx_load_png(NW_PATH);
	if (!game->nowall_texture)
		return (mlx_delete_texture(game->player_texture), (FALSE));
	game->wall_texture = mlx_load_png(W_PATH);
	if (!game->wall_texture)
		return (mlx_delete_texture(game->player_texture),
			mlx_delete_texture(game->nowall_texture), (FALSE));
	game->collectible_texture = mlx_load_png(C_PATH);
	if (!game->collectible_texture)
		return (mlx_delete_texture(game->player_texture),
			mlx_delete_texture(game->nowall_texture),
			mlx_delete_texture(game->wall_texture), (FALSE));
	game->exit_texture = mlx_load_png(E_PATH);
	if (!game->exit_texture)
	{
		mlx_delete_texture(game->player_texture);
		mlx_delete_texture(game->nowall_texture);
		mlx_delete_texture(game->wall_texture);
		mlx_delete_texture(game->collectible_texture);
		return (FALSE);
	}
	return (TRUE);
}

int	load_images(t_game *game)
{
	game->player_image = mlx_texture_to_image(game->mlx, game->player_texture);
	game->nowall_image = mlx_texture_to_image(game->mlx, game->nowall_texture);
	game->wall_image = mlx_texture_to_image(game->mlx, game->wall_texture);
	game->collectible_image = mlx_texture_to_image(game->mlx,
			game->collectible_texture);
	game->exit_image = mlx_texture_to_image(game->mlx, game->exit_texture);
	if (!game->player_image || !game->nowall_image || !game->wall_image
		|| !game->collectible_image || !game->exit_image)
		return (FALSE);
	return (TRUE);
}

static void	ft_image_to_window(t_game *game, int x, int y)
{
	if (game->map->cells[y][x] == WALL)
		mlx_image_to_window(game->mlx, game->wall_image, x * IMAGE_SIZE, y
			* IMAGE_SIZE);
	else if (game->map->cells[y][x] == NOWALL)
		mlx_image_to_window(game->mlx, game->nowall_image, x * IMAGE_SIZE, y
			* IMAGE_SIZE);
	else if (game->map->cells[y][x] == PLAYER)
		mlx_image_to_window(game->mlx, game->player_image, x * IMAGE_SIZE, y
			* IMAGE_SIZE);
	else if (game->map->cells[y][x] == COLLEC)
		mlx_image_to_window(game->mlx, game->collectible_image, x * IMAGE_SIZE,
			y * IMAGE_SIZE);
	else if (game->map->cells[y][x] == EXITMAP)
		mlx_image_to_window(game->mlx, game->exit_image, x * IMAGE_SIZE, y
			* IMAGE_SIZE);
}

void	render_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			ft_image_to_window(game, x, y);
			x++;
		}
		y++;
	}
}
