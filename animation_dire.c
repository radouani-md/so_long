#include "so_long.h"

void get_direction(t_game *game, int img_width, int img_height)
{
	if (game->player_img)
		mlx_destroy_image(game->mlx, game->player_img);
	if (game->direction == 1) // Left
	{
		game->player_img = mlx_xpm_file_to_image(game->mlx, "file_util/left1.xpm",
			&img_width, &img_height);
	}
	else if (game->direction == 2) // Right
	{
		game->player_img = mlx_xpm_file_to_image(game->mlx, "file_util/right1.xpm",
			&img_width, &img_height);
	}
	else if (game->direction == 3) // Up
	{
		game->player_img = mlx_xpm_file_to_image(game->mlx, "file_util/up1.xpm",
			&img_width, &img_height);
	}
	else if (game->direction == 4) // Down
	{
		game->player_img = mlx_xpm_file_to_image(game->mlx, "file_util/nor1.xpm",
			&img_width, &img_height);
	}
}
// int	animate_enemy(t_game *game)
// {
// 	static int frame_count = 0;
// 	frame_count++;
// 	if (frame_count >= 500) // Change every 20 frames
// 	{
// 		if (game->enemy_img == game->enemy_img_left)
// 			game->enemy_img = game->enemy_img_right;
// 		else
// 			game->enemy_img = game->enemy_img_left;
// 		draw_map(game); // Redraw map with the updated enemy image
// 		frame_count = 0;
// 	}
// 	return (1);
// }