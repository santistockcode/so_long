
#include "so_long.h"

int is_extension_correct(char *file);
int is_map_empty(char *file);

int is_extension_correct(char *file)
{
    int len;

    len = ft_strlen(file);

    if (file[len - 1] == 'r' &&
    file[len - 2] == 'e' &&
    file[len - 3] == 'b' && 
    file[len - 4] == '.')
    {
        return (TRUE);
    }
    else 
        return (FALSE);
}

int is_map_empty(char *file)
{
    int fd;
    char    *line;
    
    fd = open(file, O_RDONLY);
    if (fd == -1) {
        perror(ERROR_OPEN);
        return EXIT_FAILURE;
    }

    line = get_next_line(fd);
    if (line == NULL) {
        close(fd);
        return TRUE;
    }

    if (line[0] == '\0') {
        free(line);
        close(fd);
        return TRUE;
    }

    free(line);
    close(fd);
    return FALSE;
}