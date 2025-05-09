/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mradouan <mradouan@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-28 21:42:15 by mradouan          #+#    #+#             */
/*   Updated: 2025-01-28 21:42:15 by mradouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print(char c)
{
	write(1, &c, 1);
}

void	md_put_number(int nb)
{
	if (nb > 9)
	{
		md_put_number(nb / 10);
		md_put_number(nb % 10);
	}
	else
	{
		print(nb + 48);
	}
}

void	md_print_nb(int nb)
{	
	write(1, "{Step ", 6);
	md_put_number(nb);
	write(1, "}\n", 2);
}

int	close_window(t_game *game)
{
	free_resources(game);
	ft_free(game->map);
	get_next_line(-1);
	write(1, "Map is Closed. Do you feel boring !!", 36);
	exit(0);
}
