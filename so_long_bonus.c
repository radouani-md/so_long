/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mradouan <mradouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 21:23:19 by mradouan          #+#    #+#             */
/*   Updated: 2025/02/02 11:41:17 by mradouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	init_images(t_game *game)
{
	int	img_width;
	int	img_height;

	game->wall_img = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm",
			&img_width, &img_height);
	game->space_img = mlx_xpm_file_to_image(game->mlx, "textures/free.xpm",
			&img_width, &img_height);
	game->collectible_img = mlx_xpm_file_to_image(game->mlx,
			"textures/collectible.xpm", &img_width, &img_height);
	game->exit_img = mlx_xpm_file_to_image(game->mlx, "textures/door.xpm",
			&img_width, &img_height);
	enemy_img(game, img_width, img_height);
	game->enemy_frame = 0;
	game->player_img = NULL;
	game->direction = 2;
	get_direction(game, img_width, img_height);
	if (!game->wall_img || !game->space_img || !game->collectible_img
		|| !game->exit_img || !game->player_img || !game->enemy_img)
	{
		write(2, "Error: Failed to load one or more .xpm files.\n", 46);
		free_resources(game);
		ft_free(game->map);
		exit(0);
	}
}

void	handle_arguments(int argc)
{
	if (argc != 2)
	{
		write(2, "Unexpected Arguments! Please provide one argument.\n", 51);
		exit(0);
	}
}

int	initialize_game(t_game *game, char *map_path)
{
	game->map = load_map(map_path, &game->width, &game->height);
	if (!game->map)
	{
		write(2, "Error: Failed to load map\n", 26);
		ft_free(game->map);
		return (0);
	}
	game->moves = 0;
	game->collec_coin = count_collectible(game);
	if (!check_cpe01(game))
	{
		write(2, "Error: Invalid map. Exiting.\n", 29);
		ft_free(game->map);
		return (0);
	}
	return (1);
}

void	setup_graphics(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		free_resources(game);
		ft_free(game->map);
		write(2, "Error: Failed to initialize MiniLibX\n", 37);
		exit(0);
	}
	game->win = mlx_new_window(game->mlx, game->width * TILE_SIZE,
			game->height * TILE_SIZE, "/so_long/");
	if (!game->win)
	{
		write(2, "Error: Failed to create a window\n", 33);
		free_resources(game);
		ft_free(game->map);
		exit(0);
	}
}

int	main(int argc, char **argv)
{
	t_game	game;

	handle_arguments(argc);
	if (!initialize_game(&game, argv[1]))
		return (0);
	setup_graphics(&game);
	init_images(&game);
	draw_map(&game);
	mlx_key_hook(game.win, get_move, &game);
	mlx_hook(game.win, 17, 0, close_window, &game);
	mlx_loop_hook(game.mlx, animate_enemy, &game);
	mlx_loop(game.mlx);
	return (0);
}
