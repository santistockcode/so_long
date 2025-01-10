/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_textures_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalarco <saalarco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 12:34:17 by saalarco          #+#    #+#             */
/*   Updated: 2025/01/10 17:23:54 by saalarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

// Function to free textures
void	free_textures(t_game *game)
{
	mlx_delete_texture(game->player_texture);
	mlx_delete_texture(game->nowall_texture);
	mlx_delete_texture(game->wall_texture);
	mlx_delete_texture(game->collectible_texture);
	mlx_delete_texture(game->exit_texture);
}

// Function to free images and textures
void	free_images_textures(t_game *game)
{
	mlx_delete_image(game->mlx, game->wall_image);
	mlx_delete_image(game->mlx, game->nowall_image);
	mlx_delete_image(game->mlx, game->player_image);
	mlx_delete_image(game->mlx, game->collectible_image);
	mlx_delete_image(game->mlx, game->exit_image);
	free_textures(game);
}
