/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalarco <saalarco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:15:16 by saalarco          #+#    #+#             */
/*   Updated: 2024/11/21 19:40:44 by saalarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	// correct usage
	if (argc <= 1)
		return (ft_printf(ERROR_USAGE));
	// correct extension
	if (!is_extension_correct(argv[1]))
		return (ft_printf(ERROR_FILE));
	// check map is valid
	if (is_map_empty(argv[1]))
		return (ft_printf(ERROR_EMPTY));
	// render map until close 
	// do shit
	// cosas mlx
	return (1);
}
