#include "so_long.h"
#include <stdio.h>

// int cheek_rectoungle(int *width, int *height)
// {
//     if (height > width)
//     {
//         write(1, "Map is Not in a rectangle shape !!", 34);
//         exit(0);
//     }
// }
int check_cpe01(int width, int height, t_game *game)
{
    int x;
    int y;
    char cell;

    y = 0;
    while (y < height)
    {
        x = 0;
        while (x < width)
        {
            cell = game->map[y][x];
            if (cell != 'E' && cell != 'C' && cell != '1' &&
                cell != '0' && cell != 'P')
            {
                printf("Error: Invalid character '%c' at (%d, %d)\n", cell, y, x);
                return 0;
            }
            x++;
        }
        y++;
    }
        return 1;
}