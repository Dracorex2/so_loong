/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <lucmansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 19:11:12 by lucmansa          #+#    #+#             */
/*   Updated: 2025/03/18 07:46:28 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	mlx_i(t_game *game)
{
	game->mlx = mlx_init();
	init_img(game);
	game->win = mlx_new_window(game->mlx, game->m.width * game->img_s,
			game->m.height * game->img_s, "so long");
	printf("%p\n", game->mlx);
	mlx_key_hook(game->win, &key_press, game);
	mlx_loop_hook(game->mlx, &count_frame, game);
	mlx_hook(game->win, 17, 0, &destroy, game);
	do_draw(game);
}

int	key_press(int key, t_game *game)
{
	if (key == XK_Escape)
		destroy(game);
	if (key == XK_w)
		move_player(game, game->p.x, game->p.y - 1);
	if (key == XK_s)
		move_player(game, game->p.x, game->p.y + 1);
	if (key == XK_a)
		move_player(game, game->p.x - 1, game->p.y);
	if (key == XK_d)
		move_player(game, game->p.x + 1, game->p.y);
	do_draw(game);

	return (0);
}
