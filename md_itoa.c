/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mradouan <mradouan@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-02 13:45:50 by mradouan          #+#    #+#             */
/*   Updated: 2025-02-02 13:45:50 by mradouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	get_length(int n)
{
	int	len;

	len = 1;
	if (n < 0)
		len++;
	while (n / 10 != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*md_itoa(int n)
{
	char	*result;
	int		len;
	long	num;

	num = n;
	len = get_length(n);
	result = (char *)malloc(len + 1);
	if (!result)
		return (NULL);
	result[len] = '\0';
	if (num < 0)
	{
		result[0] = '-';
		num = -num;
	}
	while (len-- > 0)
	{
		if (result[len] == '-')
			break ;
		result[len] = (num % 10) + '0';
		num /= 10;
	}
	return (result);
}
