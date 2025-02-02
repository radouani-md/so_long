/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_player.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mradouan <mradouan@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-28 21:40:13 by mradouan          #+#    #+#             */
/*   Updated: 2025-01-28 21:40:13 by mradouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_direction(int keycode, t_game *game)
{
	if (keycode == 97)
		game->direction = 1;
	else if (keycode == 100)
		game->direction = 2;
	else if (keycode == 119)
		game->direction = 3;
	else if (keycode == 115)
		game->direction = 4;
}

void	player_position(t_game *game)
{
	int	i;
	int	j;

	j = 0;
	while (j < game->height)
	{
		i = 0;
		while (i < game->width)
		{
			if (game->map[j][i] == 'P')
			{
				game->player_x = i;
				game->player_y = j;
				break ;
			}
			i++;
		}
		j++;
	}
}
void	display_moves(t_game *game)
{
    char	*move_str;

    move_str = md_itoa(game->moves);
	draw_map(game);
    mlx_string_put(game->mlx, game->win, 10, 10, 0xFFFFFF, "Moves :");
    mlx_string_put(game->mlx, game->win, 60, 10, 0xFFFFFF, move_str);
    free(move_str);
}