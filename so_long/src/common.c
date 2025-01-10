/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalarco <saalarco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 16:27:19 by saalarco          #+#    #+#             */
/*   Updated: 2025/01/10 16:42:40 by saalarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_error(char *msg)
{
	ft_putstr_fd(RED, STDERR_FILENO);
	if (msg)
	{
		ft_putstr_fd("Error:\n", STDERR_FILENO);
		ft_putstr_fd(msg, STDERR_FILENO);
		ft_putchar_fd('\n', STDERR_FILENO);
	}
	if (mlx_errno)
	{
		ft_putstr_fd("Error:\n", STDERR_FILENO);
		ft_putstr_fd((char *)mlx_strerror(mlx_errno), STDERR_FILENO);
		ft_putchar_fd('\n', STDERR_FILENO);
	}
	ft_putstr_fd(NORMAL, STDERR_FILENO);
	exit (EXIT_FAILURE);
}
