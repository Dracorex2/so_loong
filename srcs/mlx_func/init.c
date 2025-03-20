/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <lucmansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 19:11:12 by lucmansa          #+#    #+#             */
/*   Updated: 2025/03/20 15:32:48 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	mlx_i(t_game *game)
{
	game->mlx = mlx_init();
	init_img(game);
	game->win = mlx_new_window(game->mlx, game->m.width * game->img_s,
			game->m.height * game->img_s, "so long");
	mlx_hook(game->win, 2, 1, &key_press, game);
	mlx_hook(game->win, 17, 0, &destroy, game);
	if (BONUS_MODE)
	{
		mlx_loop_hook(game->mlx, &count_frame, game);
		put_nb_win(game);
	}
	do_draw(game);
}

int	key_press(int key, t_game *game)
{
	if (key == XK_Escape)
		destroy(game, 0);
	if (key == XK_w || key == XK_Up)
		move_player(game, game->p.x, game->p.y - 1);
	if (key == XK_s || key == XK_Down)
		move_player(game, game->p.x, game->p.y + 1);
	if (key == XK_a || key == XK_Left)
		move_player(game, game->p.x - 1, game->p.y);
	if (key == XK_d || key == XK_Right)
		move_player(game, game->p.x + 1, game->p.y);
	do_draw(game);
	if (BONUS_MODE)
		put_nb_win(game);
	return (0);
}
