/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <lucmansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 16:07:51 by lucmansa          #+#    #+#             */
/*   Updated: 2025/03/20 16:27:31 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_enemies(t_game *game)
{
	int	y;
	int	x;

	y = -1;
	while (++y < game->m.height)
	{
		x = -1;
		while (++x < game->m.width)
		{
			if (!BONUS_MODE && game->m.map[y][x] == 'O')
				game->m.map[y][x] = '0';
			if (game->m.map[y][x] == 'O')
			{
				if (game->m.map[y + 1][x] == '1' && game->m.map[y - 1][x] == '1'
					&& game->m.map[y][x + 1] == '1'
					&& game->m.map[y][x - 1] == '1')
					return (0);
			}
		}
	}
	return (1);
}

char	**map_cpy(t_game *game)
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
	char	**map;

	if (!game->m.map[0])
		return (write(2, "Map is empty\n", 13), 0);
	if (!is_rectangle(game))
		return (write(2, "Map not rectangle\n", 18), 0);
	if (!has_border(game))
		return (write(2, "Missing border\n", 15), 0);
	if (!has_player(game))
		return (write(2, "Missing player\n", 15), 0);
	if (!has_element(game))
		return (write(2, "Missing collectible or exit\n", 28), 0);
	if (!check_enemies(game))
		return (write(2, "Enemie stuck\n", 13), 0);
	map = map_cpy(game);
	if (flood_fill(map, game->p.y, game->p.x)
		!= game->m.coin_count + 1)
		return (write(2, "Collectible or exit is not accessible\n", 38)
			, free_map(map), 0);
	free_map(map);
	return (1);
}
