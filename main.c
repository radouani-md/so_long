#include "mlx/mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include "so_long.h"

int main() {
    t_game *game;

    int tile = TILE_SIZE;

    game->map = load_map("file_util/map.ber", &game->map_width, &game->map_height, game);
    game->collectibles = 0;
    int y = 0;
    while (y < game->map_height) {
        int x = 0;
        while (x < game->map_width) {
            if (game->map[y][x] == 'C') {
                game->collectibles++;
            }
            x++;
        }
        y++;
    }

    // Initialize MiniLibX
    game->mlx = mlx_init();
    game->win = mlx_new_window(game->mlx, game->map_width * TILE_SIZE, game->map_height * TILE_SIZE, "2D Game");

    // Load images
    game->wall_img = mlx_xpm_file_to_image(game->mlx, "wall.xpm", &tile, &tile);
    game->player_img = mlx_xpm_file_to_image(game->mlx, "player.xpm", &tile, &tile);
    game->collectible_img = mlx_xpm_file_to_image(game->mlx, "collectible.xpm", &tile, &tile);
    game->rouad_img = mlx_xpm_file_to_image(game->mlx, "freewhite.xpm", &tile, &tile);
    game->exit_img = mlx_xpm_file_to_image(game->mlx, "exit2.xpm", &tile, &tile);

    if (!game->wall_img || !game->player_img || !game->collectible_img || !game->rouad_img || !game->exit_img) {
    fprintf(stderr, "Error: Failed to load one or more images.\n");
    return (1);
    }    
    // Draw the initial map
    draw_map(game);
     

    // Hook key events
    mlx_key_hook(game->win, get_move, &game);
    mlx_loop(game->mlx);

    return 0;
}

