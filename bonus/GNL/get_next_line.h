/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aammisse <aammisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:04:42 by aammisse          #+#    #+#             */
/*   Updated: 2025/01/25 17:49:32 by aammisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# ifndef SIZE_MAX
#  define SIZE_MAX 18446744073709551615
# endif

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stddef.h>

char	*get_next_line(int fd);
char	*ft_strdup(const char *s1);
char	*ft_calloc(size_t num, size_t size);
char	*ft_strjoin(char *s1, const char *s2);
size_t	ft_getstrlen(const char *s);

#endif