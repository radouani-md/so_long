/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mradouan <mradouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 11:23:42 by mradouan          #+#    #+#             */
/*   Updated: 2024/12/11 11:33:00 by mradouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get.h"

static char	*check_read(int fd, char *buffer, char *static_v)
{
	char	*joined;
	ssize_t	read_bytes;

	while (1)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes <= 0)
			break ;
		buffer[read_bytes] = '\0';
		joined = ft_strjoin(static_v, buffer);
		if (!joined)
			return (free(buffer), free(static_v), NULL);
		static_v = joined;
		if (ft_strchr(static_v, '\n'))
			break ;
	}
	return (static_v);
}

static char	*get_next(char *static_v)
{
	char	*new_buffer;
	int		i;

	i = 0;
	while (static_v[i])
	{
		if (static_v[i] == '\n')
			break ;
		i++;
	}
	if (!static_v[i])
		return (free(static_v), NULL);
	new_buffer = ft_strdup(static_v + i + 1);
	free(static_v);
	return (new_buffer);
}

static char	*get_the_line(char *static_v)
{
	int		i;
	char	*str;

	i = 0;
	if (!static_v[i])
		return (NULL);
	while (static_v[i] && static_v[i] != '\n')
		i++;
	if (static_v[i] == '\0')
		str = (char *)malloc(sizeof(char) * (i + 1));
	else
		str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (static_v[i] && static_v[i] != '\n')
	{
		str[i] = static_v[i];
		i++;
	}
	if (static_v[i] == '\n')
		str[i++] = '\n';
	str[i] = '\0';
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*static_v;
	char		*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
	{
		free(static_v);
		static_v = NULL;
		return (NULL);
	}
	buffer = malloc((size_t)BUFFER_SIZE + 1);
	if (!buffer)
	{
		free(static_v);
		static_v = NULL;
		return (NULL);
	}
	static_v = check_read(fd, buffer, static_v);
	free(buffer);
	if (!static_v)
		return (free(static_v), NULL);
	line = get_the_line(static_v);
	static_v = get_next(static_v);
	return (line);
}
