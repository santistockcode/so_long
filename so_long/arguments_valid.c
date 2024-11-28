#include "so_long.h"

// Function to check file extension
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