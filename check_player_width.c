#include "so_long.h"

int check_two_player(t_game *game)
{
    int row;
    int col;
    int conter;

    row = 0;
    conter = 0;
    while (row < game->height)
    {
        col = 0;
        while (col < game->width)
        {
            if (game->map[row][col] == 'P' )
                conter++;
            col++;
        }
        row++;
    }
    if (conter > 1)
    {
        write(1, "Map invalid, You Have two or more Players\n", 42);
        return (0);
    }
    return (1);
}

int check_two_exit(t_game *game)
{
    int row;
    int col;
    int conter;

    row = 0;
    conter = 0;
    while (row < game->height)
    {
        col = 0;
        while (col < game->width)
        {
            if (game->map[row][col] == 'E')
                conter++;
            col++;
        }
        row++;
    }
    if (conter > 1)
    {
        write(1, "Map invalid, You Have two or more Exit\n", 39);
        return (0);
    }
    return (1);
}

int check_width(t_game *game)
{
    int row;
    size_t dfault;

    row = 0;
    dfault = ft_strlen(game->map[0]);
    while (game->map[row])
    {
        if (ft_strlen(game->map[row]) != dfault)
        {
            write(1, "Map invalid, you have deffernt width\n", 37);
            return (0);
        }
        row++;
    }
    return (1);
}
