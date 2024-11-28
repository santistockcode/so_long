#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ERROR_MEMORY "Memory allocation error"

// Function to measure the height and width of the file content
void measure_dimensions(FILE *file, int *height, int *width)
{
    *height = 0;
    *width = 0;
    int current_width = 0;
    char ch;

    while ((ch = fgetc(file)) != EOF)
    {
        if (ch == '\n')
        {
            (*height)++;
            if (current_width > *width)
            {
                *width = current_width;
            }
            current_width = 0;
        }
        else
        {
            current_width++;
        }
    }
    if (current_width > 0)
    {
        (*height)++;
        if (current_width > *width)
        {
            *width = current_width;
        }
    }
}

// Function to allocate memory for the map
char **alloc_map(int map_height, int map_width)
{
    char **map = (char **)malloc(map_height * sizeof(char *));
    if (map == NULL)
    {
        perror(ERROR_MEMORY);
        return NULL;
    }

    for (int i = 0; i < map_height; i++)
    {
        map[i] = (char *)malloc((map_width + 1) * sizeof(char));
        if (map[i] == NULL)
        {
            perror(ERROR_MEMORY);
            for (int j = 0; j < i; j++)
            {
                free(map[j]);
            }
            free(map);
            return NULL;
        }
    }
    return map;
}

// Function to populate the map with the content from the file
void populate_map(FILE *file, char **map)
{
    int h = 0, v = 0;
    char ch;

    while ((ch = fgetc(file)) != EOF)
    {
        if (ch == '\n')
        {
            map[h][v] = '\0';
            h++;
            v = 0;
        }
        else
        {
            map[h][v++] = ch;
        }
    }
    if (v > 0)
    {
        map[h][v] = '\0';
    }
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    int height, width;
    measure_dimensions(file, &height, &width);
    fclose(file);

    char **map = alloc_map(height, width);
    if (map == NULL)
    {
        return EXIT_FAILURE;
    }

    file = fopen(argv[1], "r");
    if (file == NULL)
    {
        perror("Error opening file");
        for (int i = 0; i < height; i++)
        {
            free(map[i]);
        }
        free(map);
        return EXIT_FAILURE;
    }

    populate_map(file, map);
    fclose(file);

    // Use the map...

    // Free allocated memory
    for (int i = 0; i < height; i++)
    {
        free(map[i]);
    }
    free(map);

    return EXIT_SUCCESS;
}