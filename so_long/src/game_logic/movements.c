/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalarco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 11:57:29 by saalarco          #+#    #+#             */
/*   Updated: 2025/01/10 11:57:31 by saalarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "../../include/so_long.h"

// Function to update position of player
void move_player(t_game *game, int dx, int dy);

// Function to disable collectible and print some message
void collect(t_game *game, int x, int y);


// On movement update map
void move(t_game *game, int x, int y);

// Function is movement alllowed
int is_movement_allowed(t_game *game, int x, int y);
