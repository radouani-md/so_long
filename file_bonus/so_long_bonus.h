/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mradouan <mradouan@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-28 22:16:08 by mradouan          #+#    #+#             */
/*   Updated: 2025-01-28 22:16:08 by mradouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# ifndef PLAYER_SIZE
#  define PLAYER_SIZE 64
# endif

# ifndef TILE_SIZE
#  define TILE_SIZE 64
# endif

# include "/home/mradouan/Desktop/include/mlx/mlx.h"
# include <unistd.h>
# include "../get_file_next/get.h"
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct s_enemy
{
	int	enemy_x;
	int	enemy_y;
	int	enemy_dir;
}	t_enemy;

typedef struct s_game
{
	t_enemy	*enemies;
	void	*mlx;
	void	*win;
	char	**map;
	char	**copy_map;
	int		width;
	int		height;
	int		player_x;
	int		player_y;
	int		collec_coin;
	void	*enemy_img;
	void	*wall_img;
	void	*space_img;
	void	*collectible_img;
	void	*exit_img;
	void	*player_img;
	void	*enemy_img_left;
	void	*enemy_img_right;
	void	*enemy_img_up;
	void	*enemy_img_down;
	int		is_yes;
	int		enemy_frame;
	int		count_enemy;
	int		moves;
	int		direction;
}	t_game;

typedef struct s_flood
{
	int	collectibles;
	int	exit_found;
}	t_flood;

int		check_two_exit(t_game *game);
char	**load_map(const char *file, int *width, int *height);
void	draw_map(t_game *game);
int		check_cpe01(t_game *game);
char	*get_next_line(int fd);
int		is_not_directory(const char *file);
int		is_ber(const char *filename);
int		has_required_elements(t_game *game);
int		check_two_player(t_game *game);
int		check_width(t_game *game);
int		calculate_num_of_lines(const char *file);
int		get_move(int keycode, t_game *game, int img_width, int img_height);
void	player_position(t_game *game);
void	free_resources(t_game *game);
int		check_close(t_game *game);
int		validate_map(t_game *game);
int		count_collectible(t_game *game);
void	ft_free(char **map);
void	md_print_nb(int nb);
int		close_window(t_game *game);
char	**allocate(char **map, int num_lines, int fd);
char	*md_itoa(int n);
void	display_moves(t_game *game);
void	get_direction(t_game *game, int img_width, int img_height);
void	set_direction(int keycode, t_game *game);
int		animate_enemy(t_game *game);
void	enemy_img(t_game *game, int img_width, int img_height);
void	redraw_enemy(t_game *game);
int		size_icron(t_game *game);
void	count_emys(t_game *game);
void	find_enemy(t_game *game);
void	move_enemy(t_game *game, t_enemy *enemy);

#endif