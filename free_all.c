#include "so_long.h"

int handle_close(t_game *game)
{
    free_resources(game);
    exit(0);
}

void free_resources(t_game *game)
{
    if (game->map) {
        int i = 0;
        while (game->map[i])
            free(game->map[i++]);
        free(game->map);
    }
    if (game->win)
        mlx_destroy_window(game->mlx, game->win);
    if (game->mlx)
        mlx_destroy_display(game->mlx);
    if (game->mlx) 
    {
        mlx_destroy_image(game->mlx, game->space_img);
        mlx_destroy_image(game->mlx, game->wall_img);
        mlx_destroy_image(game->mlx, game->player_img);
        mlx_destroy_image(game->mlx, game->collectible_img);
        mlx_destroy_image(game->mlx, game->exit_img);
    }
}