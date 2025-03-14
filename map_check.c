/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <lucmansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 16:07:51 by lucmansa          #+#    #+#             */
/*   Updated: 2025/03/14 17:58:57 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

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
			if (x >= game->m.width || !is_object(game->m.map[y][x], "01PEC"))
				return (0);
		}
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
			if (game->m.map[y][x] == 'P')
			{
				game->m.map[y][x] = '0';
				game->p.x = x;
				game->p.y = y;
				p++;
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

char **map_cpy(t_game *game)
{
	char	**cpy;
	int		y;
	
	cpy = malloc((game->m.height + 1) * sizeof(char *));
	y = -1;
	while (++y < game->m.height)
	{
		cpy[y] = malloc(game->m.width * sizeof(char));
		ft_memcpy(cpy[y], game->m.map[y], game->m.width);
	}
	cpy[y] = NULL;
	return (cpy);
}

int	flood_fill(char **map, int y, int x)
{
	int	res;
	
	if (map[y][x] == '1')
		return (0);
	res = 0;
	if (map[y][x] == 'C' || map[y][x] == 'E')
		res += 1;
	map[y][x] = '1';
	res += flood_fill(map, y, x - 1);
	res += flood_fill(map, y, x + 1);
	res += flood_fill(map, y - 1, x);
	res += flood_fill(map, y + 1, x);
	return (res);
}

int	map_checker(t_game *game)
{
	char **map;

	if (!is_rectangle(game))
		return (0);
	if (!has_border(game))
		return (0);
	if (!has_player(game))
		return (0);
	if (!has_element(game))
		return (0);
	map = map_cpy(game);
	if (flood_fill(map, game->p.y, game->p.x)
		!= game->m.coin_count + 1)
	{
		return (0);
		free_map(map);
	}
	free_map(map);
	return (1);
}
