/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <lucmansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 16:11:37 by lucmansa          #+#    #+#             */
/*   Updated: 2025/03/11 16:52:24 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <unistd.h>
# include <signal.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

void	ft_putstr(int out, char *str);
void	ft_putchar(char c);
void	ft_putnbr(int nb);
void	*ft_realloc(void *ptr, size_t old_size, size_t new_size);
void	*ft_memcpy(void *dest, const void *src, size_t n);
size_t	ft_strlen(const char *str);

#endif