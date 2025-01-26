#include "so_long.h"
void player_position(t_game *game)
{
    int i;
    int j;

    j = 0;
     while (j < game->height)
    {
        i = 0;
        while (i < game->width)
        {
            if (game->map[j][i] == 'P')
            {
                game->player_x = i;
                game->player_y = j;
                break;
            }
            i++;
        }
        j++;
    }
}