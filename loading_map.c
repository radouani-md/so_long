#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include "so_long.h"

int continue_calculate(int num_lines, int fd)
{
    char *line;

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
    free(line); //! 
    return (num_lines);
}

int calculate_num_of_lines(const char *file)
{
    int num_lines;
    char *line;
	int fd;

	fd = open(file, O_RDONLY);
	if(is_ber(file) == 0 || is_not_directory(file) == 0 || fd < 0)
	{
		write(1, "Error uplaod .BER Or DIR , Error loading\n", 41);
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

size_t calculate_num_of_words(char **map)
{
    int i;
    size_t max;
    size_t line_length ;

    i = 0;
    max = ft_strlen(map[0]);
    while (map[i])
    {
        line_length = ft_strlen(map[i]);
        // if (map[i][line_length - 1] == '\n')
        //     line_length--;
        if (max < line_length)
            max = line_length;
        i++;
    }
    return (max);
}

char **allocate(char **map, int num_lines, int fd)
{
	map = malloc((num_lines + 1) * sizeof(char *));
	if (!map)
	{
		fprintf(stderr, "Error\nMemory allocation failed for map.\n");
		close(fd);
        free(map); //! 
		return (NULL);
	}
	return (map);
}

char **fill_map(char **map, int fd)
{
    char *line;
    int row;
	size_t len;

    row = 0;
	line = get_next_line(fd);
    while (line)
    {
        len = ft_strlen(line);
        if (line[len - 1] == '\n')
            line[len - 1] = '\0';
        map[row++] = ft_strdup(line);
        free(line);
		line = get_next_line(fd);   
    }
    // free(line); //!
    map[row] = NULL;
    return (map);
}

char **load_map(const char *file, int *width, int *height)
{
	char **map;
	int fd;
	int num_lines;

	map = NULL;
	num_lines = calculate_num_of_lines(file);
	if (num_lines == 0)
		return (write(1, "The file is Empty or has newlines\n", 34),NULL);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (printf("Error loading !!"), NULL);
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
