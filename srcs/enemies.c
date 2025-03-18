/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <lucmansa@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 21:08:20 by lucmansa          #+#    #+#             */
/*   Updated: 2025/03/18 22:45:48 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <stdlib.h>
#include <time.h>

int	randint(int i)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	srand(t.tv_sec + t.tv_usec);
	return ((int)(rand() * 1.0 / RAND_MAX * (i)));
}

void	reset_enemies(t_game *game)
{
	int	y;
	int	x;

	y = -1;
	while (++y < game->m.height)
	{
		x = -1;
		while (++x < game->m.width)
		{
			if (game->m.map[y][x] == 'o')
				game->m.map[y][x] = 'O';
		}
	}
}

void	try_move(t_game *game, int y, int x)
{
	int	r;

	while (1)
	{
		r = randint(5);
		if (r == 1)
		{
			if (game->m.map[y + 1][x] == '0')
			{
				game->m.map[y + 1][x] = 'o';
				game->m.map[y][x] = '0';
				break ;
			}
		}
		if (r == 2)
		{
			if (game->m.map[y][x + 1] == '0')
			{
				game->m.map[y][x + 1] = 'o';
				game->m.map[y][x] = '0';
				break ;
			}
		}
		if (r == 3)
		{
			if (game->m.map[y - 1][x] == '0')
			{
				game->m.map[y - 1][x] = 'o';
				game->m.map[y][x] = '0';
				break ;
			}
		}
		if (r == 4)
		{
			if (game->m.map[y][x - 1] == '0')
			{
				game->m.map[y][x - 1] = 'o';
				game->m.map[y][x] = '0';
				break ;
			}
		}
	}
}

void	move_enemies(t_game *game)
{
	int	y;
	int	x;

	y = -1;
	while (++y < game->m.height)
	{
		x = -1;
		while (++x < game->m.width)
		{
			if (game->m.map[y][x] == 'O')
				try_move(game, y, x);
		}
	}
	reset_enemies(game);
}
