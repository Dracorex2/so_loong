/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <lucmansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 19:11:12 by lucmansa          #+#    #+#             */
/*   Updated: 2025/03/14 19:14:39 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./header.h"

void	mlx(t_game *game)
{
	char	i;
	char str[18];
	
	game->mlx = mlx_init();
	game->f_sprite = mlx_xpm_file_to_image(game->mlx, "./img/sol.xpm", &size, &size);
	game->w_sprite = mlx_xpm_file_to_image(game->mlx, "./img/mur.xpm", &size, &size);
	i = '0' - 1;
	ft_memcpy(str, "./img/sprite1.xpm", 18);
	while (++i < '7')
	{
		str[12] = i;
		game->p_sprite[i - '0'] = mlx_xpm_file_to_image(game->mlx, str, &size, &size);
	}
	game->p.frame_idx = 0;
	game->p.frame_p = 0;
	game->win = mlx_new_window(game->mlx, game->m.width * 80, game->m.height * 80, "so long");
	mlx_key_hook(game->win, &key_press, game);
	mlx_loop_hook(game->mlx, &count_frame, game);
	mlx_hook(game->win, 17, 0, &destroy, game);
}

int	key_press(int key, t_game *game)
{
	if (key == XK_Escape)
		destroy(game);
	if (key == XK_w && game->m.map[game->p.y - 1][game->p.x] != '1')
		game->p.y -= 1;
	if (key == XK_s && game->m.map[game->p.y + 1][game->p.x] != '1')
		game->p.y += 1;
	if (key == XK_a && game->m.map[game->p.y][game->p.x - 1] != '1')
		game->p.x -= 1;
	if (key == XK_d && game->m.map[game->p.y][game->p.x + 1] != '1')
		game->p.x += 1;
	game->p.move += 1;
	
	return (0);
}
