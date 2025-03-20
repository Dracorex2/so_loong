/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_windows.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <lucmansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 18:01:15 by lucmansa          #+#    #+#             */
/*   Updated: 2025/03/20 15:47:23 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_nb_win(t_game *game)
{
	int	tmp;
	int	ofset;

	tmp = game->p.move;
	ofset = game->m.width - 1;
	mlx_put_image_to_window(game->mlx, game->win, game->nb[tmp % 10],
		ofset * game->img_s, 0 * game->img_s);
	while (tmp >= 10)
	{
		ofset--;
		tmp /= 10;
		mlx_put_image_to_window(game->mlx, game->win, game->nb[tmp % 10],
			ofset * game->img_s, 0 * game->img_s);
	}
}
