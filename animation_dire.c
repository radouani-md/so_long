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

#include "so_long.h"

void	get_direction(t_game *game, int img_width, int img_height)
{
	if (game->player_img)
		mlx_destroy_image(game->mlx, game->player_img);
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
