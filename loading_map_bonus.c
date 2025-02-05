/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loading_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mradouan <mradouan@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-28 21:05:24 by mradouan          #+#    #+#             */
/*   Updated: 2025-01-28 21:05:24 by mradouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	continue_calculate(int num_lines, int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		if (line && line[0] == '\n')
		{
			free(line);
			return (0);
		}
		num_lines++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	return (num_lines);
}

int	calculate_num_of_lines(const char *file)
{
	int		num_lines;
	char	*line;
	int		fd;

	fd = open(file, O_RDONLY);
	if (is_ber(file) == 0 || is_not_directory(file) == 0 || fd < 0)
	{
		write(2, "Error:\n uplaod .BER Or DIR , Error loading\n", 43);
		exit(0);
	}
	num_lines = 0;
	line = get_next_line(fd);
	if (line && line[0] == '\n')
	{
		free(line);
		return (0);
	}
	else if (!line)
		return (0);
	num_lines++;
	free(line);
	num_lines = continue_calculate(num_lines, fd);
	return (close(fd), num_lines);
}

size_t	calculate_num_of_words(char **map)
{
	int		i;
	size_t	max;
	size_t	line_length;

	i = 0;
	max = ft_strlen(map[0]);
	while (map[i])
	{
		line_length = ft_strlen(map[i]);
		if (max < line_length)
			max = line_length;
		i++;
	}
	return (max);
}

char	**fill_map(char **map, int fd)
{
	char	*line;
	int		row;
	size_t	len;

	row = 0;
	line = get_next_line(fd);
	while (line)
	{
		len = ft_strlen(line);
		if (line[len - 1] == '\n')
			line[len - 1] = '\0';
		map[row++] = line;
		line = get_next_line(fd);
	}
	map[row] = NULL;
	return (map);
}

char	**load_map(const char *file, int *width, int *height)
{
	char	**map;
	int		fd;
	int		num_lines;

	map = NULL;
	num_lines = calculate_num_of_lines(file);
	if (num_lines == 0)
		return (write(2, "Error:\n file is Empty or has newlines\n", 38), NULL);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (write(2, "Error:\n loading !!", 18), NULL);
	map = allocate(map, num_lines, fd);
	if (!map)
		return (NULL);
	map = fill_map(map, fd);
	close(fd);
	if (!map)
		return (NULL);
	*width = calculate_num_of_words(map);
	*height = num_lines;
	return (map);
}
