/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_valid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mradouan <mradouan@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-28 21:17:21 by mradouan          #+#    #+#             */
/*   Updated: 2025-01-28 21:17:21 by mradouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_valid_char(char cell)
{
	return (cell == 'E' || cell == 'C' || cell == 'P'
		|| cell == '1' || cell == '0' || cell == 'M');
}

int	validate_characters(t_game *game)
{
	int		x;
	int		y;
	char	cell;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			cell = game->map[y][x];
			if (cell == '\0')
			{
				x++;
				continue ;
			}
			if (!is_valid_char(cell))
				return (write(2, "Error: Invalid character", 24));
			x++;
		}
		y++;
	}
	return (1);
}

int	check_cpe01(t_game *game)
{
	if (!validate_characters(game))
		return (0);
	if (!has_required_elements(game))
	{
		write(2, "Error: Map must contain at least one ECP10\n", 43);
		return (0);
	}
	if (!check_two_player(game) || !check_two_exit(game))
		return (0);
	if (!check_width(game))
		return (0);
	if (!check_close(game))
	{
		write(2, "Map is Not Closed !!\n", 21);
		return (0);
	}
	if (!validate_map(game))
		return (0);
	return (1);
}

int	is_not_directory(const char *file)
{
	int	fd;

	fd = open(file, O_RDONLY | __O_DIRECTORY);
	if (fd == -1)
		return (1);
	close(fd);
	return (0);
}

int	is_ber(const char *filename)
{
	const char	*extension;
	size_t		len_extension;
	size_t		len_filename;

	extension = ".ber";
	len_filename = ft_strlen(filename);
	len_extension = ft_strlen(extension);
	if (len_filename < len_extension)
		return (0);
	if (ft_strcmp(filename + len_filename - len_extension, extension) != 0)
		return (0);
	if (len_filename == len_extension
		|| filename[len_filename - len_extension - 1] == '.')
		return (0);
	return (1);
}
