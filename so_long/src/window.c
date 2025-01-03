/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalarco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 18:47:44 by saalarco          #+#    #+#             */
/*   Updated: 2025/01/03 18:47:45 by saalarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	report_error_window(const char *msg)
{
	ft_putstr_fd((char *)ERROR, 1);
	ft_putstr_fd((char *)msg, 1);
}

// /*
// Check if width and heigh for fixed image size fits screen size
// */
static int	map_fits_screen_size(int width, int height)
{
	if (MAX_MONITOR_WIDTH <= (IMAGE_SIZE * width)
		|| MAX_MONITOR_HEIGHT <= (IMAGE_SIZE * height))
		return (0);
	return (1);
}

/*
Initializes a window with the specified width, height, and title.
Returns a pointer to the initialized window (mlx_t*).
*/
mlx_t	*init_window(int width, int height, const char *title)
{
	mlx_t	*mlx;

	if (!map_fits_screen_size(width, height))
	{
		report_error_window(ERROR_SCREEN);
		return (NULL);
	}
	mlx = mlx_init(width, height, title, false);
	if (!mlx)
	{
		report_error_window(ERROR_MLX_WINDOW);
		return (NULL);
	}
	return (mlx);
}

void	close_window(mlx_t *mlx)
{
	if (mlx)
		mlx_terminate(mlx);
}
