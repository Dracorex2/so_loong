/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <lucmansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 16:10:42 by lucmansa          #+#    #+#             */
/*   Updated: 2025/03/11 16:49:23 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_putstr(int out, char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		write(out, &str[i], 1);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	unsigned int	nbr;

	if (nb < 0)
		ft_putchar('-');
	nbr = nb;
	if (nbr >= 10)
		ft_putnbr(nbr / 10);
	ft_putchar(nbr % 10 + 48);
}

void	*ft_realloc(void *ptr, size_t old_size, size_t new_size)
{
	void	*res;

	res = malloc(new_size);
	if (!res)
		return (free(ptr), NULL);
	if (old_size < new_size)
		ft_memcpy(res, ptr, old_size);
	else
		ft_memcpy(res, ptr, new_size);
	free(ptr);
	return (res);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*d;
	char	*s;

	if (n != 0 && src == 0 && dest == 0)
		return (NULL);
	d = (char *)dest;
	s = (char *)src;
	while (n--)
		d[n] = s[n];
	return (dest);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}