/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <lucmansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 21:08:20 by lucmansa          #+#    #+#             */
/*   Updated: 2025/03/20 15:48:19 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>

int	randint(int i)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	srand(t.tv_sec * t.tv_usec);
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
			if (move_up(game, y, x))
				break ;
		if (r == 2)
			if (move_right(game, y, x))
				break ;
		if (r == 3)
			if (move_down(game, y, x))
				break ;
		if (r == 4)
			if (move_left(game, y, x))
				break ;
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
