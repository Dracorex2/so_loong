/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemies.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <lucmansa@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 22:54:49 by lucmansa          #+#    #+#             */
/*   Updated: 2025/03/19 23:04:25 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	move_up(t_game *game, int y, int x)
{
	if (game->m.map[y + 1][x] == '0')
	{
		game->m.map[y + 1][x] = 'o';
		game->m.map[y][x] = '0';
		return (1);
	}
	return (0);
}

int	move_down(t_game *game, int y, int x)
{
	if (game->m.map[y - 1][x] == '0')
	{
		game->m.map[y - 1][x] = 'o';
		game->m.map[y][x] = '0';
		return (1);
	}
	return (0);
}

int	move_left(t_game *game, int y, int x)
{
	if (game->m.map[y][x - 1] == '0')
	{
		game->m.map[y][x - 1] = 'o';
		game->m.map[y][x] = '0';
		return (1);
	}
	return (0);
}

int	move_right(t_game *game, int y, int x)
{
	if (game->m.map[y][x + 1] == '0')
	{
		game->m.map[y][x + 1] = 'o';
		game->m.map[y][x] = '0';
		return (1);
	}
	return (0);
}
