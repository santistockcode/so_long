# [`get_map`] Module

The [`get_map`]module is responsible for handling map-related functionalities in the [`so_long`]project. This includes reading, parsing, validating, and managing the game maps.

## Files

- [`free_parsed_map.c`](./../src/get_map/free_parsed_map.c): Contains the function to free the memory allocated for a parsed map.
- [`parse_map.c`](./../src/get_map/parse_map.c): Contains the function to parse a map from a file.
- [`validate_map_contents.c`](./../src/get_map/validate_map_contents.c): Contains the function to validate the contents of a parsed map.
- [`validate_map_playable.c`](./../src/get_map/validate_map_playable.c): Contains the function to validate if a map is playable.
- [`flood_fill.c`](./../src/get_map/flood_fill.c): Contains the flood fill algorithm used for map validation.

## Functions

### [`free_parsed_map`]

Defined in [`free_parsed_map.c`](src/get_map/free_parsed_map.c).

```c
void free_parsed_map(t_parsed_map *map);
```

Frees the memory allocated for a parsed map.

### `parse_map`

Defined in [`parse_map.c`](src/get_map/parse_map.c).

```c
t_parsed_map *parse_map(t_file *file);
```

Parses a map from a file and returns a [`t_parsed_map`] structure.

### [`validate_map_contents`]

Defined in [`validate_map_contents.c`](src/get_map/validate_map_contents.c).

```c
int validate_map_contents(t_parsed_map *map);
```

Validates the contents of a parsed map. Returns `1` if the map is valid, otherwise `0`.

### `validate_map_playable`

Defined in [`validate_map_playable.c`](src/get_map/validate_map_playable.c).

```c
int validate_map_playable(t_parsed_map *map);
```

Validates if a map is playable. Returns `1` if the map is playable, otherwise `0`.

### `flood_fill`

Defined in [`flood_fill.c`](src/get_map/flood_fill.c).

```c
void flood_fill(char **map, unsigned int x, unsigned int y);
```

Uses the flood fill algorithm to mark reachable areas in the map.

## Usage

To use the functions provided by the `get_map` module, include the necessary headers in your source file:

```c
#include "get_map.h"
```

Then, you can call the functions as needed to read, parse, validate, and manage game maps.

## Example

Here is an example of how to use the [`get_map`] module to read and validate a map:

```c
#include "get_map.h"

int main() {
    int fd = open("path/to/map.ber", O_RDONLY);
    t_file *file = ft_file_read_all(fd);
    close(fd);

    if (!file) {
        // Handle error
        return 1;
    }

    t_parsed_map *map = parse_map(file);
    ft_file_free(&file);

    if (!map) {
        // Handle error
        return 1;
    }

    int is_valid = validate_map_contents(map);
    int is_playable = validate_map_playable(map);

    if (is_valid && is_playable) {
        // Map is valid and playable
    } else {
        // Handle invalid or non-playable map
    }

    free_parsed_map(map);
    return 0;
}
```

This example demonstrates how to open a map file, read its contents, parse the map, validate it, and check if it is playable. Finally, it frees the allocated memory for the parsed map.