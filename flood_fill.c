/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mradouan <mradouan@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-28 22:27:24 by mradouan          #+#    #+#             */
/*   Updated: 2025-01-28 22:27:24 by mradouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_collectible(t_game *game)
{
	int	row;
	int	col;
	int	count;

	row = 0;
	count = 0;
	while (row < game->height)
	{
		col = 0;
		while (col < game->width)
		{
			if (game->map[row][col] == 'C')
				count++;
			col++;
		}
		row++;
	}
	return (count);
}

void	find_position(t_game *game, int *px, int *py)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->map[y][x] == 'P')
			{
				*px = x;
				*py = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

void	flood_file(t_game *game, int x, int y, t_flood *flood)
{
	if (x < 0 || y < 0 || y >= game->height || x >= game->width)
		return ;
	if (game->copy_map[y][x] == '1' || game->copy_map[y][x] == 'F')
		return ;
	if (game->copy_map[y][x] == 'C')
		flood->collectibles++;
	if (game->copy_map[y][x] == 'E')
		flood->exit_found = 1;
	game->copy_map[y][x] = 'F';
	flood_file(game, x + 1, y, flood);
	flood_file(game, x - 1, y, flood);
	flood_file(game, x, y + 1, flood);
	flood_file(game, x, y - 1, flood);
}

int	check_copy_map(t_game *game, int i)
{
	if (!game->copy_map[i])
	{
		while (i > 0)
			free(game->copy_map[--i]);
		free(game->copy_map);
		return (0);
	}
	return (1);
}

int	validate_map(t_game *game)
{
	t_flood	flood;
	int		i;

	flood.collectibles = 0;
	flood.exit_found = 0;
	i = 0;
	game->copy_map = malloc((game->height + 1) * sizeof(char *));
	if (!game->copy_map)
		return (0);
	while (game->map[i])
	{
		game->copy_map[i] = ft_strdup(game->map[i]);
		if (!check_copy_map(game, i))
			return (0);
		i++;
	}
	game->copy_map[i] = NULL;
	find_position(game, &game->player_x, &game->player_y);
	flood_file(game, game->player_x, game->player_y, &flood);
	ft_free(game->copy_map);
	if (flood.collectibles == game->collec_coin && flood.exit_found)
		return (1);
	if (flood.collectibles != game->collec_coin)
		write(2, "Error:\n Map validation failed (No Coins).\n", 42);
	return (write(2, "Error: Map validation failed (No Exit found).\n", 46), 0);
}
