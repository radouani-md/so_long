/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mradouan <mradouan@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-03 21:53:36 by mradouan          #+#    #+#             */
/*   Updated: 2025-02-03 21:53:36 by mradouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_BONUS_H
# define GET_BONUS_H

# include <unistd.h>
# include <stdlib.h>

# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 999
# endif

char	*get_next_line(int fd);
size_t	ft_strlen(char const *str);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
int		ft_strcmp(const char *s1, const char *s2);

#endif