#include "so_long.h"

int get_move(int keycode, t_game *game) 
{
    int new_x = game->player_x;
    int new_y = game->player_y;

    if (keycode == 65361 || keycode == 97)
        new_x--;
    else if (keycode == 65363 || keycode == 100)
        new_x++;
    else if (keycode == 65362 || keycode == 119)
        new_y--;
    else if (keycode == 65364 || keycode == 115)
        new_y++;
    else if (keycode == 65307)
        exit(0);

    if (game->map[new_y][new_x] != '1' && game->map[new_y][new_x] != '\0' && game->map[new_y][new_x] != '\n')
    {
        if (game->map[new_y][new_x] == 'C')
            game->collectibles--;
        if (game->collectibles > 0 && game->map[new_y][new_x] == 'E')
            return 0;
        if (game->collectibles == 0 && game->map[new_y][new_x] == 'E') {
            write(1, "You win!\n", 9);
            exit(0);
        }

        mlx_put_image_to_window(game->mlx, game->win, game->rouad_img, game->player_x * TILE_SIZE, game->player_y * TILE_SIZE);
        mlx_put_image_to_window(game->mlx, game->win, game->player_img, new_x * TILE_SIZE, new_y * TILE_SIZE);
        game->map[game->player_y][game->player_x] = '0';
        game->map[new_y][new_x] = 'P';
        game->player_x = new_x;
        game->player_y = new_y;
    }

    return 0;
}
