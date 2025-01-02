/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalarco <saalarco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 13:39:37 by saalarco          #+#    #+#             */
/*   Updated: 2025/01/02 15:07:32 by saalarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H

# include <../MLX42/include/MLX42/MLX42.h>

mlx_t* init_window(int width, int height, const char *title);
void close_window(mlx_t *mlx);

// inside init_window
// int					is_screen_size_valid(t_game *game);

#endif
