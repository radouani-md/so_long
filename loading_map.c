	#include <stddef.h>
	#include <stdlib.h>
	#include <stdio.h>
	#include <fcntl.h>
	#include "so_long.h"

int calculate_num_of_lines(int fd)
{
	int num_lines;
	char *lines;

	num_lines = 0;
	while ((lines = get_next_line(fd)))
	{	
		free(lines);
		num_lines++;
	}
	lseek(fd, 0, SEEK_SET);
	return (num_lines);
}

char **load_map(const char *file, int *width, int *height)
	{
		t_game *game;
		int fd;
		char *line;
		int num_lines;
		int row;

		row = 0;
		fd = open(file, O_RDONLY);
		if (!fd)
		{
			printf("Error loading !!");
			exit(0);
		}
		num_lines = calculate_num_of_lines(fd);
		if (num_lines == 0)
    	{
			printf("Error: Map file is empty.\n");
			close(fd);
			exit(1);
    	}
		game->map = malloc((num_lines + 1) * sizeof(char *));
		if (!game->map)
		{
   			fprintf(stderr, "Error: Memory allocation failed for map.\n");
    		exit(EXIT_FAILURE);
			close(fd);
		}
		while ((line = get_next_line(fd)))
			game->map[row++] = line;
		game->map[row] = NULL;
		*height = row;
		*width = calculate_num_of_words(game);
		// check_map(game->map, *width, *height);
		close(fd);
		return (game->map);
	}
int calculate_num_of_words(t_game *game)
{
	int i;

	i = 0;
	size_t max_width = ft_strllen(game->map[0]);
	while (game->map[i])
	{
		if(max_width < ft_strllen(game->map[i]))
			max_width = ft_strllen(game->map[i]);
		i++;
	}
	return (max_width);
}
// int check_map(char **map, int width, int height)
// {
// 	t_game *game;

// 	if (check_cpe01(game->map, width, height))
// 	{
// 		printf("map is Valid!");
// 		return (1);
// 	}
// 	else
// 		printf("map not valid");
// 	return 0;
// }
