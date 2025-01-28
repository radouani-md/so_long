/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mradouan <mradouan@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-28 22:30:59 by mradouan          #+#    #+#             */
/*   Updated: 2025-01-28 22:30:59 by mradouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_tile(t_game *game, int row, int col)
{
	void	*img;

	img = NULL;
	if (game->map[row][col] == '1')
		img = game->wall_img;
	else if (game->map[row][col] == '0')
		img = game->space_img;
	else if (game->map[row][col] == 'C')
	{
		img = game->collectible_img;
		game->collec_coin++;
	}
	else if (game->map[row][col] == 'E')
		img = game->exit_img;
	else if (game->map[row][col] == 'P')
		img = game->player_img;
	if (img)
		mlx_put_image_to_window(game->mlx, game->win, img,
			col * TILE_SIZE, row * TILE_SIZE);
}

void	draw_map_row(t_game *game, int row)
{
	int	col;

	col = 0;
	while (col < game->width)
	{
		if (game->map[row][col] != '\0')
			draw_tile(game, row, col);
		col++;
	}
}

void	draw_map(t_game *game)
{
	int	row;

	row = 0;
	game->collec_coin = 0;
	while (row < game->height)
	{
		draw_map_row(game, row);
		row++;
	}
}
