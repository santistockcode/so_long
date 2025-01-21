/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_conditions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalarco <saalarco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 11:57:04 by saalarco          #+#    #+#             */
/*   Updated: 2025/01/21 19:05:44 by saalarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

// Function to print some cool message and free all
static void	close_game(t_game *game)
{
	ft_putstr_fd(CYAN, STDOUT_FILENO);
	printf("Congratulations! You have finished the game in %d movements\n",
		game->movements);
	ft_putstr_fd(NORMAL, STDOUT_FILENO);
	free_images_textures(game);
	free_parsed_map(game->map);
	close_window(game->mlx);
	free(game);
}

// Function to allow exit (end game)
void	end_game(t_game *game)
{
	close_game(game);
	ft_putstr_fd(MAGNENTA, STDOUT_FILENO);
	ft_printf("So long, farewell, thanks lucak.itch.io/glitchy-pixel-art\n");
	ft_putstr_fd(NORMAL, STDOUT_FILENO);
	exit(EXIT_SUCCESS);
}

/*
Function to manage window exit pressing x
*/
void	window_exit_handle(void *ptr)
{
	t_game	*game;

	game = (t_game *)ptr;
	free_images_textures(game);
	free_parsed_map(game->map);
	close_window(game->mlx);
	free(game);
	ft_putstr_fd(MAGNENTA, STDOUT_FILENO);
	ft_printf("So long, farewell, thanks lucak.itch.io/glitchy-pixel-art\n");
	ft_putstr_fd(NORMAL, STDOUT_FILENO);
	exit(EXIT_SUCCESS);
}
