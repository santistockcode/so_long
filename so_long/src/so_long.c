/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalarco <saalarco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:15:16 by saalarco          #+#    #+#             */
/*   Updated: 2024/12/23 12:37:30 by saalarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"


int	main(int argc, char **argv)
{

	if (argc != 2 || !is_extension_correct(argv[1]))
		return(ft_printf(ERROR_USAGE), 0);

	// get_file -> validate map data -> map pathfinder 
	
	// cosas mlx
	return (1);
}
