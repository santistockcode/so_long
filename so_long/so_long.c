/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalarco <saalarco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:15:16 by saalarco          #+#    #+#             */
/*   Updated: 2024/11/24 17:49:44 by saalarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int	main(int argc, char **argv)
{
	char	**map;

	// correct extension
	if (argc <= 1 || !is_extension_correct(argv[1]))
		return (ft_printf(ERROR_USAGE));
	// check map is valid

	// render map until close
	if(!(map = fetch_map(argv[1])))
		return (ft_printf(ERROR_FETCH));

	printf("Map after fetch:\n");
    for (int i = 0; i < 12; i++) {
        printf("%s\n", map[i]);
    }
	
	// do shit
	// cosas mlx
	return (1);
}