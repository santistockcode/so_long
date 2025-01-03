/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_valid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalarco <saalarco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 10:01:14 by saalarco          #+#    #+#             */
/*   Updated: 2025/01/03 18:31:40 by saalarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	report_error_argument_valid(const char *msg, t_parsed_map *map,
		int free_map)
{
	ft_putstr_fd((char *) ERROR, 1);
	ft_putstr_fd((char *) msg, 1);
	if (free_map)
		free_parsed_map(map);
}

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
		return (report_error_argument_valid(ERROR_USAGE, NULL, 0), NULL);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (report_error_argument_valid(ERROR_OPEN, NULL, 0), NULL);
	file = ft_file_read_all(fd);
	close(fd);
	if (!file)
		return (report_error_argument_valid(ERROR_EMPTY, NULL, 0), NULL);
	map = parse_map(file);
	ft_file_free(&file);
	if (!map)
		return (report_error_argument_valid(ERROR_PARSE, NULL, 0), NULL);
	if (!validate_map_contents(map))
		return (report_error_argument_valid(ERROR_CONTENTS, map, 1), NULL);
	if (!validate_map_playable(map))
		return (report_error_argument_valid(ERROR_PLAYABLE, map, 1), NULL);
	return (map);
}
