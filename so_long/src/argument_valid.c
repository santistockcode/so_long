/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_valid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalarco <saalarco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 10:01:14 by saalarco          #+#    #+#             */
/*   Updated: 2025/01/10 16:42:25 by saalarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// Function to check file extension
static int	is_extension_correct(char *file)
{
	int	len;

	len = ft_strlen(file);
	if (file[len - 1] == 'r' && file[len - 2] == 'e' && file[len - 3] == 'b'
		&& file[len - 4] == '.')
	{
		return (TRUE);
	}
	else
		return (FALSE);
}

// Are arguments and it contents valid to play the game?
t_parsed_map	*argument_valid(int argc, char **argv)
{
	int				fd;
	t_file			*file;
	t_parsed_map	*map;

	if (argc != 2 || !is_extension_correct(argv[1]))
		return (ft_error(ERROR_USAGE), NULL);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (ft_error(ERROR_OPEN), NULL);
	file = ft_file_read_all(fd);
	close(fd);
	if (!file)
		return (ft_error(ERROR_EMPTY), NULL);
	map = parse_map(file);
	ft_file_free(&file);
	if (!map)
		return (ft_error(ERROR_PARSE), NULL);
	if (!validate_map_contents(map))
		return (free_parsed_map(map), ft_error(ERROR_CONTENTS), NULL);
	if (!validate_map_playable(map))
		return (free_parsed_map(map), ft_error(ERROR_PLAYABLE), NULL);
	return (map);
}
