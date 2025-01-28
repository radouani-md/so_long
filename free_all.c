#include "so_long.h"

int handle_close(t_game *game)
{
    free_resources(game);
    exit(0);
}

void free_resources(t_game *game)
{
    if (game->space_img)
        mlx_destroy_image(game->mlx, game->space_img);
    if (game->wall_img)
        mlx_destroy_image(game->mlx, game->wall_img);
    if (game->collectible_img)
        mlx_destroy_image(game->mlx, game->collectible_img);
    if (game->exit_img)
        mlx_destroy_image(game->mlx, game->exit_img);
    if (game->player_img)
        mlx_destroy_image(game->mlx, game->player_img);
    if (game->win)
        mlx_destroy_window(game->mlx, game->win);
    if (game->mlx)
    {
        mlx_destroy_display(game->mlx);
        free(game->mlx);
    }
}
void ft_free(char **map)
{
    int i;

    i = 0;
    while(map[i])
        free(map[i++]);
    free(map);
    map = NULL;
}
