/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <lucmansa@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 19:14:44 by lucmansa          #+#    #+#             */
/*   Updated: 2025/03/18 22:38:40 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	try_init(t_game *game, void **dest, char *path)
{
	*dest = mlx_xpm_file_to_image(game->mlx, path, &game->img_s, &game->img_s);
	if (*dest == NULL)
	{
		destroy(game);
		write(2, "Error with mlx", 14);
		exit(1);
	}
}

int	init_img(t_game *game)
{
	try_init(game, &game->f_sprite, "./img/floor.xpm");
	try_init(game, &game->w_sprite, "./img/wall.xpm");
	try_init(game, &game->p_sprite[0], "./img/sprite0.xpm");
	try_init(game, &game->p_sprite[1], "./img/sprite1.xpm");
	try_init(game, &game->p_sprite[2], "./img/sprite2.xpm");
	try_init(game, &game->p_sprite[3], "./img/sprite3.xpm");
	try_init(game, &game->p_sprite[4], "./img/sprite4.xpm");
	try_init(game, &game->p_sprite[5], "./img/sprite5.xpm");
	try_init(game, &game->p_sprite[6], "./img/sprite6.xpm");
	try_init(game, &game->p_sprite_p[0], "./img/sprite_p0.xpm");
	try_init(game, &game->p_sprite_p[1], "./img/sprite_p1.xpm");
	try_init(game, &game->p_sprite_p[2], "./img/sprite_p2.xpm");
	try_init(game, &game->p_sprite_p[3], "./img/sprite_p3.xpm");
	try_init(game, &game->p_sprite_p[4], "./img/sprite_p4.xpm");
	try_init(game, &game->p_sprite_p[5], "./img/sprite_p5.xpm");
	try_init(game, &game->p_sprite_p[6], "./img/sprite_p6.xpm");
	try_init(game, &game->o_sprite[0], "./img/enemie0.xpm");
	try_init(game, &game->o_sprite[1], "./img/enemie1.xpm");
	try_init(game, &game->o_sprite[2], "./img/enemie2.xpm");
	try_init(game, &game->o_sprite[3], "./img/enemie3.xpm");
	try_init(game, &game->o_sprite[4], "./img/enemie4.xpm");
	try_init(game, &game->o_sprite[5], "./img/enemie5.xpm");
	try_init(game, &game->o_sprite[6], "./img/enemie6.xpm");
	try_init(game, &game->e_sprite[0], "./img/door_c.xpm");
	try_init(game, &game->e_sprite[1], "./img/door_o.xpm");
	try_init(game, &game->c_sprite, "./img/key.xpm");
	return (0);
}
