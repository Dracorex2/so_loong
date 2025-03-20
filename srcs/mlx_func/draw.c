/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <lucmansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 19:11:17 by lucmansa          #+#    #+#             */
/*   Updated: 2025/03/20 15:37:16 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	draw_obj(int x, int y, t_game *game)
{
	if (game->m.map[y][x] == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->w_sprite,
			x * game->img_s, y * game->img_s);
	else if (game->m.map[y][x] == '0')
		mlx_put_image_to_window(game->mlx, game->win, game->f_sprite,
			x * game->img_s, y * game->img_s);
	else if (game->m.map[y][x] == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->c_sprite,
			x * game->img_s, y * game->img_s);
	else if (game->m.map[y][x] == 'E' && game->m.coin_count > 0)
		mlx_put_image_to_window(game->mlx, game->win, game->e_sprite[0],
			x * game->img_s, y * game->img_s);
	else if (game->m.map[y][x] == 'E' && game->m.coin_count == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->e_sprite[1],
			x * game->img_s, y * game->img_s);
}

int	do_draw(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	while (++y < game->m.height)
	{
		x = -1;
		while (++x < game->m.width)
			draw_obj(x, y, game);
	}
	if (!BONUS_MODE)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->p_sprite[0],
			game->p.x * game->img_s, game->p.y * game->img_s);
		if (game->m.map[game->p.y][game->p.x] == 'E')
			mlx_put_image_to_window(game->mlx, game->win, game->p_sprite_p[0],
				game->p.x * game->img_s, game->p.y * game->img_s);
	}
	return (0);
}
