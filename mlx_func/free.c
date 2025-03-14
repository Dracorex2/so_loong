/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <lucmansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 19:04:43 by lucmansa          #+#    #+#             */
/*   Updated: 2025/03/14 19:09:39 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./header.h"

void	destroy_player

int	destroy(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_image(game->mlx, game->w_sprite);
	mlx_destroy_image(game->mlx, game->f_sprite);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free_map(game->m.map);
	exit(0);
}
