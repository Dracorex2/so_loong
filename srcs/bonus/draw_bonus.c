/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <lucmansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 15:23:38 by lucmansa          #+#    #+#             */
/*   Updated: 2025/03/20 16:14:20 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_enemies(t_game *game)
{
	int	y;
	int	x;

	if (BONUS_MODE && game->p.frame_idx == 6)
		move_enemies(game);
	y = -1;
	while (++y < game->m.height)
	{
		x = -1;
		while (++x < game->m.width)
		{
			if (game->m.map[y][x] == 'O')
			{
				mlx_put_image_to_window(game->mlx, game->win,
					game->o_sprite[game->p.frame_idx],
					x * game->img_s, y * game->img_s);
				draw_obj(x, y + 1, game);
				draw_obj(x - 1, y, game);
				draw_obj(x + 1, y, game);
				draw_obj(x, y - 1, game);
			}
		}
	}
}

void	draw_player(int x, int y, t_game *game)
{
	draw_enemies(game);
	if (game->m.map[y][x] == 'E')
		mlx_put_image_to_window(game->mlx, game->win,
			game->p_sprite_p[game->p.frame_idx],
			x * game->img_s, y * game->img_s);
	else
		mlx_put_image_to_window(game->mlx, game->win,
			game->p_sprite[game->p.frame_idx],
			x * game->img_s, y * game->img_s);
	if (game->p.frame_p == 0)
	{
		game->p.frame_idx++;
		if (game->p.frame_idx >= 6)
			game->p.frame_p = 1;
	}
	else
	{
		game->p.frame_idx--;
		if (game->p.frame_idx <= 0)
			game->p.frame_p = 0;
	}
}

int	count_frame(t_game *game)
{
	struct timeval	t0;
	struct timeval	t1;
	int				time_taken;

	game->tick++;
	gettimeofday(&t0, NULL);
	if (game->tick % 4 == 0)
	{
		draw_player(game->p.x, game->p.y, game);
		if (game->m.map[game->p.y][game->p.x] == 'O')
			destroy(game, 2);
	}
	gettimeofday(&t1, NULL);
	time_taken = (t1.tv_sec - t0.tv_sec) * 1000000 + (t1.tv_usec - t0.tv_usec);
	if (time_taken < 1000000 / 56)
		usleep(1000000 / 56 - time_taken);
	return (0);
}
