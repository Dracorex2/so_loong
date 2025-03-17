/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <lucmansa@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 19:14:44 by lucmansa          #+#    #+#             */
/*   Updated: 2025/03/17 22:43:13 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

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
	try_init(game, &game->e_sprite[0], "./img/door_c.xpm");
	try_init(game, &game->e_sprite[1], "./img/door_o.xpm");
	try_init(game, &game->c_sprite, "./img/key.xpm");
	return (0);
}
