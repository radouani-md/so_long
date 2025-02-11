/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mradouan <mradouan@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-28 21:14:16 by mradouan          #+#    #+#             */
/*   Updated: 2025-01-28 21:14:16 by mradouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	free_img(t_game *game)
{
	if (game->space_img)
		mlx_destroy_image(game->mlx, game->space_img);
	if (game->enemy_img_down)
		mlx_destroy_image(game->mlx, game->enemy_img_down);
	if (game->enemy_img_up)
		mlx_destroy_image(game->mlx, game->enemy_img_up);
	if (game->enemy_img_left)
		mlx_destroy_image(game->mlx, game->enemy_img_left);
	if (game->enemy_img_right)
		mlx_destroy_image(game->mlx, game->enemy_img_right);
	if (game->wall_img)
		mlx_destroy_image(game->mlx, game->wall_img);
	if (game->collectible_img)
		mlx_destroy_image(game->mlx, game->collectible_img);
	if (game->exit_img)
		mlx_destroy_image(game->mlx, game->exit_img);
	if (game->player_img)
		mlx_destroy_image(game->mlx, game->player_img);
}

void	free_resources(t_game *game)
{
	free_img(game);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	if (game->enemies)
		free(game->enemies);
}

void	ft_free(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (map[i])
		free(map[i++]);
	free(map);
	map = NULL;
}
