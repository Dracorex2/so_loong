/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <lucmansa@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 19:11:12 by lucmansa          #+#    #+#             */
/*   Updated: 2025/03/17 18:49:58 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	mlx_i(t_game *game)
{
	game->mlx = mlx_init();
	init_img(game);
	printf("%i\n", game->img_s);
	game->win = mlx_new_window(game->mlx, game->m.width * game->img_s,
			game->m.height * game->img_s, "so long");
	mlx_key_hook(game->win, &key_press, game);
	mlx_loop_hook(game->mlx, &count_frame, game);
	mlx_hook(game->win, 17, 0, &destroy, game);
}

int	key_press(int key, t_game *game)
{
	if (key == XK_Escape)
		destroy(game);
	if (key == XK_w && game->m.map[game->p.y - 1][game->p.x] != '1')
		game->p.y -= 1;
	if (key == XK_s && game->m.map[game->p.y + 1][game->p.x] != '1')
		game->p.y += 1;
	if (key == XK_a && game->m.map[game->p.y][game->p.x - 1] != '1')
		game->p.x -= 1;
	if (key == XK_d && game->m.map[game->p.y][game->p.x + 1] != '1')
		game->p.x += 1;
	game->p.move += 1;
	ft_putstr(1, "player move : ");
	ft_putnbr(game->p.move);
	ft_putstr(1, "\nkey remain : ");
	ft_putnbr(game->m.coin_count);
	return (0);
}
