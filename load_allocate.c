/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_allocate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mradouan <mradouan@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-28 21:12:09 by mradouan          #+#    #+#             */
/*   Updated: 2025-01-28 21:12:09 by mradouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**allocate(char **map, int num_lines, int fd)
{
	map = malloc((num_lines + 1) * sizeof(char *));
	if (!map)
	{
		write(2, "Error:\n Memory allocation failed for map.\n", 42);
		close(fd);
		return (NULL);
	}
	return (map);
}
