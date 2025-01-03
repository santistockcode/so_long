/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalarco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 18:47:00 by saalarco          #+#    #+#             */
/*   Updated: 2025/01/03 18:47:02 by saalarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// // game.c
// #include "game.h"

// void move_player(t_game *game, int dx, int dy) {
//     int new_x = game->player_x + dx;
//     int new_y = game->player_y + dy;

//     if (game->map[new_y][new_x] != '1') { // Check for walls.
//         game->map[game->player_y][game->player_x] = '0';
	// Empty old position.
//         game->player_x = new_x;
//         game->player_y = new_y;
//         game->map[new_y][new_x] = 'P'; // Move player to new position.
//     }
// }
