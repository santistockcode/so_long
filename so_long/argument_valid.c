
#include "so_long.h"

int		is_map_empty(char *line, int fd);
int		fetch_map(char *file, char **map);
void	fetch_map_line(char **map, char *line, int h, size_t row);

int	is_map_empty(char *line, int fd)
{
	if (line == NULL)
	{
		close(fd);
		return (TRUE);
	}
	if (line[0] == '\0')
	{
		free(line);
		close(fd);
		return (TRUE);
	}
	return (FALSE);
}

void	fetch_map_line(char **map, char *line, int h, size_t row)
{
	int	v;

	v = 0;
	if (ft_strlen(line) != row)
		return (ft_printf(ERROR_EXTENSION));
	while (line[v] != '\0')
	{
		map[h][v] = line[v];
		v++;
	}
}
char	**map_alloc(void)
{
    char **map;
	// Allocate memory for the map
	map = (char **)malloc(map_height * sizeof(char *));
	if (map == NULL)
	{
		perror(ERROR_MEMORY);
		return (NULL);
	}
	for (size_t i = 0; i < map_height; i++)
	{
		map[i] = (char *)malloc((map_width + 1) * sizeof(char));
		if (map[i] == NULL)
		{
			perror(ERROR_MEMORY);
			// Free previously allocated memory
			for (size_t j = 0; j < i; j++)
			{
				free(map[j]);
			}
			free(map);
			return (NULL);
		}
	}
	// Initialize the map with null characters
	for (size_t i = 0; i < map_height; i++)
	{
		for (size_t j = 0; j < map_width; j++)
		{
			map[i][j] = '\0';
		}
		map[i][map_width] = '\0';
	}
}

int	fetch_map(char *file, char **map)
{
	int		fd;
	char	*line;
	int		counter_h;
	size_t	row;

	counter_h = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		perror(ERROR_OPEN);
		return (NULL);
	}
	line = get_next_line(fd);
	if (is_map_empty(line, fd))
		return (ft_printf(ERROR_EMPTY), (NULL)); // how do I free map here?
	while (line)
	{
		// is row same extension as every other row?
		fetch_map_line(map, line, counter_h, row);
		free(line);
		line = get_next_line(fd);
		counter_h++;
	}
	free(line);
	close(fd);
	return (counter_h);
}
