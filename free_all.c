#include "so_long.h"

int handle_close(t_game *game)
{
    free_resources(game);
    exit(0);
}

void free_resources(t_game *game)
{
    int i = 0;
    while (game->map[i])
        free(game->map[i++]);
    free(game->map);
    mlx_destroy_window(game->mlx, game->win);
    mlx_destroy_display(game->mlx);
    mlx_destroy_image(game->mlx, game->space_img);
    mlx_destroy_image(game->mlx, game->wall_img);
    mlx_destroy_image(game->mlx, game->player_img);
    mlx_destroy_image(game->mlx, game->collectible_img);
    mlx_destroy_image(game->mlx, game->exit_img);
}
void ft_free(char **map)
{
    int i;

    i = 0;
    while(map[i])
        free(map[i++]);
    free(map);
}