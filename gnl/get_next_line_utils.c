/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 12:19:44 by lucmansa          #+#    #+#             */
/*   Updated: 2024/11/26 19:07:06 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strchr(char *s, char c)
{
	int	i;

	i = 0;
	if (!s)
		return (-1);
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	if (s[i] == c)
		return (i);
	return (-1);
}

void	ft_strlcpy(char *dst, char *src, size_t size)
{
	size_t	i;

	i = -1;
	if (size)
	{
		while ((src[++i] != 0) && (i < size - 1))
			dst[i] = src[i];
		dst[i] = '\0';
	}
}

char	*ft_strjoin(char *s1, char *s2, int n)
{
	char	*res;
	int		len;
	int		i;

	i = 0;
	if (!s1)
	{
		res = ft_calloc(sizeof(char), n + 1);
		ft_strlcpy(res, s2, n + 1);
		return (res);
	}
	len = ft_strchr(s1, '\0') + n;
	res = ft_calloc(sizeof(char), len + 1);
	if (!res)
		return (free(s1), NULL);
	ft_strlcpy(res, s1, ft_strchr(s1, '\0') + 1);
	while (res[i])
		i++;
	ft_strlcpy(&res[i], s2, n + 1);
	free(s1);
	return (res);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*i;
	size_t	j;

	i = malloc(nmemb * size);
	if (!i)
		return (NULL);
	j = -1;
	while (++j < nmemb * size)
		i[j] = 0;
	return (i);
}
