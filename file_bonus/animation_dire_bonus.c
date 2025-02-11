/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_dire.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mradouan <mradouan@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-02 13:48:43 by mradouan          #+#    #+#             */
/*   Updated: 2025-02-02 13:48:43 by mradouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	helper_get(t_game *game, int img_width, int img_height)
{
	if (game->direction == 1)
	{
		game->player_img = mlx_xpm_file_to_image(game->mlx,
				"textures/left1.xpm", &img_width, &img_height);
	}
	else if (game->direction == 2)
	{
		game->player_img = mlx_xpm_file_to_image(game->mlx,
				"textures/right1.xpm", &img_width, &img_height);
	}
	else if (game->direction == 3)
	{
		game->player_img = mlx_xpm_file_to_image(game->mlx,
				"textures/up1.xpm", &img_width, &img_height);
	}
	else if (game->direction == 4)
	{
		game->player_img = mlx_xpm_file_to_image(game->mlx,
				"textures/nor1.xpm", &img_width, &img_height);
	}
}

void	get_direction(t_game *game, int img_width, int img_height)
{
	if (game->player_img)
		mlx_destroy_image(game->mlx, game->player_img);
	helper_get(game, img_width, img_height);
	if (!game->player_img)
	{
		write(1, "Error\n Failed to load .xpm\n", 27);
		free_resources(game);
		exit(0);
	}
}

void	help_animate(int frame_count, t_game *game)
{
	int	i;

	i = 0;
	if (frame_count % 10000 == 0)
	{
		while (i < game->count_enemy)
		{
			move_enemy(game, &game->enemies[i]);
			i++;
		}
	}
}

int	animate_enemy(t_game *game)
{
	static int	frame_count = 0;

	if (frame_count >= 18000)
	{
		if (game->enemy_img == game->enemy_img_up)
			game->enemy_img = game->enemy_img_down;
		else if (game->enemy_img == game->enemy_img_down)
			game->enemy_img = game->enemy_img_right;
		else if (game->enemy_img == game->enemy_img_right)
			game->enemy_img = game->enemy_img_left;
		else
			game->enemy_img = game->enemy_img_up;
		redraw_enemy(game);
		frame_count = 0;
	}
	help_animate(frame_count, game);
	frame_count++;
	return (1);
}
