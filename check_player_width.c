/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_player_width.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mradouan <mradouan@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-28 22:33:48 by mradouan          #+#    #+#             */
/*   Updated: 2025-01-28 22:33:48 by mradouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_two_player(t_game *game)
{
	int	row;
	int	col;
	int	conter;

	row = 0;
	conter = 0;
	while (row < game->height)
	{
		col = 0;
		while (col < game->width)
		{
			if (game->map[row][col] == 'P' )
				conter++;
			col++;
		}
		row++;
	}
	if (conter > 1)
	{
		write(2, "Error :\nMap invalid, You Have two or more Players\n", 50);
		return (0);
	}
	return (1);
}

int	check_two_exit(t_game *game)
{
	int	row;
	int	col;
	int	conter;

	row = 0;
	conter = 0;
	while (row < game->height)
	{
		col = 0;
		while (col < game->width)
		{
			if (game->map[row][col] == 'E')
				conter++;
			col++;
		}
		row++;
	}
	if (conter > 1)
	{
		write(2, "Error:\n Map invalid, You Have two or more Exit\n", 47);
		return (0);
	}
	return (1);
}

int	check_width(t_game *game)
{
	int		row;
	size_t	dfault;

	row = 0;
	dfault = ft_strlen(game->map[0]);
	while (game->map[row])
	{
		if (ft_strlen(game->map[row]) != dfault)
		{
			write(1, "Error:\n Map invalid, you have deffernt width\n", 45);
			return (0);
		}
		row++;
	}
	return (1);
}

int	check_close(t_game *game)
{
	int	row;
	int	col;

	if (!game || !game->map)
		return (0);
	col = 0;
	while (col < game->width)
	{
		if (game->map[0][col] != '1' || game->map[game->height - 1][col] != '1')
			return (0);
		col++;
	}
	row = 0;
	while (row < game->height)
	{
		if (game->map[row][0] != '1' || game->map[row][game->width - 1] != '1')
			return (0);
		row++;
	}
	return (1);
}

int	size_icron(t_game *game)
{
	if (game->height > 31)
	{
		write (2, "Error:\n The height is too long than Pc height\n", 46);
		return (0);
	}
	if (game->width > 57)
	{
		write (2, "Error:\n The height is too long than Pc width\n", 45);
		return (0);
	}
	return (1);
}
