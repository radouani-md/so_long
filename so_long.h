
#ifndef SO_LONG_H
# define SO_LONG_H
#define PLAYER_SIZE 64
#define TILE_SIZE 64
#include "/home/mradouan/Desktop/include/mlx/mlx.h"
#include <unistd.h>
#include "get_file_next/get.h"
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

#include <string.h>

typedef struct s_game 
{
    void    *mlx;
    void    *win;
    char    **map;
    int     width;
    int     height;
    int     player_x;
    int     player_y;
    int     collec_coin;
    void    *wall_img;
    void    *space_img;
    void    *collectible_img;
    void    *exit_img;
    void    *player_img;
} t_game;

int check_two_exit(t_game *game);
char **load_map(const char *file, int *width, int *height);
void draw_map(t_game *game);
int check_cpe01(t_game *game);
char	*get_next_line(int fd);
int is_not_directory(const char *file);
int is_ber(const char *filename);
int has_required_elements(t_game *game);
int check_two_player(t_game *game);
int check_width(t_game *game);
int calculate_num_of_lines(const char *file);
int get_move(int keycode, t_game *game);
void player_position(t_game *game);
void free_resources(t_game *game);
int check_close(t_game *game);
int validate_map(t_game *game);
int count_collectible(t_game *game);
void ft_free(char **map);
#endif