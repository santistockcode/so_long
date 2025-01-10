/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_mlx.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalarco <saalarco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 11:53:55 by saalarco          #+#    #+#             */
/*   Updated: 2025/01/10 16:49:08 by saalarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_MLX_H
# define DISPLAY_MLX_H
# include "../MLX42/include/MLX42/MLX42.h"
# include "hooks_mlx.h"
# include <stdio.h>
# include <stdlib.h>

# define P_PATH "textures/player.png"
# define W_PATH "textures/wall.png"
# define NW_PATH "textures/nowall.png"
# define C_PATH "textures/collec.png"
# define E_PATH "textures/exit.png"

// Functions to load images and textures to the game struct
int		load_textures(t_game *game);
int		load_images(t_game *game);

// Function to put images to window (images I already have in the structure)
void	render_map(t_game *game);
void	render_player(t_game *game);

// Function to free the textures and images
void	free_textures(t_game *game);
void	free_images_textures(t_game *game);

#endif
