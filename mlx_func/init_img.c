/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <lucmansa@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 19:14:44 by lucmansa          #+#    #+#             */
/*   Updated: 2025/03/17 16:21:25 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	try_init(t_game *game, void **dest, char *path)
{
	*dest = mlx_xpm_file_to_image(game->mlx, path, &game->img_s, &game->img_s);
	if (dest == NULL)
	{
		destroy(game);
		write(2, "Error with mlx", 14);
		exit(1);
	}
}

int	init_img(t_game *game)
{
	game->f_sprite = mlx_xpm_file_to_image(game->mlx, "./img/floor.xpm", &game->img_s, &game->img_s);
	game->w_sprite = mlx_xpm_file_to_image(game->mlx, "./img/wall.xpm", &game->img_s, &game->img_s);
	game->p_sprite[0] = mlx_xpm_file_to_image(game->mlx, "./img/sprite0.xpm", &game->img_s, &game->img_s);
	game->p_sprite[1] = mlx_xpm_file_to_image(game->mlx, "./img/sprite1.xpm", &game->img_s, &game->img_s);
	game->p_sprite[2] = mlx_xpm_file_to_image(game->mlx, "./img/sprite2.xpm", &game->img_s, &game->img_s);
	game->p_sprite[3] = mlx_xpm_file_to_image(game->mlx, "./img/sprite3.xpm", &game->img_s, &game->img_s);
	game->p_sprite[4] = mlx_xpm_file_to_image(game->mlx, "./img/sprite4.xpm", &game->img_s, &game->img_s);
	game->p_sprite[5] = mlx_xpm_file_to_image(game->mlx, "./img/sprite5.xpm", &game->img_s, &game->img_s);
	game->p_sprite[6] = mlx_xpm_file_to_image(game->mlx, "./img/sprite6.xpm", &game->img_s, &game->img_s);
	//try_init(game->mlx, game->f_sprite, "./img/sol.xpm");
	//try_init(game->mlx, game->w_sprite, "./img/mur.xpm");
	//try_init(game->mlx, game->p_sprite[0], "./img/sprite0.xpm");
	//try_init(game->mlx, game->p_sprite[1], "./img/sprite1.xpm");
	//try_init(game->mlx, game->p_sprite[2], "./img/sprite2.xpm");
	//try_init(game->mlx, game->p_sprite[3], "./img/sprite3.xpm");
	//try_init(game->mlx, game->p_sprite[4], "./img/sprite4.xpm");
	//try_init(game->mlx, game->p_sprite[5], "./img/sprite5.xpm");
	//try_init(game->mlx, game->p_sprite[6], "./img/sprite6.xpm");
	return (0);
}
