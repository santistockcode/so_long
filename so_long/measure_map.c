
#include "so_long.h"

// int	is_no_line(char *line, int fd);
// void	fetch_map_line(char **map, char *line, int h, size_t row);
int measure_height(int fd, char *line);
void measure_map_and_alloc(char **file);
int	line_problem(char *line, int fd);

int	line_problem(char *line, int fd)
{
	if (line == NULL) // end of line or error
	{
		close(fd);
		return (TRUE);
	}
	if (line[0] == '\0') // se libera
	{
		free(line);
		line = NULL;
		close(fd);
		return (TRUE);
	}
	return (FALSE);
}

// void	fetch_map_line(char **map, char *line, int h, size_t row)
// {
// 	int	v;

// 	v = 0;
// 	if (ft_strlen(line) != row)
// 		return (ft_printf(ERROR_EXTENSION));
// 	while (line[v] != '\0')
// 	{
// 		map[h][v] = line[v];
// 		v++;
// 	}
// }
// char	**alloc_map(int map_height, int map_width)
// {
//     char **map;
// 	// Allocate memory for the map
// 	map = (char **)malloc(map_height * sizeof(char *));
// 	if (map == NULL)
// 	{
// 		perror(ERROR_MEMORY);
// 		return (NULL);
// 	}
// 	for (size_t i = 0; i < map_height; i++)
// 	{
// 		map[i] = (char *)malloc((map_width + 1) * sizeof(char));
// 		if (map[i] == NULL)
// 		{
// 			perror(ERROR_MEMORY);
// 			// Free previously allocated memory
// 			for (size_t j = 0; j < i; j++)
// 			{
// 				free(map[j]);
// 			}
// 			free(map);
// 			return (NULL);
// 		}
// 	}
// }

// int measure_height(int fd)
// {
// 	char *line;
// 	int height;

// 	height = 0;
// 	line = get_next_line(fd);
// 	if (line_problem(line))
// 		return (0);
// 	while (line != NULL && *line != '\0')
// 	{
// 		// Reservo linea tal que int lo que sea
// 		// mientras haya height pues le meto un 
// 		free(line);
// 		height++;
// 		line = get_next_line(fd);
// 	}
// 	return height;
// }

// measure heigth
// measure width

int measure_map(char *file_name, Map *map)
{
	int fd;
	int height;
	size_t width;
	char *line;

	errno = EIO;
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return(perror(ERROR_OPEN), -1);
	height = 0;
	width = 0;
	line = get_next_line(fd);
	if (line_problem(line, fd))
		return(perror(ERROR_IRREGULAR), -1);
	while (line != NULL && *line != '\0')
	{
		if (line_problem(line, fd))
			return(perror(ERROR_IRREGULAR), -1);

		/*
		if (width == 0)
			width = ft_strlen(line);
		else if (ft_strlen(line) != width)
			return(perror(ERROR_EXTENSION), -1);
		*/
		height++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);

	map->height = height;
	map->width = width;
	return (0);
}

// breakpoint set --file measure_map.c --line 115
// watch examples on how to use next line

