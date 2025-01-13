#include "so_long.h"

void draw_map(t_game *game)
{
    int y;
    int x;

    y = 0;
    while (y < game->map_height)
    {
        x = 0;
        while (x < game->map_width)
        {
            int px = x * TILE_SIZE;
            int py = y * TILE_SIZE;

            if (game->map[y][x] == '1' || game->map[y][x] == '\n' || game->map[y][x] == '\0')
                mlx_put_image_to_window(game->mlx, game->win, game->wall_img, px, py);
            else if (game->map[y][x] == 'C')
                mlx_put_image_to_window(game->mlx, game->win, game->collectible_img, px, py);
            else if (game->map[y][x] == 'E')
                mlx_put_image_to_window(game->mlx, game->win, game->exit_img, px, py);
            else if (game->map[y][x] == '0')
                mlx_put_image_to_window(game->mlx, game->win, game->rouad_img, px, py);
            else if (game->map[y][x] == 'P') {
                game->player_x = x;
                game->player_y = y;
                mlx_put_image_to_window(game->mlx, game->win, game->player_img, px, py);
            }
            x++;
        }
        y++;
    }
}