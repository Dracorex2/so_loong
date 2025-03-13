/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <lucmansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 19:07:20 by lucmansa          #+#    #+#             */
/*   Updated: 2025/03/13 19:56:47 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	mlx(t_game *game)
{
	int	size;
	
	game->mlx = mlx_init();
	game->f_sprite = mlx_xpm_file_to_image(game->mlx, "./img/sol.xpm", &size, &size);
	game->w_sprite = mlx_xpm_file_to_image(game->mlx, "./img/mur.xpm", &size, &size);
	game->win = mlx_new_window(game->mlx, game->m.width * 40, game->m.height * 40, "so long");

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
	return (0);
}

void    draw_obj(int x, int y, t_game *game)
{
	int x2 = x * 40;
	int y2 = y * 40;
	if (game->m.map[y][x] == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->w_sprite, x2, y2);
	else if (game->m.map[y][x] == '0')
		mlx_put_image_to_window(game->mlx, game->win, game->f_sprite, x2, y2);
	mlx_put_image_to_window(game->mlx, game->win, game->w_sprite, game->p.x * 40, game->p.y * 40);
}