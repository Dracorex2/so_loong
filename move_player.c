/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <lucmansa@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 22:49:04 by lucmansa          #+#    #+#             */
/*   Updated: 2025/03/17 23:00:40 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	move_player(t_game *game, int x, int y)
{
	if (game->m.map[y][x] != '1')
	{
		game->p.x = x;
		game->p.y = y;
		if (game->m.map[y][x] == 'C')
		{
			game->m.map[y][x] = '0';
			game->m.coin_count--;
		}
		else if (game->m.map[y][x] == 'E' && game->m.coin_count == 0)
			destroy(game);
		game->p.move++;
	}
}
