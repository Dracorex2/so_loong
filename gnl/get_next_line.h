/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <lucmansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 12:19:27 by lucmansa          #+#    #+#             */
/*   Updated: 2025/03/11 16:47:13 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*ft_strjoin(char *s1, char *s2, int n);
void	ft_strlcpy(char *dst, char *src, size_t size);
char	*get_next_line(int fd);
int		ft_strchr(char *s, char c);
void	*ft_calloc(size_t nmemb, size_t size);

#endif