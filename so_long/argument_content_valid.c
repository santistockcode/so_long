
#include "so_long.h"

// int	is_no_line(char *line, int fd);
// void	fetch_map_line(char **map, char *line, int h, size_t row);
int measure_height(int fd);
void measure_map_and_alloc(char **file);

int	line_problem(char *line)
{
	if (line == NULL)
	{
		return (TRUE);
	}
	if (line[0] == '\0')
	{
		free(line);
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

int measure_height(int fd)
{
	char *line;
	int height;

	height = 0;
	line = get_next_line(fd);
	if (line_problem(line))
		return (0);
	while (line != NULL && *line != '\0')
	{
		free(line);
		height++;
		line = get_next_line(fd);
	}
	return height;
}

void measure_map_and_alloc(char **file)
{
	char **map;
	int fd;
	size_t column_size;
	size_t row_size;
	char *line;

	fd = open(*file, O_RDONLY);
	if (fd == -1)
	{
		perror(ERROR_OPEN);
		// return (NULL);
	}
	column_size = measure_height(fd);
	if (column_size == 0)
	{
		close(fd);
		return;
	}
	// return (map);
}
