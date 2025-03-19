/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <lucmansa@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 19:14:44 by lucmansa          #+#    #+#             */
/*   Updated: 2025/03/19 23:31:34 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	try_init(t_game *game, void **dest, char *path)
{
	*dest = mlx_xpm_file_to_image(game->mlx, path, &game->img_s, &game->img_s);
	if (*dest == NULL)
	{
		destroy(game, 0);
		write(2, "Error with mlx", 14);
		exit(1);
	}
}

void	init_img2(t_game *game)
{
	try_init(game, &game->o_sprite[0], "./img/enemie0.xpm");
	try_init(game, &game->o_sprite[1], "./img/enemie1.xpm");
	try_init(game, &game->o_sprite[2], "./img/enemie2.xpm");
	try_init(game, &game->o_sprite[3], "./img/enemie3.xpm");
	try_init(game, &game->o_sprite[4], "./img/enemie4.xpm");
	try_init(game, &game->o_sprite[5], "./img/enemie5.xpm");
	try_init(game, &game->o_sprite[6], "./img/enemie6.xpm");
	try_init(game, &game->nb[0], "./img/nb_0.xpm");
	try_init(game, &game->nb[1], "./img/nb_1.xpm");
	try_init(game, &game->nb[2], "./img/nb_2.xpm");
	try_init(game, &game->nb[3], "./img/nb_3.xpm");
	try_init(game, &game->nb[4], "./img/nb_4.xpm");
	try_init(game, &game->nb[5], "./img/nb_5.xpm");
	try_init(game, &game->nb[6], "./img/nb_6.xpm");
	try_init(game, &game->nb[7], "./img/nb_7.xpm");
	try_init(game, &game->nb[8], "./img/nb_8.xpm");
	try_init(game, &game->nb[9], "./img/nb_9.xpm");
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
	try_init(game, &game->e_sprite[0], "./img/door_c.xpm");
	try_init(game, &game->e_sprite[1], "./img/door_o.xpm");
	try_init(game, &game->c_sprite, "./img/key.xpm");
	if (BONUS_MODE)
		init_img2(game);
	return (0);
}
