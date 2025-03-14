/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <lucmansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 19:11:17 by lucmansa          #+#    #+#             */
/*   Updated: 2025/03/14 19:12:35 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./header.h"

void    draw_player(int x, int y, t_game *game)
{
	int x2 = x * 80;
	int y2 = y * 80;
	mlx_put_image_to_window(
		game->mlx, 
		game->win, 
		game->p_sprite[game->p.frame_idx], x2, y2);
	// if (game->p.frame_p == 0 && game->p.frame_idx < 5)
	// 	game->p.frame_idx++;
	// else if (game->p.frame_p == 0)
	// 	game->p.frame_p = 1;
	// if (game->p.frame_p == 1 && game->p.frame_idx > 0)
	// 	game->p.frame_idx--;
	// else if (game->p.frame_p == 1)
	// 	game->p.frame_p = 0;
	if (game->p.frame_p == 0 && game->tick % 4 == 0)
	{
		game->p.frame_idx++;
		if (game->p.frame_idx >= 6)
			game->p.frame_p = 1;
	}
	else if (game->tick % 4 == 0)
	{
		game->p.frame_idx--;
		if (game->p.frame_idx <= 0)
			game->p.frame_p = 0;
	}
}

void    draw_obj(int x, int y, t_game *game)
{
	int x2 = x * 80;
	int y2 = y * 80;
	if (game->m.map[y][x] == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->w_sprite, x2, y2);
	else if (game->m.map[y][x] == '0')
		mlx_put_image_to_window(game->mlx, game->win, game->f_sprite, x2, y2);
}

int    do_draw(t_game *game)
{
	int    x;
	int    y;

	y = 0;
	while (y < game->m.height)
	{
		x = 0;
		while (x < game->m.width)
		{
			draw_obj(x, y, game);
			x++;
		}
		y++;
	}
	draw_player(game->p.x, game->p.y, game);
	return (0);
}

int	count_frame(t_game *game)
{
	struct timeval    t0;
	struct timeval    t1;
	int					time_taken;

	game->tick++;
	gettimeofday(&t0, NULL);
	mlx_clear_window(game->mlx, game->win);
	do_draw(game);
	gettimeofday(&t1, NULL);
	time_taken = (t1.tv_sec - t0.tv_sec) * 1000000 + (t1.tv_usec - t0.tv_usec);
	if (time_taken < 1000000 / 56)
		usleep(1000000 / 56 - time_taken);
	return (0);
}
