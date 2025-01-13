
#ifndef SO_LONG_H
# define SO_LONG_H
#define WALL '1'
#define EMPTY '0'
#define COLLECTIBLE 'C'
#define EXIT 'E'
#define PLAYER 'P'
#define PLAYER_SIZE 64
#include "mlx/mlx.h"
#include "get_file_next/get.h"

#define TILE_SIZE 64

typedef struct s_game {
    void    *mlx;
    void    *win;
    void    *wall_img;
	void	*rouad_img;
    void    *player_img;
    void    *collectible_img;
    void    *exit_img;
    char    **map;
    int     player_x;
    int     player_y;
    int     map_width;
    int     map_height;
    int     collectibles;
} t_game;

char **load_map(const char *file, int *width, int *height, t_game *game);
int calculate_num_of_words(t_game *game);
void draw_map(t_game *game);
int get_move(int keycode, t_game *game);
int check_map(char **map, int width, int height);
int cheek_rectoungle(int *width, int *height);
int check_cpe01(int width, int height, t_game *game);

#endif