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

// int	update_animation(t_game *game)
// {
// 	static int frame_counter = 0;

// 	if (frame_counter++ > 10) // Change frame every 10 loops
// 	{
// 		game->current_frame = (game->current_frame + 1) % 4;
// 		game->player_img = game->py_frame[game->current_frame]; // Update the displayed frame
// 		frame_counter = 0;
// 	}
// 	mlx_put_image_to_window(game->mlx, game->win, game->space_img, game->player_x * 32, game->player_y * 32); // Clear old position
// 	mlx_put_image_to_window(game->mlx, game->win, game->player_img, game->player_x * 32, game->player_y * 32); // Draw new frame
// 	return (0);
// }