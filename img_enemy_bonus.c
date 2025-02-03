/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_enemy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mradouan <mradouan@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-03 20:46:21 by mradouan          #+#    #+#             */
/*   Updated: 2025-02-03 20:46:21 by mradouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	enemy_img(t_game *game, int img_width, int img_height)
{
	game->enemy_img = NULL;
	game->enemy_img_down = mlx_xpm_file_to_image(game->mlx,
			"textures/enemy.xpm", &img_width, &img_height);
	game->enemy_img_up = mlx_xpm_file_to_image(game->mlx,
			"textures/enemy_back.xpm", &img_width, &img_height);
	game->enemy_img_left = mlx_xpm_file_to_image(game->mlx,
			"textures/enemy_left.xpm", &img_width, &img_height);
	game->enemy_img_right = mlx_xpm_file_to_image(game->mlx,
			"textures/enemy_right.xpm", &img_width, &img_height);
	game->enemy_img = game->enemy_img_up;
}

void	redraw_enemy(t_game *game)
{
	int		row;
	int		col;

	row = 0;
	while (row < game->height)
	{
		col = 0;
		while (col < game->width)
		{
			if (game->map[row][col] == 'M')
			{
				mlx_put_image_to_window(game->mlx, game->win, game->space_img,
					col * TILE_SIZE, row * TILE_SIZE);
				mlx_put_image_to_window(game->mlx, game->win, game->enemy_img,
					col * TILE_SIZE, row * TILE_SIZE);
			}
			col++;
		}
		row++;
	}
}
