#include "so_long.h"
int count_collectible(t_game *game)
{
    int row;
    int col;
    int count;

    row = 0;
    count = 0;
    while (row < game->height)
    {
        col = 0;
        while (col < game->width)
        {
            if (game->map[row][col] == 'C')
                count++;
            col++;
        }
        row++;
    }
    return (count);
}

void find_position(t_game *game, int *px, int *py)
{
    int x;
    int y;

    y = 0;
    while (y < game->height)
    {
        x = 0;

        while (x < game->width)
        {
            if (game->map[y][x] == 'P') 
            {
                *px = x;
                *py = y;
                return ;
            }
            x++;
        }
        y++;
    }
}

void flood_file(t_game *game, char **copy_map, int x, int y, int *collectble, int *exit_here)
{
    if (x < 0 || y < 0 || y >= game->height || x >= game->width)
        return ;
    if (copy_map[y][x] == '1' || copy_map[y][x] == 'F')
        return ;
    if (copy_map[y][x] == 'C')
        (*collectble)++;
    if (copy_map[y][x] == 'E')
        *exit_here = 1;
    copy_map[y][x] = 'F';
    flood_file(game, copy_map, x + 1, y, collectble, exit_here);
    flood_file(game, copy_map, x - 1, y, collectble, exit_here);
    flood_file(game, copy_map, x, y + 1, collectble, exit_here);
    flood_file(game, copy_map, x, y - 1, collectble, exit_here);
}
int validate_map(t_game *game)
{
    int collectibles;
    int exit_here;
    char **copy_map;
    int i;

    collectibles = 0;
    exit_here = 0;
    i = 0;
    copy_map = malloc((game->height + 1) * sizeof(char *));
    while (game->map[i])
    {
        copy_map[i] = ft_strdup(game->map[i]);
        i++;
    }
    copy_map[i] = NULL;
    find_position(game, &game->player_x, &game->player_y);
    flood_file(game, copy_map, game->player_x, game->player_y, &collectibles, &exit_here);
    ft_free(copy_map);
    if (collectibles == game->collec_coin && exit_here)
        return (1);
    if (collectibles != game->collec_coin)
        write(1, "Error: Map validation failed (No collectibles).\n", 48);
    write(1, "Error: Map validation failed (No Exit found).\n", 46);
    return (0);
}
