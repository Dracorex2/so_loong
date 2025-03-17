/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <lucmansa@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 19:04:43 by lucmansa          #+#    #+#             */
/*   Updated: 2025/03/17 16:47:56 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	free_img(t_game *game)
{
	mlx_destroy_image(game->mlx, game->w_sprite);
	mlx_destroy_image(game->mlx, game->f_sprite);
	mlx_destroy_image(game->mlx, game->p_sprite[0]);
	mlx_destroy_image(game->mlx, game->p_sprite[1]);
	mlx_destroy_image(game->mlx, game->p_sprite[2]);
	mlx_destroy_image(game->mlx, game->p_sprite[3]);
	mlx_destroy_image(game->mlx, game->p_sprite[4]);
	mlx_destroy_image(game->mlx, game->p_sprite[5]);
	mlx_destroy_image(game->mlx, game->p_sprite[6]);
}

int	destroy(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	free_img(game);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free_map(game->m.map);
	exit(0);
}
