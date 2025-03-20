/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <lucmansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 08:13:25 by lucmansa          #+#    #+#             */
/*   Updated: 2025/03/20 18:28:06 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_object(char c, char *charset)
{
	int	i;

	i = -1;
	while (charset[++i])
	{
		if (charset[i] == c)
			return (1);
	}
	return (0);
}

int	is_rectangle(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	while (++y < game->m.height)
	{
		x = -1;
		while (game->m.map[y][++x])
		{
			if (!is_object(game->m.map[y][x], "01PECO"))
				return (0);
		}
		if (x != game->m.width - 1)
			return (0);
	}
	return (1);
}

int	has_border(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	x = -1;
	while (game->m.map[y][++x])
		if (game->m.map[y][x] != '1')
			return (0);
	while (++y < game->m.height - 1)
		if (game->m.map[y][0] != '1'
			|| game->m.map[y][game->m.width - 1] != '1')
			return (0);
	x = -1;
	while (game->m.map[y][++x])
		if (game->m.map[y][x] != '1')
			return (0);
	return (1);
}

int	has_player(t_game *game)
{
	int	x;
	int	y;
	int	p;

	p = 0;
	y = -1;
	while (++y < game->m.height)
	{
		x = -1;
		while (++x < game->m.width)
		{
			if (game->m.map[y][x] == 'P')
			{
				game->m.map[y][x] = '0';
				game->p.x = x;
				game->p.y = y;
				p++;
			}
		}
	}
	if (p != 1)
		return (0);
	return (1);
}

int	has_element(t_game *game)
{
	int	x;
	int	y;
	int	exit;

	y = -1;
	exit = 0;
	game->m.coin_count = 0;
	while (++y < game->m.height)
	{
		x = -1;
		while (++x < game->m.width)
		{
			if (game->m.map[y][x] == 'C')
				game->m.coin_count++;
			if (game->m.map[y][x] == 'E')
				exit++;
		}
	}
	if (!game->m.coin_count || exit != 1)
		return (0);
	return (1);
}
