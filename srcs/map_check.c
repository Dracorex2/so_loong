/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <lucmansa@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 16:07:51 by lucmansa          #+#    #+#             */
/*   Updated: 2025/03/18 08:14:22 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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
		return (0);
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
		return (free_map(map), 0);
	free_map(map);
	return (1);
}
