/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalarco <saalarco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 18:47:00 by saalarco          #+#    #+#             */
/*   Updated: 2025/01/10 17:49:23 by saalarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/*
Function to manage key pressed and update graphics based on logic
*/
void	key_handle(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
	{
		if (is_movement_allowed(game, game->p_x, game->p_y - 1))
			move(game, game->p_x, game->p_y - 1);
	}
	else if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
	{
		if (is_movement_allowed(game, game->p_x - 1, game->p_y))
			move(game, game->p_x - 1, game->p_y);
	}
	else if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
	{
		if (is_movement_allowed(game, game->p_x + 1, game->p_y))
			move(game, game->p_x + 1, game->p_y);
	}
	else if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
	{
		if (is_movement_allowed(game, game->p_x, game->p_y + 1))
			move(game, game->p_x, game->p_y + 1);
	}
	else if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		window_exit_handle(game);
}

/*
Function to print movements on terminal
*/
void	print_movements_handle(void *ptr)
{
	t_game	*p;

	p = (t_game *)ptr;
	ft_putstr_fd(YELLOW, STDOUT_FILENO);
	ft_printf("Movements: %d\r", p->movements);
	ft_putstr_fd(NORMAL, STDOUT_FILENO);
}

/*
Function to manage window exit pressing x
*/
void	window_exit_handle(void *ptr)
{
	t_game	*game;

	game = (t_game *)ptr;
	ft_putstr_fd(MAGNENTA, STDOUT_FILENO);
	ft_printf("So long, farewell, thanks lucak.itch.io/glitchy-pixel-art\n");
	ft_putstr_fd(NORMAL, STDOUT_FILENO);
	free_images_textures(game);
	free_parsed_map(game->map);
	close_window(game->mlx);
	free(game);
	exit(EXIT_SUCCESS);
}
