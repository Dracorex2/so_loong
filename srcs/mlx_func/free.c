/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <lucmansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 19:04:43 by lucmansa          #+#    #+#             */
/*   Updated: 2025/03/19 19:37:29 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	free_map(char **map)
{
	int	y;

	y = -1;
	while (map[++y])
		free(map[y]);
	free(map);
}

void	free_img(t_game *game)
{
	mlx_destroy_image(game->mlx, game->w_sprite);
	mlx_destroy_image(game->mlx, game->f_sprite);
	mlx_destroy_image(game->mlx, game->c_sprite);
	mlx_destroy_image(game->mlx, game->e_sprite[0]);
	mlx_destroy_image(game->mlx, game->e_sprite[1]);
	mlx_destroy_image(game->mlx, game->p_sprite[0]);
	mlx_destroy_image(game->mlx, game->p_sprite[1]);
	mlx_destroy_image(game->mlx, game->p_sprite[2]);
	mlx_destroy_image(game->mlx, game->p_sprite[3]);
	mlx_destroy_image(game->mlx, game->p_sprite[4]);
	mlx_destroy_image(game->mlx, game->p_sprite[5]);
	mlx_destroy_image(game->mlx, game->p_sprite[6]);
	mlx_destroy_image(game->mlx, game->p_sprite_p[0]);
	mlx_destroy_image(game->mlx, game->p_sprite_p[1]);
	mlx_destroy_image(game->mlx, game->p_sprite_p[2]);
	mlx_destroy_image(game->mlx, game->p_sprite_p[3]);
	mlx_destroy_image(game->mlx, game->p_sprite_p[4]);
	mlx_destroy_image(game->mlx, game->p_sprite_p[5]);
	mlx_destroy_image(game->mlx, game->p_sprite_p[6]);
	mlx_destroy_image(game->mlx, game->o_sprite[0]);
	mlx_destroy_image(game->mlx, game->o_sprite[1]);
	mlx_destroy_image(game->mlx, game->o_sprite[2]);
	mlx_destroy_image(game->mlx, game->o_sprite[3]);
	mlx_destroy_image(game->mlx, game->o_sprite[4]);
	mlx_destroy_image(game->mlx, game->o_sprite[5]);
	mlx_destroy_image(game->mlx, game->o_sprite[6]);
	mlx_destroy_image(game->mlx, game->nb[0]);
	mlx_destroy_image(game->mlx, game->nb[1]);
	mlx_destroy_image(game->mlx, game->nb[2]);
	mlx_destroy_image(game->mlx, game->nb[3]);
	mlx_destroy_image(game->mlx, game->nb[4]);
	mlx_destroy_image(game->mlx, game->nb[5]);
	mlx_destroy_image(game->mlx, game->nb[6]);
	mlx_destroy_image(game->mlx, game->nb[7]);
	mlx_destroy_image(game->mlx, game->nb[8]);
	mlx_destroy_image(game->mlx, game->nb[9]);
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
