/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <lucmansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 19:14:44 by lucmansa          #+#    #+#             */
/*   Updated: 2025/03/14 19:32:25 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./header.h"

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
int init_img(t_game *game)
{
	char	i;
	char str[18];

	try_init(game->mlx, game->f_sprite, "./img/sol.xpm");
	try_init(game->mlx, game->w_sprite, "./img/mur.xpm");
	i = '0' - 1;
	ft_memcpy(str, "./img/sprite1.xpm", 18);
	while (++i < '7')
	{
		str[12] = i;
		game->p_sprite[i - '0'] = mlx_xpm_file_to_image(game->mlx, str,
			&game->img_size, &game->img_size);
	}
}
