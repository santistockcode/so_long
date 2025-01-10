/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalarco <saalarco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 11:57:29 by saalarco          #+#    #+#             */
/*   Updated: 2025/01/10 17:50:15 by saalarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

// Function to update position of player
void	move_player(t_game *game, int x, int y)
{
	game->movements++;
	game->p_x = x;
	game->p_y = y;
	game->player_image->instances->x = game->p_x * IMAGE_SIZE;
	game->player_image->instances->y = game->p_y * IMAGE_SIZE;
}

// Function to disable collectible and print some message
void	collect(t_game *game, int x, int y)
{
	int	i;

	i = 0;
	while (i < game->map->num_collectables)
	{
		if (game->collectible_image->instances[i].x == x * IMAGE_SIZE
			&& game->collectible_image->instances[i].y == y * IMAGE_SIZE)
		{
			game->collectible_image->instances[i].enabled = FALSE;
		}
		i++;
	}
	game->map->cells[y][x] = NOWALL;
	move_player(game, x, y);
	game->c_left--;
	ft_putstr_fd(GREEN, STDOUT_FILENO);
	ft_printf("Collectible collected, left: %d\n", game->c_left);
	ft_putstr_fd(NORMAL, STDOUT_FILENO);
}

// On movement update map
void	move(t_game *game, int x, int y)
{
	if (game->map->cells[y][x] == COLLEC)
		collect(game, x, y);
	else if (game->map->cells[y][x] == EXITMAP && game->c_left == 0)
	{
		move_player(game, x, y);
		end_game(game);
	}
	else
		move_player(game, x, y);
}

// Function is movement alllowed
int	is_movement_allowed(t_game *game, int x, int y)
{
	if (x < 0 || y < 0 || x >= game->map->width || y >= game->map->height)
		return (0);
	if (game->map->cells[y][x] == WALL)
	{
		ft_putstr_fd(RED, STDOUT_FILENO);
		ft_printf("You can't move there\n");
		ft_putstr_fd(NORMAL, STDOUT_FILENO);
		return (0);
	}
	return (1);
}
