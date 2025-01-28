#include <stdio.h>
#include <stdlib.h>
#include "so_long.h"




void init_images(t_game *game)
{
    int img_width, img_height;

    game->wall_img = mlx_xpm_file_to_image(game->mlx, "file_util/wall.xpm", &img_width, &img_height);
    game->space_img = mlx_xpm_file_to_image(game->mlx, "file_util/free.xpm", &img_width, &img_height);
    game->collectible_img = mlx_xpm_file_to_image(game->mlx, "file_util/collectible.xpm", &img_width, &img_height);
    game->exit_img = mlx_xpm_file_to_image(game->mlx, "file_util/door.xpm", &img_width, &img_height);
    game->player_img = mlx_xpm_file_to_image(game->mlx, "file_util/player.xpm", &img_width, &img_height);

    if (!game->wall_img || !game->space_img || !game->collectible_img || !game->exit_img || !game->player_img)
    {
        write(1, "Error: Failed to load one or more .xpm files.\n", 46);
        free_resources(game);
        exit(EXIT_FAILURE);
    }
}

void handle_arguments(int argc)
{
    if (argc != 2)
    {
        write(1, "Unexpected Arguments! Please provide exactly one argument.\n", 59);
        exit(0);
    }
}

int initialize_game(t_game *game, char *map_path)
{
    game->map = load_map(map_path, &game->width, &game->height);
    if (!game->map)
    {
        write(1, "Error: Failed to load map\n", 26);
        free_resources(game);
        return (0);
    }
    game->collec_coin = count_collectible(game);
    if (!check_cpe01(game))
    {
        write(1, "Error: Invalid map. Exiting.\n", 29);
        return (0);
    }
}

void setup_graphics(t_game *game)
{
    game->mlx = mlx_init();
    if (!game->mlx)
    {
        free_resources(game);
        write(1, "Error: Failed to initialize MiniLibX\n", 37);
        exit(EXIT_FAILURE);
    }
    game->win = mlx_new_window(game->mlx, game->width * TILE_SIZE, game->height * TILE_SIZE, "/so_long/");
    if (!game->win)
    {
        write(1, "Error: Failed to create a window\n", 33);
        free_resources(game);
        exit(EXIT_FAILURE);
    }
}

void f()
{
    system("leaks my_game");
}

int main(int argc, char **argv)
{
    t_game game;

    atexit(f);
    handle_arguments(argc);
    if (!initialize_game(&game, argv[1]))
        return 0;
    setup_graphics(&game);

    init_images(&game);
    draw_map(&game);

    mlx_key_hook(game.win, get_move, &game);
    mlx_loop(game.mlx);
    free_resources(&game);
    return (EXIT_SUCCESS);
}
