/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <lucmansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 19:07:20 by lucmansa          #+#    #+#             */
/*   Updated: 2025/03/14 19:11:44 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	mlx(t_game *game)
{
	int	size;
	char	i;
	char str[18];
	
	game->mlx = mlx_init();
	game->f_sprite = mlx_xpm_file_to_image(game->mlx, "./img/sol.xpm", &size, &size);
	game->w_sprite = mlx_xpm_file_to_image(game->mlx, "./img/mur.xpm", &size, &size);
	i = '0' - 1;
	ft_memcpy(str, "./img/sprite1.xpm", 18);
	while (++i < '7')
	{
		str[12] = i;
		game->p_sprite[i - '0'] = mlx_xpm_file_to_image(game->mlx, str, &size, &size);
	}
	game->p.frame_idx = 0;
	game->p.frame_p = 0;
	game->win = mlx_new_window(game->mlx, game->m.width * 80, game->m.height * 80, "so long");
	mlx_key_hook(game->win, &key_press, game);
	mlx_loop_hook(game->mlx, &count_frame, game);
	mlx_hook(game->win, 17, 0, &destroy, game);
}

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
