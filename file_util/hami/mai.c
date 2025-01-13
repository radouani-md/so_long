
#include <mlx.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

#define TILE_SIZE 32
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

typedef struct s_game {
    void    *mlx;
    void    *win;
    char    **map;
    int     player_x;
    int     player_y;
    int     map_width;
    int     map_height;
} t_game;

void error_exit(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

char **read_map(const char *filename, t_game *game) {
    int fd = open(filename, O_RDONLY);
    if (fd < 0)
        error_exit("Error opening map file");

    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    char **map = malloc(sizeof(char *) * 100); // Adjust size if needed
    if (!map)
        error_exit("Memory allocation error");

    int row = 0;
    while ((read = getline(&line, &len, fdopen(fd, "r"))) != -1) {
        map[row] = strdup(line);
        map[row][strcspn(map[row], "\n")] = '\0'; // Remove newline
        row++;
    }
    close(fd);
    free(line);

    game->map_height = row;
    game->map_width = strlen(map[0]);
    return map;
}

void render_map(t_game *game) {
    for (int y = 0; y < game->map_height; y++) {
        for (int x = 0; x < game->map_width; x++) {
            if (game->map[y][x] == '1')
                mlx_string_put(game->mlx, game->win, x * TILE_SIZE, y * TILE_SIZE, 0xFFFFFF, "#"); // Wall
            else if (game->map[y][x] == 'P') {
                mlx_string_put(game->mlx, game->win, x * TILE_SIZE, y * TILE_SIZE, 0xFF0000, "P"); // Player
                game->player_x = x;
                game->player_y = y;
            }
            else if (game->map[y][x] == 'C')
                mlx_string_put(game->mlx, game->win, x * TILE_SIZE, y * TILE_SIZE, 0x00FF00, "C"); // Collectible
            else if (game->map[y][x] == 'E')
                mlx_string_put(game->mlx, game->win, x * TILE_SIZE, y * TILE_SIZE, 0x0000FF, "E"); // Exit
        }
    }
}

int key_press(int keycode, t_game *game) {
    if (keycode == 53) {
        mlx_destroy_window(game->mlx, game->win);
        exit(0);
    }
    return 0;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <map_file.ber>\n", argv[0]);
        return EXIT_FAILURE;
    }

    t_game game;
    game.mlx = mlx_init();
    if (!game.mlx)
        error_exit("Failed to initialize MLX");

    game.win = mlx_new_window(game.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "So Long");
    if (!game.win)
        error_exit("Failed to create window");

    game.map = read_map(argv[1], &game);
    render_map(&game);

    mlx_key_hook(game.win, key_press, &game);
    mlx_loop(game.mlx);

    return 0;
}
