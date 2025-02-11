/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   didacted_enemy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mradouan <mradouan@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-11 14:23:59 by mradouan          #+#    #+#             */
/*   Updated: 2025-02-11 14:23:59 by mradouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	update_enemy(t_game *game, t_enemy *enemy, int new_x)
{
	game->map[enemy->enemy_y][enemy->enemy_x] = '0';
	game->map[enemy->enemy_y][new_x] = 'M';
	if (new_x == game->player_x && enemy->enemy_y == game->player_y)
	{
		write(2, "Game Over, The Enemy has Killed you\n", 36);
		free_resources(game);
		ft_free(game->map);
		exit(0);
	}
	mlx_put_image_to_window(game->mlx, game->win,
		game->space_img, enemy->enemy_x * TILE_SIZE,
		enemy->enemy_y * TILE_SIZE);
	enemy->enemy_x = new_x;
	mlx_put_image_to_window(game->mlx, game->win,
		game->enemy_img, enemy->enemy_x * TILE_SIZE,
		enemy->enemy_y * TILE_SIZE);
}

void	move_enemy(t_game *game, t_enemy *enemy)
{
	int	new_x;

	new_x = enemy->enemy_x;
	if (enemy->enemy_dir == -1)
	{
		if (game->map[enemy->enemy_y][enemy->enemy_x - 1] != '1'
			&& game->map[enemy->enemy_y][enemy->enemy_x - 1] != 'C'
			&& game->map[enemy->enemy_y][enemy->enemy_x - 1] != 'M'
			&& game->map[enemy->enemy_y][enemy->enemy_x - 1] != 'E')
			new_x--;
		else
			enemy->enemy_dir = 1;
	}
	else if (enemy->enemy_dir == 1)
	{
		if (game->map[enemy->enemy_y][enemy->enemy_x + 1] != '1'
			&& game->map[enemy->enemy_y][enemy->enemy_x + 1] != 'C'
			&& game->map[enemy->enemy_y][enemy->enemy_x + 1] != 'M'
			&& game->map[enemy->enemy_y][enemy->enemy_x + 1] != 'E')
			new_x++;
		else
			enemy->enemy_dir = -1;
	}
	update_enemy(game, enemy, new_x);
}

void	find_enemy(t_game *game)
{
	int	i;
	int	j;
	int	p;

	p = 0;
	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if (game->map[i][j] == 'M')
			{
				game->enemies[p].enemy_x = j;
				game->enemies[p].enemy_y = i;
				game->enemies[p].enemy_dir = 1;
				p++;
			}
			j++;
		}
		i++;
	}
}
