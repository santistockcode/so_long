#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100
#define TRUE 1
#define FALSE 0

char map[MAX_SIZE][MAX_SIZE];
int visited[MAX_SIZE][MAX_SIZE];
int rows, cols;

void flood_fill(int x, int y, char target, char replacement) {
    if (x < 0 || x >= rows || y < 0 || y >= cols) return;
    if (map[x][y] == '1' || visited[x][y]) return;

    visited[x][y] = TRUE;
    if (map[x][y] == target) {
        map[x][y] = replacement;
    }

    flood_fill(x + 1, y, target, replacement);
    flood_fill(x - 1, y, target, replacement);
    flood_fill(x, y + 1, target, replacement);
    flood_fill(x, y - 1, target, replacement);
}

int main() {
    int start_x, start_y;
    FILE *file = fopen("map.txt", "r");
    if (!file) {
        perror("Failed to open map.txt");
        return EXIT_FAILURE;
    }

    // Read the map dimensions
    rows = 0;
    while (fgets(map[rows], MAX_SIZE, file)) {
        map[rows][strcspn(map[rows], "\n")] = '\0'; // Remove newline character
        rows++;
    }
    cols = strlen(map[0]);
    fclose(file);

    // Initialize visited array
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            visited[i][j] = FALSE;
        }
    }

    // Print the initial map
    printf("Initial map:\n");
    for (int i = 0; i < rows; i++) {
        printf("%s\n", map[i]);
    }

    // Read the starting position
    printf("Enter starting position (x y): ");
    scanf("%d %d", &start_x, &start_y);

    // Validate starting position
    if (start_x < 0 || start_x >= rows || start_y < 0 || start_y >= cols) {
        printf("Invalid starting position.\n");
        return EXIT_FAILURE;
    }

    // Check if the starting position is '0'
    if (map[start_x][start_y] != '0') {
        printf("Starting position is not '0'.\n");
        return EXIT_FAILURE;
    }

    // Perform flood fill
    flood_fill(start_x, start_y, 'C', 'F');

    // Check if all 'C' cells are reachable
    int all_reachable = TRUE;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (map[i][j] == 'C' && !visited[i][j]) {
                all_reachable = FALSE;
                break;
            }
        }
    }

    // Print the result
    if (all_reachable) {
        printf("All 'C' cells are reachable.\n");
    } else {
        printf("Not all 'C' cells are reachable.\n");
    }

    // Print the map after flood fill
    printf("Map after flood fill:\n");
    for (int i = 0; i < rows; i++) {
        printf("%s\n", map[i]);
    }

    return 0;
}