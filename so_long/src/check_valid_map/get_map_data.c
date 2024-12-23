/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalarco <saalarco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 13:19:41 by saalarco          #+#    #+#             */
/*   Updated: 2024/12/23 20:02:33 by saalarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"


// static int check_has_walls(t_file *file)
// {
//     size_t i;
//     size_t len;

//     len = file->lines[0].length;
//     i = 0;
//     while (i < file->lines[0].length)
//     {
//         if(file->lines[0].text[i] != '1' || file->lines[file->line_count - 1].text[i] != '1')
//             return (FALSE);
//         i++;
//     }
//     i = 0;
//     while (i < file->line_count)
//     {
//         if (file->lines[i].text[0] != '1' || file->lines[i].text[len - 1] != '1')
//             return (FALSE);
//         i++;
//     }
//     return (TRUE);

// }

// static int check_is_rectangle(t_map_data *map_data)
// {
//     int i;
//     int len;

//     len = ft_strlen(map_data->map[0]);
//     if (len <= 2)
//         return (FALSE);
//     i = 0;
//     while (i < map_data->height)
//     {
//         if ((int) ft_strlen(map_data->map[i]) != len)
//             return (FALSE);
//         i++;
//     }
//     return (TRUE);
// }


// static int OLD_check_is_rectangle(t_file *file)
// {
//     size_t i;
//     size_t len;

//     len = file->lines[0].length;
//     i = 0;
//     while (i < file->line_count)
//     {
//         if (i == file->line_count - 1)
//         {
//             if (file->lines[i].text[file->lines[i].length - 1] == '\n' && file->lines[i].length != len)
//                 return (FALSE);
//             else if (file->lines[i].text[file->lines[i].length - 1] != '\n' && file->lines[i].length != len - 1)
//                 return (FALSE);
//         }
//         else if (file->lines[i].length != len)
//             return (FALSE);
//         i++;
//     }
//     return (TRUE);
// }

t_map_data *get_map_data(t_file *file)
{
    t_map_data *map_data;

    map_data = NULL;
    if (file->line_count >= 3)
    {
        map_data = (t_map_data *)malloc(sizeof(t_map_data));
        if (map_data == NULL)
            return (NULL);
        map_data->map = ft_split(file->buffer, '\n');
        map_data->height = file->line_count;
        if (map_data->map == NULL)
        {
            free(map_data);
            return (NULL);
        }
    }
    return (map_data);
}