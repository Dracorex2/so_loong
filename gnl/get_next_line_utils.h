/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <lucmansa@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 18:46:56 by lucmansa          #+#    #+#             */
/*   Updated: 2025/03/17 18:52:52 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_UTILS_H

# define GET_NEXT_LINE_UTILS_H
# include <unistd.h>
# include <stdlib.h>

# endif

char	*ft_strjoin(char *s1, char *s2, int n);
void	ft_strlcpy(char *dst, char *src, size_t size);
char	*get_next_line(int fd);
int		ft_strchr(char *s, char c);
void	*ft_calloc(size_t nmemb, size_t size);

#endif