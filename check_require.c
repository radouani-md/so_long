#include "so_long.h"
int check_e(t_game *game)
{
    int row;
    int col;

    row = 0;
    while (row < game->height)
    {
        col = 0;
        while (col < game->width)
        {
            if (game->map[row][col] == 'E')
                return (1);
            col++;
        }
        row++;
    }
    return (0);
}

int check_c(t_game *game)
{
    int row;
    int col;

    row = 0;
    while (row < game->height)
    {
        col = 0;
        while (col < game->width)
        {
            if (game->map[row][col] == 'C')
                return (1);
            col++;
        }
        row++;
    }
    return (0);
}

int check_p(t_game *game)
{
    int row;
    int col;

    row = 0;
    while (row < game->height)
    {
        col = 0;
        while (col < game->width)
        {
            if (game->map[row][col] == 'P')
                return (1);
            col++;
        }
        row++;
    }
    return (0);
}

int check_one_zero(t_game *game)
{
    int row;
    int col;

    row = 0;
    while (row < game->height)
    {
        col = 0;
        while (col < game->width)
        {
            if (game->map[row][col] == '1' || game->map[row][col] == '0')
                return (1);
            col++;
        }
        row++;
    }
    return (0);
}

int has_required_elements(t_game *game)
{
    if (check_e(game) && check_c(game) && check_p(game) && check_one_zero(game))
        return (1);
    return (0);
}