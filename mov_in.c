/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mradouan <mradouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 21:31:35 by mradouan          #+#    #+#             */
/*   Updated: 2025/02/02 11:29:26 by mradouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_position(t_game *game, int new_x, int new_y)
{
	mlx_put_image_to_window(game->mlx, game->win, game->space_img,
		game->player_x * TILE_SIZE, game->player_y * TILE_SIZE);
	mlx_put_image_to_window(game->mlx, game->win, game->player_img,
		new_x * TILE_SIZE, new_y * TILE_SIZE);
	game->map[game->player_y][game->player_x] = '0';
	game->map[new_y][new_x] = 'P';
	game->player_x = new_x;
	game->player_y = new_y;
	display_moves(game);
}

int	handle_special_tiles(t_game *game, int new_x, int new_y)
{
	if (game->map[new_y][new_x] == 'C')
	{
		game->collec_coin--;
		game->map[new_y][new_x] = '0';
	}
	if (game->map[new_y][new_x] == 'E')
	{
		if (game->collec_coin > 0)
			return (0);
		write(1, "\nCONGRATS You Win !\n", 20);
		ft_free(game->map);
		free_resources(game);
		exit(0);
	}
	if (game->map[new_y][new_x] == 'M')
	{
		write(1, "\nGAME OVER !! Try Again\n", 24);
		ft_free(game->map);
		free_resources(game);
		exit(0);
	}
	return (1);
}

int	is_valid_move(int new_x, int new_y, t_game *game)
{
	return (!(new_x < 0 || new_y < 0 || new_x >= game->width
			|| new_y >= game->height || game->map[new_y][new_x] == '1'));
}

void	new_posi(int keycode, int *new_x, int *new_y, t_game *game)
{
	set_direction(keycode, game);
	if (keycode == 97)
		(*new_x)--;
	else if (keycode == 100)
		(*new_x)++;
	else if (keycode == 119)
		(*new_y)--;
	else if (keycode == 115)
		(*new_y)++;
	else if (keycode == 65307)
	{
		ft_free(game->map);
		free_resources(game);
		exit(0);
	}
}

int	get_move(int keycode, t_game *game, int img_width, int img_height)
{
	int			new_x;
	int			new_y;
	static int	d = 1;

	img_width = 0;
	img_height = 0;
	new_x = game->player_x;
	new_y = game->player_y;
	player_position(game);
	new_posi(keycode, &new_x, &new_y, game);
	if (!is_valid_move(new_x, new_y, game))
		return (0);
	if (game->map[new_y][new_x] == '0' ||
	game->map[new_y][new_x] == 'C' ||
	(game->map[new_y][new_x] == 'E' && game->collec_coin == 0))
	{
		game->moves++;
		md_put_number(d++);
	}
	if (handle_special_tiles(game, new_x, new_y))
	{
		get_direction(game, img_width, img_height);
		update_position(game, new_x, new_y);
	}
	return (0);
}
